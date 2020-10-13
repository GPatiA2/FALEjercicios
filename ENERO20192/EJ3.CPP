/*
 * EJ3.CPP
 *
 *  Created on: 23 dic. 2019
 *      Author: Guille
 */


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



void vueltaAtras(int comienzo, int cifras, int & suma, int & cont, int & cifrasllevo){
	for(int i = 0; i < 9; i++){
		cout << i << endl;
	}

}




void resolver(int comienzo, int cifras){
	int suma = 0;
	int cont = 0;
	int cifrasllevo = 0;
	vueltaAtras(comienzo, cifras, suma, cont, cifrasllevo);
	cout << cont << endl;
}


int main(){
	int cifras, comienzo;
	cin >> comienzo;
	while(comienzo != 0){
		cin >> cifras;
		resolver(comienzo, cifras);
		cin >> comienzo;
	}


	return 0;
}






