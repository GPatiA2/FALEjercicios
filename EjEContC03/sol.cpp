/*
 * sol.cpp
 *
 *  Created on: 21 nov. 2019
 *      Author: Guille
 */

//Guillermo Garcia Patiño Lenza
//Grooot 2ºA FAL


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int TAMANO = 10000000;
typedef int array[TAMANO];
typedef struct{
	array datos;
	int cont;
}tLista;

int resuelve (tLista const& q);
int diferente(tLista const& v, int ini, int fin);
void resuelveCaso();

void resuelveCaso() {
 //resuelve aqui tu caso
	tLista v;
	cin >> v.cont;
	for(int i = 0; i < v.cont; i++){cin >> v.datos[i];}
	//for(int i = 0; i < numelems; i++){cout << v[i] << " ";}
	//cout << endl;
	cout << "_____________________________________________" << endl;
	int q = resuelve(v);
	cout << q << "\n";
	cout << "_____________________________________________" << endl;
    //Lee los datos
    //Calcula el resultado
    //Escribe el resultado
}

int resuelve (tLista const& q){
	 return diferente(q, 0, q.cont);
}

int diferente(tLista const& v, int ini, int fin){
	int pos;
	int excluyo;
	int m = (ini+fin)/2;
	if(fin-ini <= 1){
		pos = ini;
	}
	else{
		if(v.datos[m] != v.datos[m+1] && v.datos[m-1] != v.datos[m]){
			pos = m;
		}
		else{
			if(v.datos[m] == v.datos[m+1]){
				excluyo = m+1;
				if((fin - (excluyo+1)) % 2 == 1){
					pos = diferente(v, excluyo+1, fin);
				}
				else{
					pos = diferente(v, ini, m);
				}
			}
			if(v.datos[m] == v.datos[m-1]){
				excluyo = m-1;
				if((excluyo-ini) % 2 == 1){
					pos = diferente(v, ini, excluyo-1);
				}
				else{
					pos = diferente(v, m+1, fin);
				}
			}
		}
	}
	return pos;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    int numCasos;
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


