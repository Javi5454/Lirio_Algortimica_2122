void mergeKArrays(int n, int **arr, int n1,int n2, int * &array_resultante)
{
    //si solo hay un array
    if(n1==n2) // O(1)
    {
        for(int i=0; i < n; i++) // O(n)
        array_resultante[i]=arr[n1][i];
    }
    else{
    /*
    //si solo hay dos arrays los mezcla
    if(n2-n1==1)
    {
        merge2Arrays(arr[n1],arr[n2],n,n,array_resultante);
        return;
    }
    */
      int nVect = n2-n1+1; // O(1)
      int mitad = (n2+n1)/2; // O(1)

      //Dimensiones arrays auxiliares
      int tam2 = nVect/2; // O(1)
      int tam1 = nVect - tam2; // O(1)

        //Arrays resultantes

        int *array1 = nullptr; // O(1)
        reservarArray(n*(tam1), array1); // O(1)
        int *array2 = nullptr; // 0(1)
        reservarArray(n*(tam2), array2); // O(1)
         
        //divide el array en dos mitades
        mergeKArrays(n, arr,n1,mitad,array1); // O(kn/2)
        mergeKArrays(n, arr,mitad+1,n2,array2); // O(kn/2)
        
        //mezcla el array resultante
        merge2Arrays(array1,array2,n*tam1,n*tam2,array_resultante); // O(kn/2)


        if (array1 != nullptr){ // O(1)
            delete[] array1; // O(1)
        }
        if(array2 != nullptr){ // O(1)
            delete[] array2; // O(1)
        }
    }

}

