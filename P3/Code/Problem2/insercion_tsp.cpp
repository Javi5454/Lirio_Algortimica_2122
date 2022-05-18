#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;


struct Point
{
	int posicion_obtencion;
	double x;
	double y;

	bool operator==(Point a){
		if (a.x == x and a.y == y){
			return true;
		}
		else
			return false;
	}
	bool operator!=(Point a){
		if (a.x != x or a.y != y){
			return true;
		}
		else
			return false;
	}

};

int distacia2Puntos(Point punto1, Point punto2){
	if(punto1 == punto2)
		return 0;
	else
		return sqrt(pow((punto2.x - punto1.x),2) + pow((punto2.y - punto1.y),2)) + 0.5;
}

void salidaPunto(Point punto){
	cout << "Posicion obtencion: " << punto.posicion_obtencion << endl;
	cout << "x: " << punto.x << endl;
	cout << "y: " << punto.y << endl;
}

void borrarPunto(Point punto, vector <Point> & circuito){
  bool hecho = false;
  vector<Point>::iterator it;
  for(it = circuito.begin(); it!=circuito.end() && !hecho; ++it){
    if((*it).posicion_obtencion == punto.posicion_obtencion){
      hecho = true;
      circuito.erase(it);
    }
  }
}

void TSP_Insercion(vector<Point> candidatos, vector<Point> &circuito_solucion){
    vector<Point> v_candidatos = candidatos;
    int menorInc;
    //vector auxiliar con los posibles candidatos junto con sus array_distancias minimas dentro del recorrido
    vector<pair<Point,int>> posibles;
    Point pCandidato;
    int dist_minima = 100000000;
    int distancia_auxiliar = 0;
    int indice = 0;
    //punto que sera un candidato a ser solucion junto con su distancia minima dentro del recorrido
    pair<Point,int> pPosibleCandidato;

    //Greedy: recorremos para cada nodo solucion los candidatos y encontramos
    //		para cada nodo solucion el más cercano
    while(!v_candidatos.empty()){
        for(int i=0; i< circuito_solucion.size(); i++){
            for(int j=0; j<v_candidatos.size(); j++){
                distancia_auxiliar = distacia2Puntos(v_candidatos[j], circuito_solucion[i]);

                if(distancia_auxiliar < dist_minima){
                    pCandidato = v_candidatos[j];
                    dist_minima = distancia_auxiliar;
                }
            }
            //insertamos nodo solucion en vector auxiliar
            pPosibleCandidato.first = pCandidato;
            pPosibleCandidato.second = dist_minima;
            posibles.push_back(pPosibleCandidato);

            dist_minima = 100000000;
        }

        //escogemos el candidato con menor distancia
        menorInc = 100000000;
        for(unsigned int i=0; i<posibles.size(); i++){
            if(posibles[i].second < menorInc){
                menorInc = posibles[i].second;
                indice = i;
            }
        }
        circuito_solucion.insert(circuito_solucion.begin()+indice+1,posibles[indice].first);
        /*
          cout << endl << "MOSTRANDO RUTA ACTUALMENTE..." << endl;
          muestraRuta(solucion);
        */
        borrarPunto(posibles[indice].first, v_candidatos);

        posibles.clear();
    }
}


//esta funcion es simplemente de depuracion
int ** calculando_array_distancias(vector<Point> v){
    int dimension = v.size();
    int ** array_distancias = nullptr;

    array_distancias = new int * [dimension];
    if(array_distancias == nullptr){
        cerr << "Memoria insuficiente" << endl;
        exit(EXIT_FAILURE);
    }

    for(int i=0; i<dimension; i++){
        array_distancias[i] = new int [dimension];
        if(array_distancias[i] == nullptr){
            cerr << "Error en memoria" << endl;
            for(int j=i; j>=0; j--)
              delete [] array_distancias[j];
            delete [] array_distancias;
            array_distancias = nullptr;

            exit(EXIT_FAILURE);
        }
    }

    for(int i=0; i<dimension; i++){
        array_distancias[i][i] = 0;
        for( int j=0; j<dimension; j++)
          if(i != j)
            array_distancias[i][j] = distacia2Puntos(v[i],v[j]);
    }

    return array_distancias;
}


