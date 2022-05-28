int max = 0;
int posj = 0;
	
for(int j = 1; j < m+1; j++){
	if(matriz_calculos[n][j] >= max){
		max = matriz_calculos[n][j];
		posj = j;
	}
}

list<char> resultado;
int i = n;
	
