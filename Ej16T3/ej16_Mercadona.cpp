/*
 * ej16.cpp
 * Grupo Mercadona --> Grupo A
 * Ejecicio 16 T3, Misión Pasito a Pasito
 * Mr_TostaRica, Dav16d, Palomitas, Zapi, LaCabraDeLaLegion y Groot
 */

#include <iostream>
#include <fstream>
using namespace std;

const int TAMANO = 1000;
typedef int array[TAMANO];
typedef struct{
	array numeros;
	int cont;
}tLista;

void resuelveCaso();
void resuelve(tLista & lista);

// COMO ENTRADA EL NUMERO DE CASOS DE PRUEBA QUE VAIS A INTRODUCIR
// DESPUES LA LONGITUD DEL ARRAY
// POR ÚLTIMO LOS VALORES DEL ARRAY UNO A UNO


int main(){
	int numcasos;
	cin >> numcasos;
	for(int i = 0; i < numcasos; i++){
		resuelveCaso();
	}

}


void resuelveCaso(){
	tLista lista;
	cin >> lista.cont;
	for(int i = 0; i < lista.cont; i++){
		cin >> lista.numeros[i];
	}
	resuelve(lista);

}

void resuelve(tLista & lista){
	/*
		 * pico(lista.numeros[r], lista.numeros, i) {
		 * 		lista.numeros[r] = (max r: 0 <= r <= i : lista.numeros[r])
		 * }
		 *
		 * Precondición: lista.cont > 0
		 * Postcondición: suma = (Sum s: 0 <= s < lista.cont && pico(lista.numeros[s]) : lista.numeros[s])
		 *
		 */
			int i = 1;
			int suma = lista.numeros[0];
			int max = lista.numeros[0];

			while (i < lista.cont){
				// decreases : lista.cont - i
				// invariant : suma = (Sum k: 0 <= k < i && pico(lista.numeros[k]) : lista.numeros[k]) && max = (max q: 0 <= q < i: lista.numeros[q]) && 1 <= i <= lista.cont
				if(lista.numeros[i] > max){
					suma = suma + lista.numeros[i];
					max = lista.numeros[i];
				}
				i++;
			}


		cout << "Suma = " << suma << endl;
}

/*
 * El tamaño del problema es lista.cont = n, que es el tamaño del vector
 * El coste del cuerpo del bucle está formado por instrucciones de coste constante, así que ,aplicando la regla de la suma, el coste del cuerpo del bucle es constante.
 * En todos los casos el bucle se ejecuta n veces, donde cada vuelta cuesta lo mismo (coste constante). Aplicando la regla del producto queda que el coste del bucle es n*1 = n
 * Las instrucciones exteriores al bucle son de coste constante, así que aplicando la regla de la suma, queda que el algoritmo es de coste lineal en n (el tamaño del problema).
 */
