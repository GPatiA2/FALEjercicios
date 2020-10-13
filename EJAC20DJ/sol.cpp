/*
 * sol.cpp
 *
 *  Created on: 29 dic. 2019
 *      Author: Guille
 *
 *      PIEZAS DE COLORES
 */


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef enum bloque {azul, rojo, verde};
const int NUMEROPIEZAS = 3;


void escribirSolucion(vector<bloque> & torre){
	for(unsigned int i = 0; i < torre.size(); i++){
		if(torre[i] == rojo){
			cout << "rojo ";
		}
		else if(torre[i] == azul){
			cout << "azul ";
		}
		else{
			cout << "verde ";
		}
	}
	cout << endl;
}

bool esValida(vector<bloque> const & torre, unsigned int totales, const int puesto[NUMEROPIEZAS], const int piezas[NUMEROPIEZAS]){
	bool valido = false;
	if(torre[totales-1] != verde || torre[totales-2] != verde){
		if(puesto[verde] <= puesto[azul]){
			if(piezas[0] >= 0 && piezas[1] >= 0 && piezas[2] >= 0){
				valido = true;
			}
		}
	}
	return valido;
}

void vueltaAtras(int piezas[NUMEROPIEZAS], vector<bloque> & torre, unsigned int totales, int puesto[NUMEROPIEZAS], bool & posible){
	for(int i = 0; i < NUMEROPIEZAS; i++){
		torre[totales] = bloque(i);
		piezas[i]--;
		puesto[i]++;
		totales++;

//		cout << "ROJAS = " << piezas[0] << endl;
//		cout << "AZUL  = " << piezas[1] << endl;
//		cout << "VERDE = " << piezas[2] << endl;
//
//		for(int i = 0; i < totales; i++){
//			if(torre[i] == 0){
//				cout << "rojo ";
//			}
//			else if(torre[i] == 1){
//				cout << "azul ";
//			}
//			else{
//				cout << "verde ";
//			}
//		}
//
//		cout << endl;

		if(esValida(torre, totales, puesto, piezas)){
			if(totales == torre.size()){
				if(puesto[rojo] > puesto[azul]+puesto[verde]){
					escribirSolucion(torre);
					posible = true;
				}
			}
			else{
				vueltaAtras(piezas, torre, totales, puesto, posible);
			}
		}

		totales--;
		puesto[i]--;
		piezas[i]++;
	}


}


bool resuelveCaso(){
	int tamanio;
	cin >> tamanio;
	if(tamanio == 0){
		return false;
	}
	else{
		int piezas[NUMEROPIEZAS];
		//Lectura de los datos
		for(int i = 0; i < NUMEROPIEZAS; i++){
			cin >> piezas[i];
		}

		//La solucion es un array de un enumerado
		vector<bloque> torre(tamanio);

		//Marcador para ver cuantas piezas llevo y de que color
		int puesto[NUMEROPIEZAS];
		for(int i = 0; i < NUMEROPIEZAS; i++){
			puesto[i] = 0;
		}

		//Para ver cuantas piezas llevo puestas
		unsigned int totales = 0;

		//Para ver si hay solucion
		bool posible = false;

		//Pongo la primera pieza roja
		totales++;
		torre[0] = rojo;
		piezas[rojo]--;
		puesto[rojo]++;

		//Empiezo el algoritmo de vuelta atras
		vueltaAtras(piezas, torre, totales, puesto, posible);

		if(!posible){cout << "SIN SOLUCION" << endl;}

		return true;
	}
}


int main(){

	while(resuelveCaso());

	return 0;
}
