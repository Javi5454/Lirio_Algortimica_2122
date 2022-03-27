static void insercion_lims(int T[], int inicial, int final)
{
  int i, j;
  int aux;
  for (i = inicial + 1; i < final; i++) { // O(n)
    j = i; // O(1)
    while ((T[j] < T[j-1]) && (j > 0)) { // O(n)
      aux = T[j]; // O(1)
      T[j] = T[j-1]; // O(1)
      T[j-1] = aux; // O(1)
      j--; // O(1)
    };
  };
}

