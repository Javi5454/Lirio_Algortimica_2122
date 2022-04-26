<<<<<<< HEAD
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
=======
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
>>>>>>> 3aa3343252e6409c9458e66ee19538af2290208c
