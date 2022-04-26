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
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int REPS = 15;

/**
 * @brief Method of searching
 * @param v: Vector in where to search
 * @param n: number of elements in the vector
 * @return the index of the element or -1 if it does not exists
 */

int binarySearch(int v[], int low, int high){
    if(high >= low){
        int mid = low + (high - low) / 2;

        if(v[mid] == mid){
            return mid;
        }

        if(v[mid] > mid){
            return binarySearch(v, low, mid - 1);
        }

        //else
        return binarySearch(v, mid + 1, high);
    }

    return -1;
}

double uniforme() //Genera un n�mero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C. 
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Syntax error: ./binaria <Num of elements>" << endl;

        return -1;
    }

    int n = atoi(argv[1]);

    int m=2*n-1;
    double t = 0;

    for(int i=0; i < REPS; i++){
	    int *T = new int[n];
	    assert(T);
	    int * aux = new int[m];
	    assert(aux);

		srand(time(0));
		//genero todos los enteros entre -(n-1) y n-1
		for (int j=0; j<m; j++) aux[j]=j-(n-1);

		//algoritmo de random shuffling the Knuth (permutaci�n aleatoria) 
		for (int j=m-1; j>0; j--) {
		   double u=uniforme();
		   int k=(int)(j*u);
		   int tmp=aux[j];
		   aux[j]=aux[k];
		   aux[k]=tmp;
		}
		//me quedo con los n primeros del vector
		for (int j=0; j<n; j++) T[j]=aux[j];
		//for (int j=0; j<n; j++) cout << T[j] << " ";

		//Y ahora ordeno el vector T
		vector<int> myvector (T, T+n);
		vector<int>::iterator it;

		sort(myvector.begin(),myvector.end());

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

	    int result = binarySearch(T, 0, n-1);

	    tdespues = high_resolution_clock::now();

	    transcurrido = duration_cast<duration<double>>(tdespues - tantes);

	    t += transcurrido.count();


            delete [] T;

            //cout << "Result: " << result << endl;
    }
    
    t = ((double)t/REPS);

    cout << n << " " << t << endl;

    return 0;
    
}
