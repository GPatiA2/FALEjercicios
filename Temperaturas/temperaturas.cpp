//Guillermo Garcia Patiño Lenza
//Grupo A


#include <iostream>
#include <fstream>
using namespace std;

const int TAMANO = 10000;
typedef int temperaturas[TAMANO];
typedef struct{
	temperaturas temps;
	int cont;
}tLista;
typedef enum {CRECE, DECRECE, NADA}tRelacion;


void resuelveCaso() {
 //resuelve aqui tu caso
   //Lectura de datos
	tLista lista;
	cin >> lista.cont;
	for(int i = 0; i < lista.cont; i++){
		cin >> lista.temps[i];
	}
	/*for(int i = 0; i < lista.cont ; i++){
		cout << lista.temps[i] << " ";
	}*/
	//cout << endl;
	//Procesamiento de datos
	int picos, valles;
	tRelacion relacion, relprev;
	relacion = NADA;
	picos = 0;
	valles = 0;
	relacion = NADA;
	for(int j = 0; j < lista.cont-1; j++){
		relprev = relacion;
		if(lista.temps[j] < lista.temps[j+1]){
			relacion = CRECE;
		}
		else if(lista.temps[j] > lista.temps[j+1]){
			relacion = DECRECE;
		}
		else if(lista.temps[j] == lista.temps[j+1]){
			relacion = NADA;
		}
		//cout << "J = " << j << " RELACION = " << relacion << " RELPREV = " << relprev << endl;
		if((relacion != NADA) && (relprev != NADA)){
			if((relacion == CRECE) && (relprev == DECRECE)){
				valles++;
			}
			else if((relacion == DECRECE) && (relprev == CRECE)){
				picos++;
			}
		}
	}
	//Salida de datos por la consola
	cout << picos << " " << valles << "\n";
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

/* Analisis de eficiencia:
 * 	El tamaño del problema es la longitud del array = lista.cont
 * 	El caso mejor es igual al caso peor, ya que voy a recorrer el array entero igualmente
 * 	El orden exacto del cuerpo del bucle es constante ya que solo se ejecutan asignaciones, evaluacion de booleanos y operaciones aritmeticas
 * 	En ambos casos voy a dar un numero de vueltas que va a provocar que el coste del bucle sea del orden exacto de n*1
 * 	Las instrucciones externas al bucle son todas de orden exacto constante.
 * 	Aplicando la regla del producto, el orden exacto del algoritmo que uso en este problema es lineal.
 */



/*
 * i = lista.cont-1-j;
		mayor = (lista.temps[i] > lista.temps[i-1]) || mayor;
		menor = (lista.temps[i] < lista.temps[i-1]) || menor;
		if(menor){
			relacion = PICO;
		}
		else if(mayor){
			relacion = VALLE;
		}
		else{
			relacion = NADA;
		}
		if(j+1 % 2 == 0){
			if(relacion == NADA || !menor || !mayor){
				menor = false;
				mayor = false;
			}
			else if(mayor && menor){
				if(relacion == PICO){
					picos++;
				}
				else if(relacion == VALLE){
					valles++;
				}
				relacion = NADA;
			}
		}
 */


/*if(lista.temps[1] < lista.temps[0]){
		relacion = DECRECE;
	}
	else if(lista.temps[1] > lista.temps[0]){
		relacion = CRECE;
	}
	else if(lista.temps[1] == lista.temps[0]){
		relacion = NADA;
	}
	*/
