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
