while(i >= 1){		
	if(entrada1[i-1] == entrada2[posj-1]){
		resultado.push_front(entrada2[posj-1]);
		posj--;
		i--;
	}
	else{
		if(matriz_calculos[i][posj-1] == matriz_calculos[i][posj]){
			posj--;
		}
		else{
			i--;
		}
	}
}
