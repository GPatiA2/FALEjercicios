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
	for(int i = 0; i < lista.cont ; i++){
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
	//Precondicion : forall t:: 0<= t < lista.cont-1 ==> lista.numeros[t] < lista.numeros[t+1]  (El array se encuentra ordenado crecientemente)
	//Postcondición: forall r:: 0<= r < lista.cont ==> lista.numeros[r] % 2 == 0 && forall q:: 0<= q < lista.cont-1 ==> lista.numeros[q] < lista.numeros[q+1]
	//**(nota)																			(El array se encuentra ordenado crecientemente)
	int i = 0, j = 0, aux;
	while(j < lista.cont) {
		// decreases: lista.cont - j;
		// invariant: 0<= i <= lista.cont && 0<= j <= lista.cont && forall m:: i <= m < j ==> lista.numeros[j] % 2 == 1
		//															Los numeros entre la i y la j son impares
		if( lista.numeros[j] % 2 == 0) {
			aux = lista.numeros[i];
			lista.numeros[i] = lista.numeros[j];
			lista.numeros[j] = aux ;
			i++;
		}
		j++;

	}
	lista.cont = i;
}


/*
 * Análisis del coste:
 *  El tamaño del problema es lista.cont = n , el tamaño del array
 *    El cuerpo del bucle contiene exclusivamente instrucciones de coste constante
 *    	Aplicando la regla de la suma, el cuerpo del bucle tiene coste constante
 *
 *    El bucle siempre se ejecuta un numero n de veces.
 *  	Aplicando entonces la regla del producto, queda que el bucle es de coste n*1 = n
 *
 *   Entonces el algoritmo es de coste lineal en el tamaño del problema.
 *
 *	**Debería escribir que todos los que están a la derecha de lista.cont son impares, pero no sé si debo hacerlo ya que no
 *		tiene sentido hablar de elementos que están más a la derecha del contador de una lista.
 *		También debería escribir que los pares que quedan en el array son los pares que había en el array original.
 *
 */
