void mergeKArrays(int nElementos, int **arr, int nVectores, int * &v_resultante)
{

    int k = 0;
    bool encontrado;
    for(int i = 0; i < nElementos; i++){
      v_resultante[i] = arr[0][i];
    }

    for(int i = 1; i < nVectores; i++){         //O(k)
      for(int j = 0; j < nElementos; j++){      //O(n)
        encontrado = false;
        k = 0;
        while(k < nElementos * i + j && !encontrado){   //O(kn + n)
          if(v_resultante[k] > arr[i][j])
            encontrado = true;
          else
            k++;
        }
        
        if(encontrado){
          for(int l = nElementos*i+j-1; l >= k; l--){   //O(kn)
            v_resultante[l+1] = v_resultante[l];
          }
          v_resultante[k] = arr[i][j];
        }
        else{
          v_resultante[nElementos * i + j ] = arr[i][j];
        }
      }
    }
     
}