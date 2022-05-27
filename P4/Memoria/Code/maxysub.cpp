// Buscamos el máximo en la última fila de la matriz de cálculos
	
int max = 0;
int posj = 0;
	
for(int j = 1; j < m+1; j++){
	if(matriz_calculos[n][j] >= max){
		max = matriz_calculos[n][j];
		posj = j;
	}
}
	
// Realizamos el camino hacia atrás y almacenamos la subsecuencia en una lista
	
list<char> resultado;
int i = n;
	
while(i >= 1){
		
	// Si hay coincidencia, almacenamos la letra al principio de la cadena
	// Nos vamos a la anterior fila en diagonal
		
	if(entrada1[i-1] == entrada2[posj-1]){
		resultado.push_front(entrada2[posj-1]);
		posj--;
		i--;
	}
	else{
		
		// Si no hay coincidencia, vemos cuál es el máximo de entre la
		// casilla de la izquierda y la de arriba a la actual, y nos 
		// movemos hacia donde esté el máximo
			
		if(matriz_calculos[i][posj-1] == matriz_calculos[i][posj]){
			posj--;
		}
		else{
			i--;
		}
	}
}
