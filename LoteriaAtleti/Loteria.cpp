/*
 * GRUPO A
 * Guillermo Garcia Patiño Lenza
 */

#include <iostream>

#include <fstream>
using namespace std;

typedef int array[10000];
typedef struct{
	array numeros;
	int cont;
}tdecimos;




/*
 * Analisis de coste:
 * 	El tamaño del problema es decimos.cont , es decir, en la longitud del array de numeros
 * 	El coste de este algoritmo es lineal, ya que en cada una de las decimo.cont vueltas del bucle se ejecutan instrucciones de coste lineal
 * 		Aplicando la regla de la suma, el coste del cuerpo del bucle es constante (1)
 * 		Aplicando la regla del producto, el coste del bucle es n*1
 *


*/


int main() {
	int numCasos = 0;
	tdecimos decimos;
	int pares = 0;
	cin >> numCasos;
	for( int q = 0; q < numCasos; q++){
		cin >> decimos.cont;
		pares = 0;
		for(int i = 0; i < decimos.cont; i++){
			cin >> decimos.numeros[i];
		}
		//Resolver problema
		for(int i = 0; i < decimos.cont; i++){
			if (decimos.numeros[i] % 2 == 0){
				pares++;
			}
		}
		//Escribir resultado
		cout << pares << "\n";
	}
    return 0;
}

