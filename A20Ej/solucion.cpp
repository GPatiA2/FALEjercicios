// Guillermo Garcia Patio Lenza
// Grooot

#include <iostream>

#include <fstream>
using namespace std;

const int MF = 10000;
const int MC = 10000;

typedef struct{
	int matriz[MF][MC];
	int fil, col;
}tmatriz;

int resolver(const tmatriz & datos);
void optimizaTiempos(const tmatriz & datos, int & mejorTiempo, int empleado, int tiempo);
bool resuelveaso();
int max(const tmatriz & datos, int i);

bool resuelveaso() {
    cout <<"HOLA" << endl;
    //Leer caso de prueba
	int q;
	cin >> q;
	cout << q << endl;
    if (q == 0){
        return false;
    }
    else{
    	//Lectura de datos
    	tmatriz datos;
    	datos.col = q;
    	datos.fil = q;
    	for(int i = 0; i < datos.col; i++){
    		for(int j = 0; j < datos.fil; j++){
    			cin >> datos.matriz[i][j];
    			cout << datos.matriz[i][j];
    		}
    	}
    	 //Resolver problema
    	    int resultado = resolver(datos);
		//Escribir resultado
    	    cout << resultado << endl;
		return true;
    }
}

int max(const tmatriz & datos, int i){
	int tiempo;
	tiempo = datos.matriz[i][0];
	for(int r = 0; r < datos.col; r++){
		if(tiempo <= datos.matriz[i][r]){tiempo = datos.matriz[i][r];}
	}
	return tiempo;
}

int resolver(const tmatriz & datos){
	int mejorTiempo;
	mejorTiempo = 0;
	for(int i = 0; i < datos.col; i++){
		mejorTiempo += max(datos, i);
	}
	cout << "MEJOR TIEMPO = " << mejorTiempo << endl;
	optimizaTiempos(datos, mejorTiempo, 0, 0);
	return mejorTiempo;

}

void optimizaTiempos(const tmatriz & datos, int & mejorTiempo, int empleado, int tiempo){
	for(int i = 0; i < datos.col; i++){
		tiempo =+ datos.matriz[empleado][i];
		empleado++;
		if(tiempo >= mejorTiempo){
			tiempo =- datos.matriz[empleado][i];
			empleado--;
		}
		else{
			if(empleado == datos.fil){
				mejorTiempo = tiempo;
			}
			else{
				optimizaTiempos(datos, mejorTiempo, empleado, tiempo);
			}
		}
	}
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    //cout <<"HOLA" << endl;
    while (resuelveaso()){
    	//cout << "lsfo" << endl;
    }

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //system("pause");
#endif
    return 0;


}
