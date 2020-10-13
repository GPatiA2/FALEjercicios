#include <iostream>
using namespace std;

int main(){
	int huevos;
	int cap;
	int tiempo;
	cin >> huevos;
	cin >> cap;
	while((huevos != 0) && (cap != 0)){
		tiempo = huevos/cap;
		if(huevos%cap != 0){
			tiempo++;
		}
		tiempo = tiempo*10;
		cout << tiempo << "\n";
		cin >> huevos;
		cin >> cap;
	}

}
