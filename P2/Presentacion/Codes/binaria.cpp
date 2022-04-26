<<<<<<< HEAD
int buscarBinaria(int *v, int inicio, int fin){
    if(fin >= inicio){ // O(1)
        int medio = inicio + (fin - inicio) / 2; // O(1)

        if(v[medio] == medio){ // O(1)
            return medio; // O(1)
        }

        if(v[medio] > medio){ // O(1)
            return buscarBinaria(v, inicio, medio - 1); // O(n/2)
        }

        //else
        return buscarBinaria(v, medio + 1, fin); // O(n/2)
    }

    return -1; // O(1)
}
=======
int buscarBinaria(vector<int> v, int n){ 

    int inicio = 0; //O(1)
    int fin = n-1; //O(1)
    int medio = (inicio+fin)/2; //O(1)

    while(inicio <= fin){ //O(log(n))

        if(v.at(medio) > medio){ //O(1)
            fin = medio - 1; //O(1)
        }
        else if(v.at(medio) < medio){ //O(1)
            inicio = medio + 1; //O(1)
        }
        else{
            return medio; //O(1)
        }
        
        medio = (inicio + fin)/2; //O(1)
    }
    
    return -1; //O(1)
}
>>>>>>> 3aa3343252e6409c9458e66ee19538af2290208c
