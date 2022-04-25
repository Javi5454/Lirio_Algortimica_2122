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

int buscarBinaria(vector<int> v, int inicio,int fin){

    if(inicio == fin){
        if(v[inicio] == inicio){
        	return inicio;
        }
        else{
        	return -1;
        }
    }

    if(v[inicio] != inicio && v[fin-1] != fin-1){
        
        int medio = (inicio+fin)/2;
        int resultado = buscarBinaria(v,inicio+1,medio);
        if(resultado != -1){
        	return resultado;
        }
        else{
               resultado = buscarBinaria(v,medio+1,fin-1);
               return resultado;
        }
    }
    else if(v[inicio] == inicio){
        
        return inicio;
    }
    else if(v[fin-1] == fin-1){
        
        return fin-1;
    }

    return -1;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Syntax error: ./secuencial <Num of elements>" << endl;

        return -1;
    }

    int REPS = 15;
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

	    high_resolution_clock::time_point tantes, tdespues;
	    duration<double> transcurrido;

	    tantes = high_resolution_clock::now();

	    int result = buscarBinaria(myvector, 0, n);

	    tdespues = high_resolution_clock::now();

	    transcurrido = duration_cast<duration<double>>(tdespues - tantes);

	    t += transcurrido.count();
    }
    
    t = ((double)t/REPS);
    
    cout << t << endl;

    return 0;
    
}
