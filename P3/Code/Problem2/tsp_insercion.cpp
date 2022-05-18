/**
 * @file tsp_insercion.cpp
 * @author SEMIGRUPO - ALG2
 * @brief Resuelve Travelling Salesman Problem por insercion
 *
 * Uso: ./tsp_insercion <file_name>
 * Compilacion: g++ tsp_insercion.cpp -o tsp_insercion
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

//USE EL SIGUIENTE FLAG PARA COMPROBAR DE FORMA EXPLICITA LOS CALCULOS DE TSP_CERCANIA
//#define DEBUG
//USE EL SIGUIENTE FLAG PARA MOSTRAR LAS DISTANCIAS ENTRE PUNTOS
//#define SHOW_DISTANCIAS
//USE EL SIGUIENTE FLAG PARA MOSTRAR EL RESULTADO DE LA RUTA POR PANTALLA
#define SHOW_RUTA
//USE EL SIGUIENTE FLAG PARA MOSTRAR EL COSTE DE LA RUTA POR PANTALLA
#define SHOW_COST
//USE EL SIGUIENTE FLAG PARA MOSTRAR LOS DATOS EN FORMATO EXPORTABLE A FICHERO
//#define EXPORT_TO_FILE

using namespace std;

/**
 * @brief Estructura de datos que almacena informacion de un punto bidimensional
 */
struct Punto{
  int ID = 0;
  double x = 0;
  double y = 0;
};

/**
 * @brief Funcion ayuda. Muestra los correctos paramtros de lanzamiento del programa
 * @param filename : argv[0]
 */
void help(const char * filename);

/**
 * @brief Lee un fichero de datos y almacena la informacion en un vector
 * @param vector : Vector de Puntos donde se guardara la localizacion de cada nodo
 * @param fichero : Nombre de fichero a leer
 * @return TRUE si se ha realizado la lectura con exito, FALSE en otro caso
 */
bool leerFichero(vector<Punto> & vector, const char * fichero);

/**
 * @brief Calcula la distancia entre dos puntos pasados como argumento
 * @param p1 : Punto 1
 * @param p2 : Punto 2
 * @return Distancia entre 2 puntos redondeada al entero mas cercano
 */
int distancia(Punto p1, Punto p2);

/**
 * @brief Obtiene las distancias entre todos los puntos
 * @param v : vector de puntos
 * @return Una matriz 2D con todas las distancias obtenidas
 */
int** obtenerDistancias(vector<Punto> v);

/**
 * @brief Elimina un punto de un vector de puntos
 * @param v : Vector de puntos
 * @param punto : Punto a eliminar
 */
void eliminarPunto(vector<Punto> & v, Punto punto);

/**
 * @brief Calcula el coste de una ruta
 * @param vector : Vector de puntos con la ruta final
 * @param distancias : Matriz 2D con las distancias de todos los puntos
 * @return coste de la ruta
 */
int calcularCoste(vector<Punto> vector, int ** distancias);

/**
 * @brief Calcula una ruta inicial con el punto mas al oeste, mas al norte y mas al este
 * @param v : Vector de puntos
 * @param solucion : Solucion de la ruta
 */
void recorridoParcial(vector<Punto> & v, vector<Punto> &solucion);

/**
 * @brief Calcula la mejor ruta dado un grafo no dirigido almacenado en un vector de puntos
 * @param v : Vector de puntos que representa el grafo inicial
 * @param solucion : Vector de puntos donde se almacena la ruta final
 */
void tsp_insercion(vector<Punto> v, vector<Punto> &solucion);

/**
 * @brief Calcula el tiempo de ejecucion del algoritmo
 * @param vector : Vector de puntos a calcular tsp_cercania
 * @param solucion : Vector de puntos donde se almacenara la ruta
 * @return Tiempo de ejecucion de tsp_cercania
 */
static double runTest(vector<Punto> & v, vector<Punto> & solucion);

