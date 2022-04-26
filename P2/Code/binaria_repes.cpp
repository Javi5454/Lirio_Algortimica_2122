/**
 * @file binaria.cpp
 * @author José Alberto Hoces Castro
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
#include <algorithm>

using namespace std;
using namespace std::chrono;

/**
 * @brief Method of searching
 * @param v: Vector in where to search
 * @param n: number of elements in the vector
 * @return the index of the element or -1 if it does not exists
 */

int buscarBinaria(int v[], int inicio,int fin){
    int medio = (inicio + fin)/2;
    int resultado = -1;

    if(v[medio] == medio){
        return medio;
    }
    else{
        if(inicio <= fin){
            resultado = buscarBinaria(v, inicio, medio - 1);

            if(resultado == -1){
                resultado = buscarBinaria(v, medio + 1, fin);
            }
        }
    }

    return resultado;

}

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Syntax error: ./binaria_repes <Num of elements>" << endl;

        return -1;
    }

    srand((unsigned) time(NULL));

    int REPS = 1;
    int n = atoi(argv[1]);
    int m=2*n-1;
    double t = 0;
    for(int i=0; i < REPS; i++){
	    
	    vector<int> myvector(n);
	    
	    for(int j = 0; j < n/2; j++){
	    	myvector[j] = rand()%n - (n-1);
	    }
	    
	    for(int j=n/2; j < n; j++){
	    	myvector[j] = rand()%n;
	    }

	    sort(myvector.begin(),myvector.end());
        vector<int>::iterator it;

        int *T = new int[n];
        
        for(int i = 0; i < n; i++){
            T[i] = myvector.at(i);
        }

        if(n <= 10){
            for(int i = 0; i < n; i++){
                cout << "v[" << i << "]: " << T[i] << " ";
            }

            cout << endl;
        }

	    high_resolution_clock::time_point tantes, tdespues;
	    duration<double> transcurrido;

	    tantes = high_resolution_clock::now();

	    int result = buscarBinaria(T, 0, n-1);

	    tdespues = high_resolution_clock::now();

	    transcurrido = duration_cast<duration<double>>(tdespues - tantes);

	    t += transcurrido.count();

        //cout << "Result: " << result << endl;
    }
    
    t = ((double)t/REPS);
    
    cout << n << " " << t << endl;

    return 0;
    
}
