/*
 *
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

const int TAMANO = 1000;
typedef int numeros[TAMANO];
typedef struct{
	numeros cifras;
	int cont;
}tLista;

void sumdigs(int num);
void sumadigitos(int & num, int & suma);

int main(){
	int num;
	cin >> num;
	while(num != -1){
		sumdigs(num);
		cin >> num;
	}
}

void sumdigs(int num){

	int suma = 0;
	sumadigitos(num, suma);
	cout << "SUMA = " << suma;
}

void sumadigitos(int & num, int & suma){
	if(num < 10){
		suma = suma+num;
		cout << num << " + ";
	}
	else{
		suma = suma + (num % 10);
		cout << "SUMA = " << suma << endl;
		num = num / 10;
		cout << "NUM = " << num << endl;
		cout << num/10 << " + ";
		sumadigitos(num, suma);

	}



}
