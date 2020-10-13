/*
 * sol.cpp
 *
 *  Created on: 13 ene. 2020
 *      Author: Guille
 */
//
#include <iostream>
#include <cmath>
using namespace std;


void resolver(int digitos, int sumaCifras, int digitosLlevo, int sumaActual, int cifraAnterior, long long int & cantidad){
	for(int i = 0; i < 10; i++){
		if(i != cifraAnterior){
			cout << "PRUEBO CON " << i << endl;
			sumaActual += i;
			digitosLlevo++;
			if(digitosLlevo == digitos && sumaActual <= sumaCifras){
				cantidad++;
			}
			else if(sumaActual <= sumaCifras){
				cout << "LLAMO CON " << i << " DIGITOS = " << digitosLlevo << endl;
				resolver(digitos, sumaCifras, digitosLlevo, sumaActual, i, cantidad);
			}
			digitosLlevo--;
			sumaActual -= i;
		}
	}
}


int main(){
	int digitos;
	int cifraIni;
	int sumaCifras;

	int sumaActual = 0;
	int cifraAnterior;
	int digitosLlevo = 0;

	long long int cantidad = 0;

	for(int i = 0; i < 10; i++){cout << i << " ";} cout << endl;

	cin >> digitos;
	while(digitos != -1){
		digitosLlevo = 0;
		cifraIni = 0;
		sumaCifras = 0;
		cifraAnterior = 0;
		sumaActual = 0;
		cantidad = 0;

		cin >> cifraIni;
		cin >> sumaCifras;


		sumaActual += cifraIni;
		cifraAnterior = cifraIni;
		digitosLlevo++;

		cout << "INICIO CON PARAMETROS = " << digitos <<  " " << sumaCifras << " " << digitosLlevo << " "<< sumaActual << " " << cifraAnterior << " " << cantidad << endl;
		resolver(digitos, sumaCifras, digitosLlevo, sumaActual, cifraAnterior, cantidad);

		cout << cantidad;
		cout << endl;

		cin >> digitos;
	}



	return 0;
}
