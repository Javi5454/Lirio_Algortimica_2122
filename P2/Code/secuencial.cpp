/**
 * @file secuencial.cpp
 * @author Javier Gómez López
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

using namespace std;
using namespace std::chrono;

/**
 * @brief Method of searching
 * @param v: Vector in where to search
 * @param n: number of elements in the vector
 * @return the index of the element or -1 if it does not exists
 */

int buscarSecuencial(int v[], int n){
    for (size_t i = 0; i < n; i++)
    {
        if (v[i] == i){
            return i;
        }
        else if(v[i] > n){
            return -1;
        }
    }

    return -1;
}

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "Syntax error: ./secuencial <Num of elements> <Input File>" << endl;

        return -1;
    }

    int n = stoi(argv[1]);

    int *T = new int[n];
    assert(T);

    string route = argv[2];
    string line;

    ifstream myFile(route);

    if(myFile.is_open()){
        for (size_t i = 0; i < n; i++)
        {
            getline(myFile, line);

            int current_number = stoi(line);

            T[i] = current_number;
        }

        myFile.close();
    }

    /*for (size_t i = 0; i < n; i++) //UNCOMMENT FOR SHOWING THE VECTOR
    {
        cout << "v[" << i << "]: " << T[i] << endl;
    }*/

    //cout << endl;

    high_resolution_clock::time_point tantes, tdespues;
    duration<double> transcurrido;

    tantes = high_resolution_clock::now();

    int result = buscarSecuencial(T, n);

    tdespues = high_resolution_clock::now();

    transcurrido = duration_cast<duration<double>>(tdespues - tantes);

    double time_total = transcurrido.count();

    cout << n << "\t" << time_total << endl;

    delete [] T;

    return 0;
    
}