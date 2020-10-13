
//#include "pch.h"


// Palomitas

/*
				Mi tio se dedica a la fabricacion de luces de Navidad. Cuando era pequeno me llevaba con el a la fabrica, donde se podıan ver rollos
			y rollos de luces de colores, para adornar los arboles y las fachadas de las casas. Durante muchos anos ha detectado que unas tiras se
			venden mas que otras. Para analizar el motivo, ha realizado un estudio de mercado con el que han detectado que a la gente no le importa
			realmente el color concreto de cada bombilla, sino que el aspecto total	tenga bastante colorido. Por ello ha decidido hacer las tiras de
			luces de forma que no haya mas de dos luces seguidas del mismo color y que se cumpla que en cualquier punto de la tira la suma de las
			luces de un color no supere en mas de una unidad la suma de las luces de todos los demas colores. Ademas se debe tener en cuenta que las 
			tiras de luces no deben consumir mas de una cierta cantidad de energıa para cumplir con la legislacion sobre el medio ambiente.
			Ahora quiere saber cuantas posibles tiras puede hacer de una determinada longitud dado un numero maximo de bombillas de cada tipo y un 
			consuma maximo para la tira. Para poder seleccionar las tiras adecuadas cuenta con el consumo de cada tipo de bombilla.

*/

/*                   PODA PRIMERA
				Esta primera poda consiste en comparar la sumaActual de consumo que llevas hasta el elemento k de soluciones posibles con el cosumoMaximo
			permitido. Para ello hacemos uso de una suma estimada que corresponde a la suma de sumaActual mas el producto del minimo consumo de una bobilla
			y las bombillas que quedan por colocar. Si la sumaEstimada fuera menor o igual al consumoMax seguimos colocando bombillas, si no podamos.

*/


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(const vector<int> & LucesSol, const int & k, const vector<int> & sumaLuces, const int & consumoActual, const int & minimo, const int & consumoMax) {
	if (k == 0){
		return true;		
    }
	else if(consumoActual+(LucesSol.size()-1-k)*minimo <= consumoMax) {
		if ((LucesSol[k - 1] != LucesSol[k])||(k<2)||((LucesSol[k -2] != LucesSol[k]))) {
			
			
			return k-sumaLuces[LucesSol[k]]+2>= sumaLuces[LucesSol[k]];
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int LucesNavidad(const vector<int> & Tira, const int & longitud, const int &consumoMax,int k,vector<int> & LucesSol,
	int  & consumoActual, vector<int> & sumaLuces, const int & minimo) {
	int resultado = 0;
	int i = 0;
	while ( i<Tira.size()) {

		LucesSol[k] = i;   //marco
		consumoActual += Tira[i];
		sumaLuces[i] ++;
		if (esValida(LucesSol,k, sumaLuces,consumoActual,minimo, consumoMax)) {
			if (k == longitud - 1) {
				resultado++;				
			}
			else {
				resultado += LucesNavidad(Tira, longitud, consumoMax, k + 1,LucesSol,consumoActual,sumaLuces,minimo);
			}
		}

		LucesSol[k] = i;  //desmarco
		consumoActual -= Tira[i];
		sumaLuces[i] --;
		i++;
	}
	return resultado;
}



bool resuelveCaso() {

	int longitud;	cin >> longitud;
	if (longitud == 0) {
		return false;
	}
	else {
		int Colores;    cin >> Colores;
		int consumoMax; cin >> consumoMax;
		vector<int> Tira(Colores);
		vector<int> LucesSol(longitud);
		vector<int> sumaLuces(Colores);

		int minimo = 99999;
		for (int i = 0; i < Colores; i++) {
			cin >> Tira[i];
			if (Tira[i] < minimo) {
				minimo = Tira[i];
			}
		}
		bool existe = false;
		int ConsumoAtual = 0;
		cout << LucesNavidad(Tira, longitud, consumoMax, 0, LucesSol, ConsumoAtual, sumaLuces, minimo) << endl;
	}
	
	
	return true;
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
	system("pause");
#endif
	return 0;
}