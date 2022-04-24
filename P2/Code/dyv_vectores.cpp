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

/**
 * @brief Metodo para mezclar dos vectores ya ordenados
 * @param arr1: Primer array ordenado
 * @param arr2: Segundo array ordenado
 * @param n: Numero de elementos de cada array
 * @return the index of the element or -1 if it does not exists
 */

void merge2Arrays(int *arr1, int *arr2, int n1, int n2, int *arr3)
{
    int i = 0, j = 0, k= 0;
 
    // Traverse both array
    while (i<n1 && j <n2)
    {
        // Comprueba si el elemento actual del primer array 
        // es menor que el elemento actual del segundo array
        // Si es menor, almacena el elemento del primer array
        // e incrementa el indice del primer array
        // En otro caso hace lo correspondiente pero en el segundo array
        if (arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
            k++;
        }

    }
 
    // Store remaining elements of first array
    while (i < n1){
        arr3[k] = arr1[i];
        i++;
        k++;
    }
 
    // Store remaining elements of second array
    while (j < n2){
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeKArrays(int n, int **arr, int n1,int n2, int *array_resultante)
{
    //si solo hay un array
    if(n1==n2)
    {
        for(int i=0; i < n; i++)
        array_resultante[i]=arr[n1][i];
        return;
    }
    
    
    //si solo hay dos arrays los mezcla
    if(n2-n1==1)
    {
        merge2Arrays(arr[n1],arr[n2],n,n,array_resultante);
        return;
    }
    

    //output arrays
    int array1[n*(((n1+n2)/2)-n1+1)];
    int array2[n*(n2-((n1+n2)/2))];
     
    //divide el array en dos mitades
    mergeKArrays(n, arr,n1,(n1+n2)/2,array1);
    mergeKArrays(n, arr,(n1+n2)/2+1,n2,array2);
     
    //mezcla el array resultante
    merge2Arrays(array1,array2,n*(((n1+n2)/2)-n1+1),n*(n2-((n1+n2)/2)),array_resultante);

}


int main(int argc, char* argv[]){
    if(argc != 4){
        cout << "Syntax error: ./secuencial <Num of elements> <num of vectors> <Input File>" << endl;

        return -1;
    }


    int n = stoi(argv[1]);
    int k = stoi(argv[2]);

    int *T = new int[n];
    assert(T);

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

    int v_resultante[k*n];

    high_resolution_clock::time_point tantes, tdespues;
    duration<double> transcurrido;

    tantes = high_resolution_clock::now();

    mergeKArrays(n, v, 0, k-1, v_resultante);


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
}