/**
 * @brief Muestra la ruta obtenida
 * @param v : Vector de puntos
 */
void muestraRuta(vector<Punto> v);

/**
 * @brief Muestra un vector por pantalla
 * @param v : Vector de puntos
 */
void muestraVector(vector<Punto> v);

/**
 * @brief Muestra una matriz por pantalla
 * @param m : Matriz 2D
 * @param dimension : Dimension de matriz
 */
void muestraMatriz(int ** m, int dimension);

/**
 * @brief Libera la memoria de una matriz dinamica
 * @param matriz : Matriz 2D
 * @param dimension : Dimension de la matriz
 */
void liberarMemoria(int ** &matriz, int dimension);

/**
 * @brief Muestra el vector de puntos en formato exportable a fichero
 */
void exportToFile(vector<Punto> puntos);

//=======================================================================================================

/**
 * Funcion obtenerDistancias(). Vease Doxigen commit mas arriba
 */
int ** obtenerDistancias(vector<Punto> v){
    int ** distancias = nullptr;
    unsigned int dimension = v.size();

    //RESERVA DE MEMORIA DINAMICA
    distancias = new int * [dimension];
    if(distancias == nullptr){
        cerr << "ERROR [0] AL OBTENER DISTANCIAS... NO SE HA PODIDO RESERVAR MEMORIA SUFICIENTE..." << endl;
        exit(EXIT_FAILURE);
    }

    for(unsigned int i=0; i<dimension; i++){
        distancias[i] = new int [dimension];
        if(distancias[i] == nullptr){
            cerr << "ERROR [1] AL OBTENER DISTANCIAS... NO SE HA PODIDO RESERVAR MEMORIA PARA COLUMNA [" << i << "]..." << endl;
            for(int j=i; j>=0; j--)
              delete [] distancias[j];
            delete [] distancias;
            distancias = nullptr;

            exit(EXIT_FAILURE);
        }
    }

    for(unsigned int i=0; i<dimension; i++){
        distancias[i][i] = 0;
        for(unsigned int j=0; j<dimension; j++)
          if(i != j)
            distancias[i][j] = distancia(v[i],v[j]);
    }

    return distancias;
}

/**
 * Funcion eliminarPunto(). Vease Doxygen commit mas arriba
 */
void eliminarPunto(vector<Punto> & v, Punto punto){
  bool eliminado = false;
  vector<Punto>::iterator it;
  for(it = v.begin(); it!=v.end() && !eliminado; ++it){
    if((*it).ID == punto.ID){
      v.erase(it);
      eliminado = true;
    }
  }
}

/**
 * Funcion recorridoParcial(). Vease Doxygen commit mas arriba
 */
void recorridoParcial(vector<Punto> & v, vector<Punto> &solucion){
  Punto norte, oeste, este;
  norte = oeste = este = v[0];
  vector<Punto>::iterator it;

  for(it = v.begin()+1; it != v.end(); ++it){
    if((*it).y > norte.y){
        norte = *it;
    }
    if((*it).x < oeste.x){
        oeste = *it;
    }
    if((*it).x > este.x){
        este = *it;
    }
  }

  #ifdef DEBUG
    cout << "ELIMINO PUNTO NORTE..." << (norte).ID << endl;
    cout << "ELIMINO PUNTO OESTE..." << (oeste).ID << endl;
    cout << "ELIMINO PUNTO ESTE..." << (este).ID << endl;
  #endif

  //ELIMINAMOS DE LOS CANDIDATOS LOS 3 PUNTOS ELEGIDOS
  eliminarPunto(v,norte);
  eliminarPunto(v,este);
  eliminarPunto(v,oeste);

  //INSERTAMOS EN LA SOLUCION LOS PUNTOS DEL CAMINO INICIAL
  solucion.push_back(norte);
  solucion.push_back(oeste);
  solucion.push_back(este);

  #ifdef DEBUG
    cout << "NODO MAS AL NORTE: " << norte.ID << " - (" << norte.x << "," <<  norte.y << ")" << endl;
    cout << "NODO MAS AL OESTE: " << oeste.ID << " - (" << oeste.x << "," <<  oeste.y << ")" << endl;
    cout << "NODO MAS AL ESTE: " << este.ID << " - (" << este.x << "," <<  este.y << ")" << endl;
  #endif
}

