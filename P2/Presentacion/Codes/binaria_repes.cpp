int buscarBinaria(int v[], int inicio,int fin){
    int medio = (inicio + fin)/2; // O(1)
    int resultado = -1; // O(1)

    if(v[medio] == medio){ // O(1)
        return medio; // O(1)
    }
    else{
        if(inicio <= fin){ // O(1)
            resultado = buscarBinaria(v, inicio, medio - 1); // O(n/2)

            if(resultado == -1){
                resultado = buscarBinaria(v, medio + 1, fin); // O(n/2)
            }
        }
    }

    return resultado; // O(1)

}
