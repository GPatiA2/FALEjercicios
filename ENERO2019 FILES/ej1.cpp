/*
 * ej1.cpp
 *
 *  Created on: 22 dic. 2019
 *      Author: Guille
 */




#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void resolver(vector<bool> & datos, int cantidad){
	//hayCant = q = 3 && #q : r <= q < s : v[q] = true;
	//Invariante: 0 <= j <= tamanio && p = min r,s: 0<= r <= s < j <= tamanio && hayCant(r,s,cantidad)
	int r = 0;
	int p = 0;
	int q = 0;
	int j = 0;
	while( q < cantidad && j < datos.size()){
		if(datos[j] == 1){
			q++;
		}
		j++;
	}
	if( q  == cantidad){
		cout << "PRIMER SEGMENTO DESDE " << r << " HASTA " << j << endl;
		p = j - r  ;
		cout << "DE LONGITUD " << p << endl;
		cout << "HAY " << q << " TRUES" << endl;

		while(j < datos.size()){
			if(datos[j]){
				j++;
				q++;
				while(q > cantidad){
					if(datos[r]){
						q--;
					}
					r++;
				}
				while(!datos[r]){
					r++;
				}
				if(j - r < p){
					p = j - r;
				}
			}
			j++;
		}
		cout << p << endl;
	}
	else{
		cout << j+1 << endl;
	}




}

void leer(vector<bool> & datos, int tamanio){
	int aux;
	for(int i = 0; i < datos.size(); i++){
		cin >> aux;
		datos[i] = aux;
	}

	for(int i = 0; i < tamanio; i++){
		cout << datos[i];
	}
	cout << endl;
}

int main(){
	int tamanio;
	int cantidad;
	cin >> tamanio;
	while(tamanio != -1){
		vector<bool> datos(tamanio);
		leer(datos, tamanio);
		cin >> cantidad;
		resolver(datos, cantidad);
		cin >> tamanio;
	}

}

/*
 * if(!datos[j]){

		}
		else{
			cout << "HAY OTRO TRUE EN " << j << endl;
			cout << "MI NUEVO SEGMENTO ES DE " << j - r - 1 << " ELEMENTOS" << endl;
			cout << " J  = " << j << endl;
			cout << " R  = " << r << endl;

			if(j - r - 1  < p){
				p  = j - r - 1;
			}
		}
		j++;
 */