/**
 * Funcion test_insercion(). Vease Doxygen commit mas arriba
 */
void tsp_insercion(vector<Punto> v, vector<Punto> &solucion){
    const int INT_MAX = 2147483647;
    vector<Punto> candidatos = v;
    //OBTENEMOS UN RECORRIDO PARCIAL
    recorridoParcial(candidatos, solucion);

    #ifdef DEBUG
      cout << "RECORRDIO PARCIAL HASTA EL MOMENTO..." << endl;
      for(unsigned int i=0; i<solucion.size(); i++){
          cout << solucion[i].ID << " ";
      }
      cout << endl;

      cout << "CANDIDATOS ANTES DE COMENZAR..." << endl;
      muestraVector(candidatos);
    #endif

    int minimaDistancia = INT_MAX;
    int menorIncremento;
    Punto puntoCandidato;
    vector<pair<Punto,int>> posiblesCandidatos;
    pair<Punto,int> puntoPosibleCandidato;
    int dist = 0;
    int indiceInsercion = 0;

    //COMIENZO ALGORITMO VORAZ
    while(!candidatos.empty()){
        //RECORREMOS LOS NODOS SOLUCION
        for(unsigned int i=0; i<solucion.size(); i++){
            //RECORREMOS LOS NODOS CANDIDATOS
            for(unsigned int j=0; j<candidatos.size(); j++){
                //PARA CADA PUNTO DE LA SOLUCION, ENCONTRAMOS EL NODO MAS CERCANO A EL
                dist = distancia(solucion[i],candidatos[j]);

                if(dist < minimaDistancia){
                    minimaDistancia = dist;
                    puntoCandidato = candidatos[j];

                    #ifdef DEBUG
                      cout << "CAMBIO EN PUNTO CANDIDATO. AHORA ES --> " << puntoCandidato.ID << endl;
                    #endif
                }
            }
            //UNA VEZ OBTENEMOS EL NODO MAS CERCANO AL NODO SOLUCION, LO INSERTAMOS EN UN VECTOR TEMPORAL DE PUNTO,INCREMENTO
            puntoPosibleCandidato.first = puntoCandidato;
            puntoPosibleCandidato.second = minimaDistancia;
            posiblesCandidatos.push_back(puntoPosibleCandidato);

            #ifdef DEBUG
              cout << endl << "HE INSERTADO EN VECTOR EL NODO:" << endl;
              cout << "----> NODO: " << puntoPosibleCandidato.first.ID << endl;
              cout << "----> INCREMENTO: " << puntoPosibleCandidato.second << endl;
            #endif

            //RESETEAMOS minimaDistancia
            minimaDistancia = INT_MAX;
        }

        #ifdef DEBUG
          cout << endl << "MOSTRANDO VECTOR DE POSIBLESCANDIDATOS TRAS ESTUDIAR INCREMENTOS..." << endl;
          for(unsigned int i=0; i<posiblesCandidatos.size(); i++){
              cout << posiblesCandidatos[i].first.ID << " - " << posiblesCandidatos[i].second << endl;
          }
        #endif

        //DE LOS CANDIDATOS OBTENIDOS, ESCOGEMOS EL QUE MENOR INCREMENTO PRODUCE DE TODOS
        menorIncremento = INT_MAX;
        for(unsigned int i=0; i<posiblesCandidatos.size(); i++){
            if(posiblesCandidatos[i].second < menorIncremento){
                menorIncremento = posiblesCandidatos[i].second;
                indiceInsercion = i;
            }
        }

        #ifdef DEBUG
          cout << endl << "TRAS BUCLE FOR. HE DECIDIDO QUE EL PUNTO MAS OPTIMO SEA..." << endl;
          cout << "---> "<< posiblesCandidatos[indiceInsercion].first.ID << " - " << posiblesCandidatos[indiceInsercion].second << endl;
        #endif

        //INSERTAMOS EN LA SOLUCION EL NODO ESCOGIDO EN EL SITIO CORRESPONDIENTE
        solucion.insert(solucion.begin()+indiceInsercion+1,posiblesCandidatos[indiceInsercion].first);

        #ifdef DEBUG
          cout << endl << "MOSTRANDO RUTA ACTUALMENTE..." << endl;
          muestraRuta(solucion);
        #endif

        //ELIMINAMOS EL NODO ESCOGIDO DEL VECTOR DE CANDIDATOS
        eliminarPunto(candidatos,posiblesCandidatos[indiceInsercion].first);
        #ifdef DEBUG
          cout << "VOY A ELIMINAR DE CANDIDATOS EL NODO --> " << posiblesCandidatos[indiceInsercion].first.ID << endl;
        #endif

        //LIMPIAMOS VECTOR DE CANDIDATOS
        posiblesCandidatos.clear();
    }
}

