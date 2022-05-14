/**
 * @file contenedores1.cpp
 * @author José Alberto Hoces Castro
 * @brief Program that calculates the max amount of containers we can have in another one of capacity "n" tons
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

int contenedoresGreedy1(int *T, int n){
    
    	int used = 0;
    	int result = 0;
	vector<int> myvector(T,T+n);
	sort(myvector.begin(),myvector.end());
	
	for(int i = 0; (i < n) && (used <= n); i++){
		used += T[i];
		result++;
	}
	
	return result;
}

int main(int argc, char* argv[]){

    if(argc != 2){
        cout << "Syntax error: ./contenedores1 <Num of containers>" << endl;

        return -1;
    }

    srand((unsigned) time(NULL));

    int REPS = 15;
    int n = atoi(argv[1]);
    double t = 0;
    for(int i=0; i < REPS; i++){
    	    
    	    int *T = new int[n];
    	    
	    vector<int> myvector(n);
	    
	    for(int j=0; j < n; j++){
	    	T[j] = rand()%n;
	    }

	    high_resolution_clock::time_point tantes, tdespues;
	    duration<double> transcurrido;
	    
	    tantes = high_resolution_clock::now();

	    int result = contenedoresGreedy1(T,n);
	    
	    tdespues = high_resolution_clock::now();

	    transcurrido = duration_cast<duration<double>>(tdespues - tantes);

	    t += transcurrido.count();
	    
	    delete [] T;
    }
    
    t = ((double)t/REPS);
    
    cout << n << " " << t << endl;

    return 0;
    
}
