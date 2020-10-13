/*
 * OrdenacionRec.cpp
 *
 *  Created on: 7 nov. 2019
 *      Author: Guille
 */

#include <iostream>
using namespace std;
const int TAMANO = 100;
typedef int array[TAMANO];
typedef struct{
	array datos;
	int cont;
}tLista;


void lee (tLista & lista);
void copia (tLista & l1, tLista & l2);
void muestra (tLista & l);
void particion(tLista & l, int ini, int final, int & pos);
void quickSort (tLista & l, int ini, int final);
void quickSort (tLista & l);

int main(){
	tLista lista1, lista2;
	lee(lista1);
	muestra(lista1);
	cout << endl;
	//copia(lista1,lista2);
	//muestra(lista1);
	cout << endl;
	//muestra(lista2);
	cout << endl;
	quickSort(lista1);
	//mergeSort(lista2);
	cout << "LISTA 1: (QS)  " << endl;
	muestra(lista1);
	//cout << endl << "LISTA 2: (MS)" << endl;
	//muestra(lista2);
	return 0;
}

void lee (tLista & lista){
	cin >> lista.cont;
	for(int i = 0; i < lista.cont; i++){
		cin >> lista.datos[i];
	}
}

void copia (tLista & l1, tLista & l2){
	l2.cont = l1.cont;
	for(int i = 0; i < l1.cont; i++){
		l2.datos[i] = l1.datos[i];
	}
}

void muestra (tLista & l){
	for(int i = 0; i < l.cont; i++){
		cout << l.datos[i] << " ";
	}
}

void quickSort (tLista & l){
	int q = l.cont-1;
	quickSort(l, 0, q);
}

void quickSort (tLista & l, int ini, int final){
	int p;
	if(ini <= final){
		particion(l, ini, final, p);
		cout << "INI = " << ini << endl;
		cout << "FIN = " << final << endl;
		cout << "P = " << p << endl;
		muestra(l);
		cout << endl;
		quickSort(l, ini, p-1);
		quickSort(l, p+1, final);
	}
}

void particion(tLista & l, int ini, int final, int & pos){
	int i, j, aux;
	i = ini+1;
	j = final;
	while(i <= j){
		if((l.datos[i] > l.datos[ini]) && (l.datos[j] < l.datos[ini])){
			aux = l.datos[i];
			l.datos[i] = l.datos[j];
			l.datos[j] = aux;
			i = i+1;
			j = j-1;
		}
		else{
			if(l.datos[i] <= l.datos[ini]){
				i = i+1;
			}
			if(l.datos[j] >= l.datos[ini]){
				j = j-1;
			}
		}
		muestra(l);
		cout << endl;
	}
	pos = j;
	aux = l.datos[ini];
	l.datos[ini] = l.datos[pos];
	l.datos[pos] = l.datos[ini];
}
