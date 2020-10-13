/*
 * ej2.cpp
 *
 *  Created on: 23 dic. 2019
 *      Author: Guille
 */




#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool essumdiv(int caso, int numcifras, int & suma, int & dividoPor){
	if(caso == 0 ){
		//cout << "CASO BASE" << endl;
		//cout << "NUMCIFRAS " << numcifras << endl;
		dividoPor = numcifras + 1;
		return true;
	}
	else{
		int ultimaCifra = caso % 10;
		int nextCaso = (caso / 10);
		numcifras++;
		bool sumdiv1 = essumdiv (nextCaso, numcifras, suma, dividoPor);
		suma = suma + ultimaCifra;
		bool sumdiv2 = (suma % (dividoPor - numcifras) == 0);
		return (sumdiv1 && sumdiv2);
		//cout << "SUMA = " << suma << endl;
		//cout << "ULTCIFRA = " << ultimaCifra << endl;
		//cout << "NEXTCASO = " << nextCaso << endl;
		//cout << "DIVIDO POR = " << dividoPor << endl;
		//if(sumdiv2){cout << "SI" << endl;}
		//else{cout << "NO" << endl;}
	}
}


void resolver(int caso){
	bool sumdivisible;
	int suma = 0;
	int numcifras = 0;
	int dividoPor = 0;
	sumdivisible = essumdiv(caso, numcifras, suma, dividoPor);
	if(sumdivisible){cout << "SI" << endl;}
	else{cout << "NO" << endl;}
}

int main(){
	int caso;
	cin >> caso;
	while(caso != 0){
		resolver(caso);
		cin >> caso;
	}

	return 0;
}
