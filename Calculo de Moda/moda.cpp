/*
 * moda.cpp
 *
 *  Created on: 10 ene. 2020
 *      Author: Guille
 */

#include <iostream>
#include <vector>
using namespace std;

int moda(const vector<int> & v){
	int frecMax = 1;
	int frec = 1;
	for(unsigned int i = 1; i < v.size(); i++){
		if(v[i] == v[i-1]){
			if(frecMax == frec){
				frecMax++;
				frec++;
			}
			else if (frec < frecMax){
				frec++;
			}
		}
		else{
			frec = 1;
		}

	}
	return frecMax;
}


int main(){


	int vmoda = 0;

	int tamanio;
	cin >> tamanio;
	vector<int> v(tamanio);
	for(int i = 0; i < tamanio; i++){
		cin >> v[i];
	}
	cout << "EL VECTOR ES" << endl;
	for(int i = 0; i < tamanio ; i++){
		cout << v[i];
	}
	cout << endl;
	cout << "LA MODA ES" << endl;
	vmoda = moda(v);
	cout << vmoda << endl;




	return 0;
}


