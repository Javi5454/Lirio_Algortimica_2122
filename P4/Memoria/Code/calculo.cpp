// Calculo de la matriz de cálculos
for(int i = 1; i < n+1; i++){
    for(int j = 1; j < m+1; j++){
        if(entrada1[i-1] == entrada2[j-1]){
            matriz_calculos[i][j] = matriz_calculos[i-1][j-1]+1;
        }
        else{
            if(matriz_calculos[i][j-1] >= matriz_calculos[i-1][j]){
        	matriz_calculos[i][j] = matriz_calculos[i][j-1];
            }
            else{
        	matriz_calculos[i][j] = matriz_calculos[i-1][j];
            }
        }
    }
}
