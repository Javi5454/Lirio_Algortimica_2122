int buscarSecuencial(int v[], int n){
    for (size_t i = 0; i < n; i++) //O(n)
    {
        if (v[i] == i){ //O(1)
            return i; //O(1)
        }
        else if(v[i] > n){ //O(1)
            return -1; //O(1)
        }
    }

    return -1;//O(1)
}
