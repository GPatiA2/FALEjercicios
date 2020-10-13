/*
 * Grupo Mercadona
 * Generador de Casos de prueba
 */

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

const int NUMCASOS = 100;

string generaCaso(){
	string devolver;



	int longitud = (rand() % 10)+1; //La longitud va de 0 a 50
	int colores = (rand() % 10)+1; //De 0 a 10 colores posibles
	int consumoMax = (rand() % 10)+1; //Consumo maximo va de 0 a 30;

	devolver.append(to_string(longitud));
	devolver.append(" ");
	devolver.append(to_string(colores));
	devolver.append(" ");
	devolver.append(to_string(consumoMax));
	devolver.append("\n");

	int consumoTipo;
	//Bucle de generacion de cantidad de bombillas
	for(int i = 0; i < colores; i++){
		consumoTipo = (rand() % 10)+1; //Consumo de cada tipo entre 0 y 10
		devolver.append(to_string(consumoTipo));
		devolver.append(" ");
	}

	return devolver;
}

int main(){
	string casos;
	for(int i = 0; i < NUMCASOS; i++){
		//Si quereis que cada vez que ejecuteis el programa se generen los mismos casos, cambiar time(NULL) por un numero que querais.
		//Como va por tiempo, si ejecutais muchas veces el programa os saldrá algo parecido, para evitar eso podeis multiplicar lo
		// que hay dentro del srand por i, por ejemplo.
		srand(200*100*(time(NULL) + i));
		casos.append(generaCaso());
		casos.append("\n");
	}
	casos.append("0");
	cout << casos;

	ofstream fichero;
	fichero.open("casos.txt");
	fichero << casos;
	fichero.close();
}



