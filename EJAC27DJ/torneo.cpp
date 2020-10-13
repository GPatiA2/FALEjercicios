/*
 * torneo.cpp
 *
 *  Created on: 3 ene. 2020
 *      Author: Guille
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


bool torneo(const vector<string> & jugadores, int ronda, int & partidos, int & actual, int ini, int fin, int tamanio, int ultimoTamanio){
	if(fin - ini == 0){
		return false;
	}
	else if(fin - ini ==  2){
		//cout << "LLAMADA DE TAMANIO 2" << endl;
		if(jugadores[ini] != "NP" && jugadores[ini+1] != "NP"){
			//cout << "HAY PARTIDO" << endl;
			partidos++;
			return true;
		}
		else if(jugadores[ini] != "NP" || jugadores[ini+1] != "NP"){return true;}
		else{return false;}
	}
	else{
		//cout << "LLAMADA DE TAMANIO " << tamanio << endl;
		int m = (((fin-ini)/2))+ini;
		//cout << "VOY A LLAMAR CON INI =" << ini << " M = " << m << " FIN = " << fin << endl;
		//system("PAUSE");
		bool m1 = torneo(jugadores, ronda, partidos, actual, ini, m, tamanio/2, ultimoTamanio);
		bool m2 = torneo(jugadores, ronda, partidos, actual, m, fin, tamanio/2, ultimoTamanio);
		//cout << "LLAMADA DE TAMANIO " << tamanio << endl;
		if( tamanio > ultimoTamanio ){
			return false;
		}
		else{
			if(m1 && m2){
				//cout << "HAY PARTIDO" << endl;
				partidos++; return true;
			}
			else if(m1 || m2){return true;}
			else{return false;}
		}
	}
}

bool resuelveCaso() {

    //Leer caso de prueba
	//cout << "COMIENZA UN CASO" << endl;
	int tamanio;
	cin >> tamanio;
    if (!std::cin){ return false;}
    else{
		int ronda;
		cin >> ronda;
		//cout << "TAMANIO = " <<tamanio << " RONDA = " << ronda << endl;
		vector<string> jugadores(tamanio);
		for(int i = 0; i < tamanio; i++){
			cin >> jugadores[i];
		}

		int actual = 0;
		int partidos = 0;
		int ultimoTamanio = pow(2, ronda);
		torneo(jugadores, ronda, partidos, actual, 0, tamanio, tamanio, ultimoTamanio);
		cout << partidos << endl;
		//Resolver problema
		//Escribir resultado
		return true;
    }
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;
}
