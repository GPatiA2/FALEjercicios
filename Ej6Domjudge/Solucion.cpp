/*
 * Ej6Domjudge.cpp
 *	Guillermo García Patiño Lenza
 *  2A FAL
 *  Grupo Mercadona
 *  Nick Groot
 *
 *
 */

#include <iostream>
#include <fstream>
using namespace std;

const int TAMANO = 10000;
typedef int array[TAMANO];
typedef struct{
	array numeros;
	int cont;
	int ini;
}tLista;


void escribe(tLista & lista);
void lee(tLista & lista);
void resuelve(tLista & lista);

int main(){
	tLista lista;
	cin >> lista.cont;
	while(lista.cont != -1){
		lee(lista);
		resuelve(lista);
		escribe(lista);
		cin >> lista.cont;
	}

}

void escribe(tLista & lista){
	for(int i = lista.ini; i < lista.cont ; i++){
		cout<< lista.numeros[i] << " ";
	}
	cout << endl;
}

void lee(tLista & lista){
	//cout << "He leido el contador, voy a leer cada elemento" << endl;
	for(int i = 0; i < lista.cont; i++){
		cin >> lista.numeros[i];
	}
}

void resuelve(tLista & lista){
	//Precondicion :
	//Postcondición:
	int i = 0, j = 0;
	while(i < lista.cont && j < lista.cont){
		if(lista.numeros[i] % 2 == 0){
			i++;
		}
		else{
			if(lista.numeros[j] % 2 == 0){
				lista.numeros[i] = lista.numeros[j];
			}
		}
		j++;
	}
}


/*
 * Análisis del coste:
 *  El tamaño del problema es lista.cont = n , el tamaño del array
 *    El cuerpo del bucle contiene exclusivamente instrucciones de coste constante
 *    	Aplicando la regla de la suma, el cuerpo del bucle tiene coste constante
 *
 *    El bucle se ejecuta un número variable de veces.
 *    	En el caso peor, el array tiene todos los pares a la derecha y los impares a la izquierda.
 *    	En este caso el bucle se ejecuta n/2 veces, ya que por cada iteración del bucle se ordenan dos elementos, uno en el inicio y otro en el final
 *    	Aplicando entonces la regla del producto, queda que el bucle es de coste n/2*1 = n/2
 *
 *   Entonces el algoritmo es de coste lineal en el tamaño del problema.
 */
