/**
 * @file secuencial.cpp
 * @author Manuel Moya
 * @brief Program that searchs in an ordered vector an element that v[i] = i
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
}

void mergeKArrays(int nElementos, int **arr, int nVectores, int * &v_resultante)
{

    int k = 0;
    bool encontrado;
    for(int i = 0; i < nElementos; i++){
      v_resultante[i] = arr[0][i];
    }

    //iteramos por cada vector y por cada elemento del nuevo vector a insertar
    for(int i = 1; i < nVectores; i++){ 
      for(int j = 0; j < nElementos; j++){ 
        encontrado = false;
        k = 0;
        while(k < nElementos * i + j && !encontrado){
          if(v_resultante[k] > arr[i][j])
            encontrado = true;
          else
            k++;
        }
        //Realizamos traslacion a la derecha para insertar elemento si es menor
        if(encontrado){
          for(int l = nElementos*i+j-1; l >= k; l--){ 
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
    if(argc != 4){
        cout << "Syntax error: ./secuencial <Num of elements> <num of vectors> <Input File>" << endl;

        return -1;
    }


    int n = stoi(argv[1]);
    int k = stoi(argv[2]);


    string route = argv[3];
    string line;

    int **v;
    v = new int *[k];
    for (int i=0; i < k; i++){
        v[i] = new int[n];
    }

    ifstream myFile(route);
    int numero;

    if(myFile.is_open()){
    
        int i=0;
        int j= 0;
        while(myFile >> numero){
            if (i == n){
                i = 0;
                j++;
            }
            v[j][i] = numero;
            i++;
        }

        myFile.close();
    }

    int *v_resultante;
    reservarArray(k*n, v_resultante);

    high_resolution_clock::time_point tantes, tdespues;
    duration<double> transcurrido;

    tantes = high_resolution_clock::now();

    mergeKArrays(n, v, k, v_resultante);


    tdespues = high_resolution_clock::now();

    transcurrido = duration_cast<duration<double>>(tdespues - tantes);

    double time_total = transcurrido.count();

    cout << "Time used: " << time_total << endl;
    cout << "Numero de elementos: " << n << endl;
    cout << "Numero de vectores: " << k << endl;

    for(int i=0; i < k*n; i++){
        cout << " " <<  v_resultante[i];
    }
    cout << endl;

    if(v!= nullptr){
        for (int i=0; i < k; i++){
            delete[] v[i];
        }
        delete [] v;
    }
    if (v_resultante != nullptr){
        delete[] v_resultante;
    }
}