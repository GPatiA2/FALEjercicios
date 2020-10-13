/*
 * mergesort.cpp
 *
 *  Created on: 12 ene. 2020
 *      Author: Guille
 */

#include <iostream>
#include <vector>
using namespace std;


void mergeSort(vector<int> & v, int ini, int fin){
	vector<int>aux(v.size());
	int m;
	if(ini < fin){
		//Copia
		m = (ini+fin) / 2;
		cout << " INI = " << ini << "  FIN = " << fin << "  M = " << m << endl;
		mergeSort(v, ini, m);
		mergeSort(v, m+1, fin);

		//mezcla
		for(unsigned int i = 0; i < v.size(); i++){
			aux[i] = v[i];
		}
		int k = ini;
		int i = ini;
		int j = m+1;
		while(i <= m && j <= fin){
			if(aux[i] <= aux[j]){
				v[k] = aux[i];
				i++;
			}
			else{
				v[k] = aux[j];
				j++;
			}
			k++;
		}
		while(i <= m){
			v[k] = aux[i];
			i++;
			k++;
		}
		while(j <= fin){
			v[k] = aux[j];
			j++;
			k++;
		}

	}
}

int main(){
	int seguir;
	cin >> seguir;

	while(seguir != 0){
		vector<int> v(15);
		for(unsigned int i = 0; i < v.size(); i++){
			cin >> v[i];
		}

		for(unsigned int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
		cout << endl;

		mergeSort(v, 0, v.size()-1);

		for(unsigned int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
		cout << endl;

		cin >> seguir;
	}

	return 0;
}


