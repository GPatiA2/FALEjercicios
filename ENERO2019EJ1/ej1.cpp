/*
 * ej1.cpp
 *
 *  Created on: 22 dic. 2019
 *      Author: Guille
 */




#include <iostream>
#include <fstream>
#include <vector>
using namespace std;




void resolver (vector<bool> & datos, int cantidad){
	unsigned int ini = 0;
	unsigned int fin = 0;
	int trues = 0;
	unsigned int tamanio = datos.size() + 1;

	while(fin < datos.size()){ //Hasta que fin llegue al final
		while(trues != cantidad && fin < datos.size()){ //Si no tengo los trues que quiero
			if(datos[fin]){ //Si el fin se encuentra con un true
				trues++; //Añado un true
			}
			fin++; //Avanzo el fin
		}
		//if(trues == cantidad){tamanio = min(tamanio, fin-ini);} //Si he encontrado un segmento que me vale, actualizo la longitud

		//Ahora, para ese segmento que acabo de encontrar, voy a ver hasta donde lo puedo acortar
		while(!datos[ini] && ini < fin){ //Mientras que el ini no se tope con un true y se mantenga por detras del fin (aunque cuando se encuentre con el fin sera o porque hay un true o porque es el final)
			ini++; //Aumentar ini
		}
		if(trues == cantidad){
			tamanio = min(tamanio, fin-ini);
			ini++;
			trues--;
		} //Si mantengo los trues que quiero (cosa que deberia porque al ini no le dejo empezar esa busqueda en true)
		//Ahora avanzo el ini hasta que encuentre un false, restando los trues que se va encontrando

	}
	cout << tamanio << endl;
}

void leer(vector<bool> & datos, int tamanio){
	int aux;
	for(unsigned int i = 0; i < datos.size(); i++){
		cin >> aux;
		datos[i] = aux;
	}

	//for(int i = 0; i < tamanio; i++){
	//	cout << datos[i];
	//}
	//cout << endl;
}

int main(){
	int tamanio;
	int cantidad;
	cin >> tamanio;
	while(tamanio != -1){
		vector<bool> datos(tamanio);
		leer(datos, tamanio);
		cin >> cantidad;
		resolver(datos, cantidad);
		cin >> tamanio;
	}

}

