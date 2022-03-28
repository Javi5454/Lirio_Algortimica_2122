static void heapsort(int T[], int num_elem)
{
  int i;
  for (i = num_elem/2; i >= 0; i--)    //O(n)
    reajustar(T, num_elem, i);                //O(log(n))
  for (i = num_elem - 1; i >= 1; i--)  //O(n)
    {
      int aux = T[0];
      T[0] = T[i];
      T[i] = aux;
      reajustar(T, i, 0); //O(log(n))
    }
    //Total = O(nlog(n))
}
  

static void reajustar(int T[], int num_elem, int k)
{
  int j;
  int v;
  v = T[k];
  bool esAPO = false;
  while ((k < num_elem/2) && !esAPO)    //O(og(n))
    {
      j = k + k + 1;                     
      if ((j < (num_elem - 1)) && (T[j] < T[j+1]))    //O(1)
	       j++;
      if (v >= T[j])                                  //O(1)
	       esAPO = true;
      T[k] = T[j];
      k = j;
    }
  T[k] = v;

  //Total = O(log(n))
}