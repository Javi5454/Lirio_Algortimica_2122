int ** matriz_calculos = nullptr;

// Reserva de memoria

matriz_calculos = new int * [n+1];
for(int i=0; i < n+1; i++){
        matriz_calculos[i] = new int [m+1];
}

// Inicialización a 0 de la matriz
        
for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
        	matriz_calculos[i][j] = 0;
        }
}
