#include <iostream>
using namespace std;

const int TAMANO = 100000;
typedef int alturas[TAMANO];
typedef struct{
	alturas montanas;
	int cont;
}tCordillera;

int main(){
	tCordillera lista;
	int ultmaximo = 0;
	int cumplen = 0;
	cin >> lista.cont;
	while(lista.cont != 0){
		ultmaximo = 0;
		cumplen = 0;
		for(int i = 0; i < lista.cont; i++){
		cin >> lista.montanas[i];
		}
		for(int j = lista.cont-1; j >= 0; j--){
			//cout << "J = " << j << endl;
			if((j <= lista.cont) && (lista.montanas[j] > ultmaximo)){

				ultmaximo = lista.montanas[j];
				//cout << "Registro " << lista.montanas[j] << endl;
				//cout << "ULTMAXIMO = " << ultmaximo << endl;
				cumplen++;
			}
		}
		cout << cumplen << "\n";
		cin >> lista.cont;
	}

}
