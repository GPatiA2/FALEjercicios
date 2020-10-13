/*
 * Grupo A
 * Guillermo Garcia Patiño Lenza
 *
 */


#include <iostream>

using namespace std;

typedef int asientos[10000];
typedef struct{
	asientos butacas;
	int cont;
}tTaquilla;



int main(){
	int numCasos,q;
	int esperan = 0;
	tTaquilla taquilla;
	taquilla.cont = 0;
	cin >> numCasos;
	for(int i = 0; i < numCasos; i++){
		//Lectura de datos
		cin >> taquilla.cont;
		for(int j = 0; j < taquilla.cont; j++){
			cin >> taquilla.butacas[j];
		}
		//cout << "TAQUILLACONT = " << taquilla.cont << endl;
		//for(int i = 0; i < taquilla.cont; i++){
		//	cout << taquilla.butacas[i] << endl;
		//}

		//cout << "Q = " << q << endl;
		esperan = 0;
		q = taquilla.cont-1;

		while(q >= 0 && taquilla.butacas[q] %2 == 1){
			esperan++;
			q--;
		}
		//Hasta aquí he obtenido los impares seguidos justo al final de la secuencia
		//Ahora busco si hay algun impar más, si no lo hay significa que se abre la puerta
		while(q >= 0 && !(taquilla.butacas[q] % 2 == 1)){
			q--;
		}


		//Salida de datos por la consola
		if( q < 0 ){
			cout << "SI " << taquilla.cont - esperan << "\n";
		}
		else{
			cout << "NO\n";
		}
	}


	return 0;
}

