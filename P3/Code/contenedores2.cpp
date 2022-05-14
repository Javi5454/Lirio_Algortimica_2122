/**
 * @file contenedores2.cpp
 * @author José Alberto Hoces Castro
 * @brief Program that calculates the max amount of tons of different containers we can have in another one of capacity "n" tons
 * @version 0.1
 * @date 2022-05-14
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

int contenedoresGreedy2(int *T, int n){
    
    	int used = 0;
	vector<int> myvector(T,T+n);
	sort(myvector.begin(),myvector.end(), greater<int>);
	
	for(int i = 0; (i < n) && (used <= n); i++){
		used += T[i];
	}
	
	return used;
}

int main(int argc, char* argv[]){

    if(argc != 2){
        cout << "Syntax error: ./contenedores2 <Num of containers>" << endl;

        return -1;
    }

    srand((unsigned) time(NULL));

    int REPS = 15;
    int n = atoi(argv[1]);
    double t = 0;
    for(int i=0; i < REPS; i++){
    	    
    	    int *T = new int[n];
	    
	    for(int j=0; j < n; j++){
	    	T[j] = rand()%n;
	    }

	    high_resolution_clock::time_point tantes, tdespues;
	    duration<double> transcurrido;
	    
	    tantes = high_resolution_clock::now();

	    int result = contenedoresGreedy2(T,n);
	    
	    tdespues = high_resolution_clock::now();

	    transcurrido = duration_cast<duration<double>>(tdespues - tantes);

	    t += transcurrido.count();
	    
	    delete [] T;
    }
    
    t = ((double)t/REPS);
    
    cout << n << " " << t << endl;

    return 0;
    
}
