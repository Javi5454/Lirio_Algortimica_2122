static void seleccion_lims(int T[], int inicial, int final)
{
  int i, j, indice_menor;
  int menor, aux;
  for (i = inicial; i < final - 1; i++) { // O(n)
    indice_menor = i; // O(1)
    menor = T[i]; // O(1)
    for (j = i; j < final; j++) // O(n)
      if (T[j] < menor) {
	indice_menor = j; // O(1)
	menor = T[j]; // O(1)
      }
    aux = T[i]; // O(1)
    T[i] = T[indice_menor]; // O(1)
    T[indice_menor] = aux; // O(1)
  };
}
