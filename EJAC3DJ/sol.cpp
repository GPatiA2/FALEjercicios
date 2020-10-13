/*
 * sol.cpp
 *
 *  Created on: 11 ene. 2020
 *      Author: Guille
 */

//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void resuelveCaso() {
	int longitud;
	int tpte;
	cin >> longitud;
	cin >> tpte;
	vector<int> v(longitud);
	for(unsigned int i = 0; i < v.size(); i++){
		cin >> v[i];
	}
		unsigned int tamanio = 0;
		unsigned int iniOK = 0;
		unsigned int ini = 0;
		for(unsigned int i = 1; i < v.size(); i++){
	//		cout << "INI = " << ini << " FIN = " << i << " TAMANIO = " << tamanio << endl;
			if((tamanio < i - ini) && v[i] > tpte && v[ini] > tpte){
				tamanio++;
				if(ini > iniOK)
					iniOK = ini;
			}
			else if((v[i] <= tpte || v[ini] <= tpte)){
				ini = i;
			}
		}
		cout << iniOK << " " << iniOK+tamanio << endl;
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


//unsigned int iniaux = 0;
//	unsigned int ini = 0;
//	unsigned int fin = 1;
//	for(unsigned int i = 1; i < v.size(); i++){
//		cout << "INI = " << ini << " FIN = " << fin << endl;
//		cout << "AUX = " << iniaux << " I = " << i << endl;
//		cout << endl;
//			if(((i - iniaux) > (fin - ini)) && v[i] > tpte){
//				fin = i;
//				ini = iniaux;
//			}
//			else if(v[i] <= tpte){
//				iniaux = i;
//			}
//	}
//	cout << ini << " " << fin << endl;



////resuelve aqui tu caso
//    //Lee los datos
//
//    //Calcula el resultado
////	cout << "CASO DE LONGITUD " << longitud << " y TRANSPORTE " << tpte << endl;
//	unsigned int tamanio = 0;
//	unsigned int iniOK = 0;
//	unsigned int ini = 0;
//	for(unsigned int i = 1; i < v.size(); i++){
////		cout << "INI = " << ini << " FIN = " << i << " TAMANIO = " << tamanio << endl;
//		if((tamanio < i - ini) && v[i] > tpte && v[ini] > tpte){
//			tamanio++;
////			if(iniOK > ini)
////				iniOK = ini;
//		}
//		else if((v[i] <= tpte || v[ini] <= tpte)){
//			ini = i;
//		}
//	}
//	cout << iniOK << " " << iniOK+tamanio << endl;
//    //Escribe el resultado

