/**
   @file Resolución del problema de las Torres de Hanoi
*/

   
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std::chrono;


/**
   @brief Resuelve el problema de las Torres de Hanoi
   @param M: número de discos. M > 1.
   @param i: número de columna en que están los discos.
             i es un valor de {1, 2, 3}. i != j.
   @param j: número de columna a que se llevan los discos.
             j es un valor de {1, 2, 3}. j != i.

   Esta función imprime en la salida estándar la secuencia de 
   movimientos necesarios para desplazar los M discos de la
   columna i a la j, observando la restricción de que ningún
   disco se puede situar sobre otro de tamaño menor. Utiliza
   una única columna auxiliar.
*/
void hanoi (int M, int i, int j);




void hanoi (int M, int i, int j)
{
  if (M > 0)
    {
      hanoi(M-1, i, 6-i-j);
      cout << i << " -> " << j << endl;
      hanoi (M-1, 6-i-j, j);
  }
}

int main(  int argc, char * argv[]){
  double time_total = 0;

  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int M = atoi(argv[1]);

  if (M < 0){
    cerr << "Parametro >= 0 " << endl;
      return -1;
  }

  high_resolution_clock::time_point tantes, tdepues, tantes_vacio, tdespues_vacio;
  duration<double> transcurrido;

  for (int i=0; i < 15; i++){

    tantes = high_resolution_clock::now();

    hanoi(M, 1, 2);

    tdepues = high_resolution_clock::now();

    transcurrido = duration_cast<duration<double>>(tdepues - tantes);

    time_total += transcurrido.count();
  }

  time_total /= 15;
  cout << M << " " << time_total << endl;

  return 0;
}
