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
	matriz_calculos = new int * [n+1];
	for(int i=0; i < n+1; i++){
        	matriz_calculos[i] = new int [m+1];
        }
        
        for(int i = 0; i < n+1; i++){
        	for(int j = 0; j < m+1; j++){
        		matriz_calculos[i][j] = 0;
        	}
        }
        
        // Cálculo de la matriz de cálculos
        
        for(int i = 1; i < n+1; i++){
        	for(int j = 1; j < m+1; j++){
        		if(entrada1[i-1] == entrada2[j-1]){
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
	
	// Buscamos el máximo en la última fila de la matriz de cálculos
	
	int max = 0;
	int posj = 0;
	
	for(int j = 1; j < m+1; j++){
		if(matriz_calculos[n][j] >= max){
			max = matriz_calculos[n][j];
			posj = j;
		}
	}
	
	// Realizamos el camino hacia atrás y almacenamos la subsecuencia en una lista
	
	list<char> resultado;
	int i = n;
	
	while(i >= 1){
		
		// Si hay coincidencia, almacenamos la letra al principio de la cadena
		// Nos vamos a la anterior fila en diagonal
		
		if(entrada1[i-1] == entrada2[posj-1]){
			resultado.push_front(entrada2[posj-1]);
			posj--;
			i--;
		}
		else{
		
			// Si no hay coincidencia, vemos cuál es el máximo de entre la
			// casilla de la izquierda y la de arriba a la actual, y nos 
			// movemos hacia donde esté el máximo
			
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
	for(int i = 0; i < n+1; i++){
		for(int j = 0; j < m+1; j++){
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
    

    for(int i=0; i<n+1; i++){
      delete [] matriz_calculos[i];
    }
  
    delete [] matriz_calculos;
    matriz_calculos = nullptr;

    return 0;
}