//=======================================================================================================

/**
 * @brief Funcion principal.
 * @param narg : Numero de argumentos
 * @param argv[] : Vector de argumentos
 */
int main(int narg, char* argv[]){
  //PASO 0 : COMPROBACION DE ARGUMENTOS
  if(narg != 2){
      help(argv[0]);
      exit(EXIT_FAILURE);
  }

  //PASO 1 : DECLARACION DE VARIABLES
	vector<Punto> v, solucion;

  //PASO 2 : LEER FICHERO DE DATOS
	if(!leerFichero(v, argv[1])){
      cerr << "ERROR AT P2 LEYENDO FICHERO [" << argv[1] << "]. SALIENDO..." << endl;
      exit(EXIT_FAILURE);
  }

  cout << "OBTENIENDO DISTANCIAS..." << endl;
  unsigned int dimension = v.size();
  int ** distancias = obtenerDistancias(v);

  #ifdef SHOW_DISTANCIAS
    cout << endl << "MOSTRANDO DISTANCIAS OBTENIDAS..." << endl;
    muestraMatriz(distancias,dimension);
  #endif

  //OPCIONAL : MOSTRAR PUNTOS OBTENIDOS
  #ifdef DEBUG
    cout << ">> MOSTRANDO VECTOR..." << endl;
    muestraVector(v);
    cout << endl << endl;
  #endif

  //PASO 3 : CALCULAR TIEMPO DE EJECUCION...
  double t_ejecucion = runTest(v,solucion);

  //OPCIONAL : CALCULO EXCLUSIVO DE COSTE
  #ifdef SHOW_COST
    int costeRuta = calcularCoste(solucion,distancias);
    cout << "COSTE DE LA RUTA : " << costeRuta << endl;
  #endif

  //PASO 4 : MOSTRAR RUTA...
  #ifdef SHOW_RUTA
    cout << ">> MOSTRANDO RUTA OBTENIDA..." << endl;
    muestraRuta(solucion);
  #endif

  #ifdef EXPORT_TO_FILE
    exportToFile(solucion);
  #endif

  //PASO 5 : MOSTRANDO TIEMPOS
  cout << "DIMENSION GRAFO: "<< v.size() << " | TIEMPO: " << t_ejecucion << endl;

  //PASO 6 : LIBERAMOS MEMORIA MATRIZ DISTANCIAS
  liberarMemoria(distancias,dimension);

  return EXIT_SUCCESS;
}

//=======================================================================================================

/**
 * Funcion help(). Vease Doxygen commit mas arriba
 */
void help(const char * filename){
    cout << "USO: " << filename << "<filename>" << endl;
    cout << "filename --> fichero de datos a leer." << endl;
}

//=======================================================================================================

/**
 * Funcion leerFichero(). Vease Doxygen mas arriba
 */
