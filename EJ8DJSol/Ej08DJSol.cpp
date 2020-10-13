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

const int TAMANO = 40000;
typedef int array[TAMANO];
typedef struct{
	array numeros;
	int cont;
}tLista;


void escribe(tLista & lista);
void lee(tLista & lista);
int resuelve(tLista & lista);

int main(){
	tLista lista;
	int max;
	int casos, q = 0;
	cin >> casos;
	while(q < casos){
		lee(lista);
		max = resuelve(lista);
		cout << max << "\n";
		q++;
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
	cin >> lista.cont;
	for(int i = 0; i < lista.cont; i++){
		cin >> lista.numeros[i];
	}
}

int resuelve(tLista & lista){
	//Precondicion : forall r:: 0<= r < lista.cont ==> 0 <= lista.numeros[r] < 4000
	//Postcondición: max = max p,q: 0<= p <= q <= lista.cont && forall t:: p <= t < q-1 ==> lista.numeros[t] < lista.numeros[t+1] : q - p
	int i = 1;
	int max = 0;
	int larg = 1;
	while(i < lista.cont){
		//decreases lista.cont - i
		//invariant: max = max p,q: 0<= p <= q <= i && forall t:: p <= t < q-1 ==> lista.numeros[t] < lista.numeros[t+1] : q - p && 0 <= i <= lista.cont
		if(lista.numeros[i] <= lista.numeros[i-1]){
			larg++;
		}
		else{
			larg = 1;
		}
		max = std::max(larg,max);
		//cout << "I = " << i << " L = " << larg << " M = " << max << endl;
		i++;
	}
	return max;
}


/*
 * Análisis del Coste:
 * 	El tamaño del problema es n = lista.cont , el número de elementos del array
 * 	Las instrucciones del cuerpo del bucle son todas de coste constante, así que por la regla de la suma, el coste del bucle es constante
 * 	En el caso peor, el bucle se ejecuta n veces, siendo todas las vueltas del mismo coste. Aplicando la regla del producto, queda que el coste del bucle es n*1 = n
 * 	Como las instrucciones de fuera del bucle son también de coste constante, aplicando la regla de la suma, queda que el algoritmo es lineal en el tamaño del problema.
 */
