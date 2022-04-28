/**
 * @file secuencial.cpp
 * @author Manuel Moya
 * @brief Program that merge k sorted arrays in 1
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <cmath>
#include <chrono>
#include <fstream>
#include <vector>

using namespace std;
using namespace std::chrono;

const int REPS = 15;

double uniforme() //Genera un n�mero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C. 
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

void reservarArray(int tamano, int * &array){
    if(tamano < 1){
        cerr << "tamano erroneo" << endl;
        exit(EXIT_FAILURE);
    }

    //COMPROBAMOS QUE v ESTA A nullptr
    if(array != nullptr){
        delete[] array;
    }

    //INICIALIZAMOS VECTOR
    array = new int [tamano];

    //COMPROBAMOS QUE NO HA HABIDO ERRORES
    if(array == nullptr){
      cerr << "error al reservar tamano" << endl;
      exit(EXIT_FAILURE);
    }

    for (int i=0; i < tamano; i++){
        array[i] = 0;
    }
}

void mergeKArrays(int nElementos, int **arr, int nVectores, int * &v_resultante)
{

    int k = 0;
    bool encontrado;
    for(int i = 0; i < nElementos; i++){    //O(n)
      v_resultante[i] = arr[0][i];
    }
    

    //iteramos por cada vector y por cada elemento del nuevo vector a insertar
    for(int i = 1; i < nVectores; i++){         //O(k)
      for(int j = 0; j < nElementos; j++){      //O(n)
        encontrado = false;
        k = 0;
        while(k < nElementos * i + j && !encontrado){   //O(kn + n)
          if(v_resultante[k] > arr[i][j])
            encontrado = true;
          else
            k++;
        }
        //Realizamos traslacion a la derecha para insertar elemento si es menor
        if(encontrado){
          for(int l = nElementos*i+j-1; l >= k; l--){   //O(kn)
            v_resultante[l+1] = v_resultante[l];
          }
          v_resultante[k] = arr[i][j];
        }
        else{
          v_resultante[nElementos * i + j ] = arr[i][j];
        }
      }
    }
     
}

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Syntax error: ./secuencial <Num of elements> <num of vectors>" << endl;

        return -1;
    }


    int n = stoi(argv[1]);
    int k = stoi(argv[2]);
    double t = 0;

for(int i=0; i < REPS; i++){
        int **T;
	T =  new int * [k];
	  assert(T);

	 for (int i = 0; i < k; i++)
	      T[i]= new int [n];

	int N=k*n;
	int * aux = new int[N];
	  assert(aux);

	srand(time(0));
	//genero todos los enteros entre 0 y k*n-1
	for (int j=0; j<N; j++) aux[j]=j;

	//para cada uno de los k vectores se lanza el algoritmo S (sampling) de Knuth
	for (int i=0; i<k; i++) {
	   int t=0;
	   int m=0;
	   while (m<n) {
	    double u=uniforme();
	    if ((N-t)*u >= (n-m)) t++;
	    else {
		T[i][m]=aux[t];
		t++;
		m++;
	    }
	  }
	}

	delete [] aux;

    int *v_resultante = nullptr;
    reservarArray(k*n, v_resultante);

    high_resolution_clock::time_point tantes, tdespues;
    duration<double> transcurrido;

    tantes = high_resolution_clock::now();

    mergeKArrays(n, T, k, v_resultante);


    tdespues = high_resolution_clock::now();

    transcurrido = duration_cast<duration<double>>(tdespues - tantes);

    t += transcurrido.count();

    /*
    for(int i=0; i < k*n; i++){
        cout << " " <<  v_resultante[i];
    }
    cout << endl;
    */
    
    if (v_resultante != nullptr){
        delete[] v_resultante;
    }
    
    if(T!= 0){
  	for (int i=0; i < k; i++){
      		delete[] T[i];
  	}
    delete [] T;
    }
    }
    
    t = ((double)t/REPS);

    cout << k << " " << t << endl;
    
    return 0;
}
