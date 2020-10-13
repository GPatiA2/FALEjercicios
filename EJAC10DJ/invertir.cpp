/*
 * invertir.cpp
 *
 *  Created on: 12 ene. 2020
 *      Author: Guille
 */
// NOMBRE Y APELLIDOS

#include <iostream>

#include <fstream>
using namespace std;

void invertir(int numero, int potencia, int anterior, bool empezar){
	int cifra;
	cifra = (numero%potencia)/anterior;
	bool primero = (anterior == 1);
//	cout << "CIFRA = " << cifra << endl;
	if(numero/anterior != 0){
		if(primero && cifra != 0){
			cout << cifra;
			empezar = true;
		}
		else if(cifra != 0 && !primero && !empezar){
			cout << cifra;
			empezar = true;
		}
		else if(!primero && empezar){
			cout << cifra;
		}
		invertir(numero, potencia*10, anterior*10, empezar);
	}
}



bool resuelveCaso() {

    //Leer caso de prueba
    int numero;
	cin >> numero;
//	cout << "NUMERO = " << numero << endl;
    if (numero == 0){
        return false;
    }
    else{
    	invertir(numero, 10, 1, false);
    	cout << endl;
    }


    //Resolver problema
    //Escribir resultado
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



