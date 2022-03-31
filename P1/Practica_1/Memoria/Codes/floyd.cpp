void Floyd(int **M, int dim)
{
	for (int k = 0; k < dim; k++) //O(n)
	  for (int i = 0; i < dim;i++) //O(n)
	    for (int j = 0; j < dim;j++) //O(n)
	      {
		int sum = M[i][k] + M[k][j];    	
	    	M[i][j] = (M[i][j] > sum) ? sum : M[i][j]; //O(1)
	      }
}	     	//Total O(n^3)
