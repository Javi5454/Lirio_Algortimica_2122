void merge2Arrays(int * &arr1, int * &arr2, int n1, int n2, int * &arr3)
{
    int i = 0, j = 0, k= 0;
 
    // Traverse both array
    while (i<n1 && j <n2) // O(kn/2)
    {
        // Comprueba si el elemento actual del primer array 
        // es menor que el elemento actual del segundo array
        // Si es menor, almacena el elemento del primer array
        // e incrementa el indice del primer array
        // En otro caso hace lo correspondiente pero en el segundo array
        if (arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
            k++;
        }

    }
 
    // Store remaining elements of first array
    while (i < n1){
        arr3[k] = arr1[i];
        i++;
        k++;
    }
 
    // Store remaining elements of second array
    while (j < n2){
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}
