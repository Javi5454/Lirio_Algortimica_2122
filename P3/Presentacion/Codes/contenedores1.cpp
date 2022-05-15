int contenedoresGreedy1(int *T, int n){
    
    	int used = 0;
    	int result = 0;
	vector<int> myvector(T,T+n);
	sort(myvector.begin(),myvector.end());
	
	for(int i = 0; (i < n) && (used <= n); i++){
		used += T[i];
		result++;
	}
	
	return result;
}
