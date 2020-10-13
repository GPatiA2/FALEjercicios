/*
 * particion.cpp
 *
 *  Created on: 11 ene. 2020
 *      Author: Guille
 */

#include <iostream>
#include <vector>
using namespace std;


void particion (vector<int> & v, unsigned int ini, unsigned int fin, unsigned int & p){
	int i, j;
	int aux;
	i = ini+1;
	j = fin;
	while(i <= j){
		if(v[i] > v[ini] && v[j] < v[ini]){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
		else{
			if(v[i] <= v[ini]) {i++;}
			if(v[j] >= v[ini]) {j--;}
		}
	}
	aux = v[ini];
	v[ini] = v[j];
	v[j] = aux;
	p = j;
//	cout << i << endl;
//	cout << j << endl;
}

void quickSort(vector<int> & v, int a, int b){
	unsigned int p;
	if(a <= b){
		particion(v, a, b, p);
		quickSort(v, a, p-1);
		quickSort(v, p+1, b);
	}
}

int main(){
	vector<int> v(15);
	int seguir;
	cin >> seguir;
	while(seguir != 0){
		for(unsigned int i = 0; i < v.size(); i++){
			cin >> v[i];
		}
		for(unsigned int i = 0; i < v.size(); i++){
			cout << v[i]<< " ";
		}
		cout << endl;
		quickSort(v, 0, v.size()-1);
		for(unsigned int i = 0; i < v.size(); i++){
			cout << v[i] << " ";
		}
		cout << endl;
		cin >> seguir;
	}

	return 0;
}


