// Guillermo Garcia Patio Lenza
// Grooot

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int resolver(vector<int> & datos);
void optimizaTiempos(vector<int> & datos, int & mejorTiempo,unsigned int empleado, int tiempo);
bool resuelveaso();
int max(vector<int> & datos, int i);

bool resuelveaso() {
    //cout <<"HOLA" << endl;
    //Leer caso de prueba
	unsigned int q;
	int aux;
	cin >> q;
	//cout << q << endl;
    if (q == 0){
        return false;
    }
    else{
    	//Lectura de datos
    	vector<int> datos[q][q];
    	for(unsigned int i = 0; i < q; i++){
    		for(unsigned int j = 0; j < q; j++){
    			cin >> aux;
    			datos[i][j] = aux;
    			//cout << datos[i][j];
    		}
    	}
    	 //Resolver problema
    	    int resultado = resolver(datos);
		//Escribir resultado
    	    cout << resultado << endl;
		return true;
    }
}

int max(vector<int> & datos, int i){
	int tiempo;
	tiempo = datos[i][0];
	for(unsigned int r = 0; r < datos.size(); r++){
		if(tiempo <= datos[i][r]){tiempo = datos[i][r];}
	}
	return tiempo;
}

int resolver(vector<int> & datos){
	int mejorTiempo;
	mejorTiempo = 0;
	for(unsigned int i = 0; i < datos.size(); i++){
		mejorTiempo += max(datos, i);
	}
	//cout << "MEJOR TIEMPO = " << mejorTiempo << endl;
	optimizaTiempos(datos, mejorTiempo, 0, 0);
	return mejorTiempo;

}

void optimizaTiempos(vector<int> & datos, int & mejorTiempo,unsigned int empleado, int tiempo){
	for(unsigned int i = 0; i < datos.size(); i++){
		tiempo =+ datos[empleado][i];
		empleado++;
		if(tiempo >= mejorTiempo){
			tiempo =- datos[empleado][i];
			empleado--;
		}
		else{
			if(empleado == datos.size()){
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
