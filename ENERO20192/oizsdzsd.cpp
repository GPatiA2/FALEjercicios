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
	int principio;
	if (cifrasllevo == 0){principio = 1;}
	else{principio = 0;}
	for(int i = principio; i < 10; i++){
		suma+=i;
		cifrasllevo++;
		if(suma % cifrasllevo == 0){
			if(cifrasllevo == cifras){
				cont++;
			}
			else{
				vueltaAtras(comienzo, cifras, suma, cont, cifrasllevo);
			}
		}
		suma-= i;
		cifrasllevo--;
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