//esta funcion es simplemente de depuracion
int Coste(vector<Point> v, int ** array_distancias){
    int dimension = v.size();
    int coste_aux = 0;

    for(unsigned int i=0; i<dimension-1; i++){
        coste_aux += array_distancias[v[i].posicion_obtencion-1][v[i+1].posicion_obtencion-1];
    }
    coste_aux += array_distancias[v[dimension-1].posicion_obtencion-1][v[0].posicion_obtencion-1];
    
    return coste_aux;
}


int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "Error en parametros: ./insercion_stp input file" << endl;
		return -1;
	}
	vector<Point> v;
	ifstream file(argv[1]);
	string str;
	getline(file, str);
	int dimension = atoi(str.c_str());
	while(getline(file, str)){
		Point auxiliar;
		vector<double> v_auxiliar;
		istringstream is(str);
		double numero;
		while(is >> numero){
			v_auxiliar.push_back(numero);
		}
		auxiliar.posicion_obtencion = v_auxiliar[0];
		auxiliar.x = v_auxiliar[1];
		auxiliar.y = v_auxiliar[2];
		v.push_back(auxiliar);
	}

	//la siguiente funcion es de depuracion unicamente
	int **array_distancias = calculando_array_distancias(v);

	
	vector<Point> circuito_inicial;
	double x_oeste = 10000;
	double x_este = 0;
	double y_norte = -10000;
	int indice = 0;
	for (int i=0; i < v.size(); i++){
		if(v[i].x < x_oeste){
			x_oeste = v[i].x;
			indice = i;
		}
	}
	circuito_inicial.push_back(v[indice]);
	v.erase(v.begin()+indice);
	for (int i=0; i < v.size(); i++){
		if(v[i].x > x_este){
			x_este = v[i].x;
			indice = i;
		}
	}
	circuito_inicial.push_back(v[indice]);
	v.erase(v.begin()+indice);
	for (int i=0; i < v.size(); i++){
		if(v[i].y > y_norte){
			y_norte = v[i].y;
			indice = i;
		}
	}
	circuito_inicial.push_back(v[indice]);
	v.erase(v.begin()+indice);

	int longitud_circuito_inicial = 0;
	//salidaPunto(circuito_inicial[0]);
	//salidaPunto(circuito_inicial[1]);
	//salidaPunto(circuito_inicial[2]);
	longitud_circuito_inicial += distacia2Puntos(circuito_inicial[0], circuito_inicial[1]);
	longitud_circuito_inicial += distacia2Puntos(circuito_inicial[1], circuito_inicial[2]);
	longitud_circuito_inicial += distacia2Puntos(circuito_inicial[2], circuito_inicial[0]);

	//cout << "Longitud circuito_inicial " << longitud_circuito_inicial << endl;
	//cout << "tamano actual vector candidatos" << v.size() << endl; 

	
    high_resolution_clock::time_point tantes, tdespues;
    duration<double> transcurrido;

    tantes = high_resolution_clock::now();
    
    TSP_Insercion(v, circuito_inicial);

    tdespues = high_resolution_clock::now();

    transcurrido = duration_cast<duration<double>>(tdespues - tantes);
    double tiempo = transcurrido.count();

    //las siguientes funciones/operaciones son simplemente de depuracion
    
    int coste = Coste(circuito_inicial, array_distancias);
    /*
    cout << "Tiempo ejecucion: " << tiempo << endl;
    cout << "COSTE CIRCUITO: " << coste << endl;
    cout << "RUTA: " << endl; 
    cout << "[";
    for( int i = 0; i < circuito_inicial.size() - 1; i++){
    	cout << circuito_inicial[i].posicion_obtencion << ", ";
  	}
  	cout << circuito_inicial[circuito_inicial.size()-1].posicion_obtencion << endl;
  	cout << "]" << endl;
  	
  	cout << "DIMENSION: "<< dimension << endl;
  	for( int i = 0; i < circuito_inicial.size(); i++){
    	cout << circuito_inicial[i].posicion_obtencion << " " << circuito_inicial[i].x << " " << circuito_inicial[i].y << endl;
  	}
  	*/
  	cout << dimension << " " << tiempo << endl;

    //t += transcurrido.count();

    for(int i=0; i<dimension; i++)
      delete [] array_distancias[i];
    delete [] array_distancias;
    array_distancias = nullptr;

}