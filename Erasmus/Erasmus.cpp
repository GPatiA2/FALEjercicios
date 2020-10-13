#include <iostream>
using namespace std;

const int TAMANO = 100000;
typedef int estudiantes[TAMANO];
typedef struct{
	estudiantes jugadores;
	long long int cont;
}tPartida;

int main(){
	tPartida partida;
	long long int parejas;
	long long int aux;
	cin >> partida.cont;
	while(partida.cont != 0){
		//lectura de datos
		for(int i = 0; i < partida.cont; i++){
			cin >> partida.jugadores[i];
		}
		//procesamiento de datos
		aux = 0;
		parejas = 0;
		//cout << "CONTADOR = " << partida.cont << endl;
		//cout << "EN " << partida.cont-1 << " HAY UN" <<  partida.jugadores[partida.cont-1] << endl;
		if(partida.cont > 1){
			for(int i = partida.cont-2; i >= 0; i--){
				if ( i == partida.cont-2){
					//cout << partida.jugadores[i] << "  " << partida.jugadores[i-1];
					aux = partida.jugadores[i] + partida.jugadores[i+1];
					parejas = partida.jugadores[i]*partida.jugadores[i+1];
				}
				else{
					parejas = parejas + (aux * partida.jugadores[i]);
					aux = aux + partida.jugadores[i];
				}
				//cout << "I = " << i << endl;
				//cout << "AUX = " << aux << "  PAREJAS = " << parejas << endl;
				//system("PAUSE");
			}
		}
		cout << parejas << "\n";
		cin >> partida.cont;
	}


}


/*
if(partida.cont > 1){
			for(int i = 0; i < partida.cont-1; i++){
				aux = 0;
				for(int j = i+1; j < partida.cont; j++){
					aux = aux + partida.jugadores[j];
				}
				parejas = parejas + aux*partida.jugadores[i];
			}
		}
*/


/*if(partida.cont > 1){
			for(int i = 0; i < partida.cont; i++){
				aux = aux+((partida.jugadores[i]*(partida.jugadores[i]-1)/2));
				numjug = partida.jugadores[i] + numjug;
			}
			parejas = ((numjug*(numjug-1))/2) - aux;
		}
		else if(partida.cont == 1){
			parejas = 0;
		}
*/


/*
		if(partida.cont <= 2 ){
			parejas = partida.jugadores[0] * partida.jugadores[1];
		}
		else{
			for(int i = 0; i < partida.cont; i++){
				aux = 1;
				for(int j = 0; j < partida.cont; j++){
					if(j != i){
						aux = aux*partida.jugadores[j];
						cout << "AUX = " << aux << endl;
					}
				}
				parejas = parejas+ aux;
				cout << "PAREJAS = " << parejas << endl;
			}
		}
		*/
