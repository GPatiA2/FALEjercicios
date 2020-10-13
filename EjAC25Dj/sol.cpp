//Guillermo Garcia Patinio Lenza
//Nick grooot


#include <iostream>
#include <fstream>
using namespace std;

const int MF = 25;
const int MC = 25;
const int MP = 30;
const int MS = 30;



typedef int super[MS];
typedef struct{
	super sitios;
	int cont;
}tMarcador2;

typedef bool marcas[MP];
typedef struct{
	marcas productos;
	int cont;
}tMarcador;

typedef struct{
	int matriz[MF][MC];
	int fil, col;

}tmatriz;

int maxPrecio(const tmatriz & datos, int j);

void optimizaPrecio(const tmatriz & datos, int & mejorPrecio, tMarcador2 & marcasSuper, int & precio, int & col){
	//cout << "COMPRANDO EL PRODUCTO " << col << endl;
	//system("PAUSE");
	for(int i = 0; i < datos.fil; i++){
		//cout << "Compro en el super " << i << endl;
		//cout << "Llevo " << col << " productos" << endl;
		//cout << "En ese super llevo comprados " << marcasSuper.sitios[i] << " productos" << endl;
		//cout << "Y llevo un precio de " << precio << endl;
		//system("PAUSE");
		//Meto el primer producto en la cesta, cuento un producto para ese supermercado y anoto que ya tengo ese producto
		precio = precio + datos.matriz[i][col];
		marcasSuper.sitios[i]++;
		if(precio < mejorPrecio && marcasSuper.sitios[i] <= 3 && precio /*< preciocalc(datos,col,i)*/){
			//Si la solucion es valida
			if(col == datos.col-1){
				//cout << "COL = " << col << endl;
				//cout << "La solucion tiene de precio " << precio << endl;
				//cout << "Hasta ahora llevaba un mejor precio de " << mejorPrecio << endl;
				//system("PAUSE");
				//Si es el ultimo producto que meto en la cesta
				if(mejorPrecio > precio){
					//Si tengo un precio mejor, actualizo el precio
					mejorPrecio = precio;
				}
				marcasSuper.sitios[i]--;
				precio = precio - datos.matriz[i][col];
			}
			else{
				//Si no es el ultimo producto que meto
				//Voy a meter el siguiente producto
				col = col+1;
				optimizaPrecio(datos,mejorPrecio, marcasSuper, precio, col);
				//Desmarco y saco el producto de la cesta
				marcasSuper.sitios[i]--;
				col--;
				precio = precio - datos.matriz[i][col];
			}
		}
		else{
			//Si la solucion no es valida, saco el producto de la cesta y me voy a otro sitio a comprarlo
			marcasSuper.sitios[i]--;
			precio = precio - datos.matriz[i][col];
		}
	}
}

void resuelve(const tmatriz & datos, int & mejorPrecio, tMarcador2 & marcasSuper){
	int precio = 0;
	int col = 0;
	optimizaPrecio(datos, mejorPrecio, marcasSuper, precio, col);
}


void leer(tmatriz & datos){
	cin >> datos.fil;
	cin >> datos.col;
	for(int i = 0; i < datos.fil; i ++){
		for(int j = 0; j < datos.col; j++){
			cin >> datos.matriz[i][j];
		}
	}
}

void resuelveCaso() {
 //resuelve aqui tu caso

	tmatriz datos;
    leer(datos);

    tMarcador2 marcasSuper;
    marcasSuper.cont = datos.fil;
   // cout << "En este caso hay " << marcasSuper.cont << " supermercados" << endl;
    for(int i = 0; i < marcasSuper.cont; i++){
    	marcasSuper.sitios[i] = 0;
    }

    int mejorPrecio = 0;
    for (int j = 0; j < datos.col; j++){
    	mejorPrecio = mejorPrecio + maxPrecio(datos, j);
    }
    cout << "La cota que utilizo para la poda de optimalidad es " << mejorPrecio << endl;

    resuelve(datos, mejorPrecio, marcasSuper);

    //Escribe el resultado
    if(mejorPrecio == 0){
    	cout << "Sin solucion factible" << endl;
    }
    else{
    	cout << mejorPrecio << endl;
    }
}

int maxPrecio(const tmatriz & datos, int j){
	int max = 0;
	for(int q = 0; q < datos.fil; q++){
		if(max < datos.matriz[q][j]){
			max = datos.matriz[q][j];
		}
	}
	return max;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (unsigned int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
