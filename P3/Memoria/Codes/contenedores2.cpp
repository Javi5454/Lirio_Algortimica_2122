int contenedoresGreedy2(int *T, int n){
    
    	int used = 0;
	vector<int> myvector(T,T+n);
	sort(myvector.begin(),myvector.end(), greater<int>());
	
	for(int i = 0; (i < n) && (used <= n); i++){
		used += T[i];
	}
	
	return used;
}
