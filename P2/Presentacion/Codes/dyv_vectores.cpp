void mergeKArrays(int n, int **arr, int n1,int n2, int * &array_resultante)
{
    //si solo hay un array
    if(n1==n2){                     //O(n)
        for(int i=0; i < n; i++)                
        array_resultante[i]=arr[n1][i];
    }
    else{

      int nVect = n2-n1+1;
      int mitad = (n2+n1)/2;

      //Dimensiones arrays auxiliares
      int tam2 = nVect/2;
      int tam1 = nVect - tam2;

        //Arrays resultantes

        int *array1 = nullptr;
        reservarArray(n*(tam1), array1);
        int *array2 = nullptr;
        reservarArray(n*(tam2), array2);
         
        //divide el array en dos mitades
        mergeKArrays(n, arr,n1,mitad,array1);
        mergeKArrays(n, arr,mitad+1,n2,array2);
        
        //mezcla el array resultante
        merge2Arrays(array1,array2,n*tam1,n*tam2,array_resultante);     //O(kn)


        if (array1 != nullptr){
            delete[] array1;
        }
        if(array2 != nullptr){
            delete[] array2;
        }
    }

}