bool leerFichero(vector<Punto> & vector, const char * fichero){
    bool resultado = false; bool validState = false;
    string sentencia;
    ifstream fin;
    Punto p;

    const string startLine = "NODE_COORD_SECTION";
    const string end = "EOF";

    fin.open(fichero);
    if(fin){
        while(getline(fin,sentencia)){
          if (sentencia == end){
            validState = false;
          }

            if(validState){
                stringstream flujo_linea(sentencia);
                flujo_linea >> p.ID;
                flujo_linea >> p.x;
                flujo_linea >> p.y;
                vector.push_back(p);

            }
            if(sentencia == startLine)
                validState = true;
        }
        resultado = true;
        fin.close();
    }
    else{
        cerr << "ERROR AL ABRIR FICHERO >>> [" << fichero << "]" << endl;
    }

    return resultado;
}

//=======================================================================================================

/**
 * Funcion distancia(). Vease Doxygen commit mas arriba
 */
int distancia(Punto p1, Punto p2){
  return sqrt(pow(p2.x - p1.x,2) + pow(p2.y - p1.y,2)) + 0.5;
}

//=======================================================================================================

/**
 * Funcion calcularCoste(). Vease Doxygen commit mas arriba
 */
int calcularCoste(vector<Punto> vector, int ** distancias){
    int coste = 0;
    unsigned int dimension = vector.size();

    for(unsigned int i=0; i<dimension-1; i++){
        coste += distancias[vector[i].ID-1][vector[i+1].ID-1];
    }
    coste += distancias[vector[dimension-1].ID-1][vector[0].ID-1];

    return coste;
}

//=======================================================================================================

/**
 * FUNCION runTest(). Vease Doxygen commit mas arriba
 */
static double runTest(vector<Punto> &v, vector<Punto> &solucion){
    //VARIABLES UTILIZADAS PARA EL CALCULO DEL TIEMPO
    double t_ejecucion = 0, t_transcurrido = 0;
    clock_t tantes, tdespues;

    //CALCULO DE LA EJECUCION DEL ALGORITMO
    tantes = clock();
    tsp_insercion(v,solucion);
    tdespues = clock();

    t_transcurrido = (double)(tdespues - tantes);

    //CALCULO EJECUCION FINAL
    t_ejecucion = t_transcurrido / (CLOCKS_PER_SEC);

    return t_ejecucion;
}

//=======================================================================================================

/**
 * Funcion muestraRuta(). Vease Doxigen commit mas arriba
 */
void muestraRuta(vector<Punto> v){
  for(unsigned int i = 0; i < v.size() - 1; i++){
    cout << v[i].ID << " -> ";
  }
  cout << v[v.size()-1].ID << endl;
}

//=======================================================================================================

/**
 * Funcion muestraVector(). Vease Doxigen commit mas arriba
 */
void muestraVector(vector<Punto> v){
  for(unsigned int i=0; i< v.size(); i++){
    cout << "NODE: " << v[i].ID << " --> (" << v[i].x << "," << v[i].y << ")" << " ";
    if((i+1) % 5 == 0)
      cout << endl;
  }
}

//=========================================================================================

/**
 * Funcion muestraMatriz. Vease Doxygen commit
 */
void muestraMatriz(int ** m, int dimension){
  for(int i=0; i<dimension; i++){
    for(int j=0; j<dimension; j++){
        cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

//=========================================================================================

/**
 * Funcion liberarMemoria(). Vease Doxygen commit mas arriba
 */
void liberarMemoria(int ** &matriz, int dimension){
    for(int i=0; i<dimension; i++)
      delete [] matriz[i];
    delete [] matriz;
    matriz = nullptr;
}

//=========================================================================================

void exportToFile(vector<Punto> solucion){
    for(unsigned int i=0; i<solucion.size(); i++){
      cout << solucion[i].ID << " " << solucion[i].x << " " << solucion[i].y << endl;
    }
}
