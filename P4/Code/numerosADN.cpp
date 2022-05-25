#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <algorithm>
#include <list>
#include <cmath>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[]){

	if(argc != 2){
		cout << "Error en parametros: ./numerosADN input file" << endl;
		return -1;
	}
	
	ifstream file;
	file.open(argv[1]);
	string entrada1;
	file >> entrada1;
	
	string entrada2;
	file >> entrada2;
	file.close();
	
	int n = entrada1.size();
	int m = entrada2.size();
	
	int ** matriz_calculos = nullptr;
	matriz_calculos = new int * [n];
	for(int i=0; i < n; i++){
        	matriz_calculos[i] = new int [m];
        }
        
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		matriz_calculos[i][j] = 0;
        	}
        }
        
        // Inicializamos la primera fila
        for(int j = 0; j < m; j++){
        	if(entrada1[0] == entrada2[j]){
        		matriz_calculos[0][j] = 1;
        	}
        }
        
        // Inicializamos la primera columna
        for(int i = 1; i < n; i++){
        	if(entrada1[i] == entrada2[0]){
        		matriz_calculos[i][0] = 1;
        	}
        }
        
        
        // Cálculo de la matriz de cálculos
        
        for(int i = 1; i < n; i++){
        	for(int j = 1; j < m; j++){
        		if(entrada1[i] == entrada2[j]){
        			matriz_calculos[i][j] = matriz_calculos[i-1][j-1]+1;
        		}
        		else{
        			if(matriz_calculos[i][j-1] >= matriz_calculos[i-1][j]){
        				matriz_calculos[i][j] = matriz_calculos[i][j-1];
        			}
        			else{
        				matriz_calculos[i][j] = matriz_calculos[i-1][j];
        			}
        		}
        	}
        }
	
	// Buscamos el máximo en la última fila de la matriz de cálculos y seguimos el camino hacia atrás
	
	int max = 0;
	int posj = 0;
	
	for(int j = 0; j < m; j++){
		if(matriz_calculos[n-1][j] >= max){
			max = matriz_calculos[n-1][j];
			posj = j;
		}
	}
	
	list<char> resultado;
	int i = n-1;
	
	while(i >= 0){
		if(entrada1[i] == entrada2[posj]){
			resultado.push_front(entrada2[posj]);
			posj--;
			i--;
		}
		else{
			if(matriz_calculos[i][posj-1] == matriz_calculos[i][posj]){
				posj--;
			}
			else{
				i--;
			}
		}
	}
	
	// Impresión de resultados
	
	cout << "Matriz de cálculos: \n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << matriz_calculos[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "Secuencia más larga: \n";
	for(list<char>::iterator it=resultado.begin(); it != resultado.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	
	cout << "Porcentaje de similitud: " << (double)max/n * 100;
	cout << endl;
    

    for(int i=0; i<n; i++){
      delete [] matriz_calculos[i];
    }
  
    delete [] matriz_calculos;
    matriz_calculos = nullptr;

    return 0;
}
