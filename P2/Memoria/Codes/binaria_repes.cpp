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