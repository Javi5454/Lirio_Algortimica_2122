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