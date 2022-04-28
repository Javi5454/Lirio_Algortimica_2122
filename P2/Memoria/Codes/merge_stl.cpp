vector<int> merge(vector<int> v1, vector<int> v2){
		vector<int> merged(v1.size() + v2.size());
		int pos1 = 0;
		int pos2 = 0;

		while(pos1 < v1.size() || pos2 < v2.size()){
				if(pos1 == v1.size()){
						merged[pos1 + pos2] = v2[pos2];
						pos2++;
				}else if(pos2 == v2.size()){
						merged[pos1 + pos2] = v1[pos1];
						pos1++;
				}else{
						if(v1[pos1] < v2[pos2]){
								merged[pos1 + pos2] = v1[pos1];
								pos1++;
						}else{
								merged[pos1 + pos2] = v2[pos2];
								pos2++;
						}
				}
		}

		return merged;
}

vector<vector<int> > merge_first_two_vectors(vector<vector<int> > matrix){
		// Matriz con un vector menos, resultado de la mezcla
		vector<vector<int> > merged_matrix(matrix.size() - 1);

		// Vector que hemos mezclado
		vector<int> merged = merge(matrix[0], matrix[1]);

		// Calculamos los datos de la nueva matriz
		merged_matrix[0] = merged;
		for(int i = 1; i < merged_matrix.size(); i++){
				merged_matrix[i] = matrix[i+1];
		}

		return merged_matrix;
}

vector<int> merge_vectors_basic(vector<vector<int> > matrix){
		// Caso base para parar la recursividad
		if(matrix.size() == 1){
				return parse_matrix_to_vector(matrix);

		}else{
				matrix = merge_first_two_vectors(matrix);
				return merge_vectors_basic(matrix);
		}
}
