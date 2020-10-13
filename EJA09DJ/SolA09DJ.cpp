/*
 * GRUPO MERCADONA
 */


#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

long long int calcular(long long int num);
long long int calculaUnos(long long int num);

bool resuelveCaso() {

    //Leer caso de prueba
	long long int num;
	int sol;
	cin >> num;
    if (!std::cin)
        return false;
    sol = calculaUnos(num);
   // cout << "=========" << endl;
    cout << sol << "\n";
   // cout << "=========" << endl;
    //Resolver problema
    //Escribir resultado
    return true;
}

 int calculaUnos(long long int num){
	return calcular(num);
}

//Análisis del coste del algoritmo
 /*
  * El tamaño del problema es el numero de cifras del numero n
  * El algoritmo reduce el tamaño del problema usando una resta.
  *En el caso peor, se realizan dos llamadas recursivas, por lo que se tomará este caso para analizar el coste
  * La recurrencia que queda es
  * t(2) = c
  * t(n) = 2t(n-1)
  * Aplicando los resultados teoricos queda que (a = 2, b = 1, k = 0) t(n) es cuadrático en el tamaño del problema
  */

long long int calcular(long long int numero){
	if(numero == 0){
		return 1;
	}
	else{
		return 9*calcular((numero/10)-1);
	}
	cout << "__________________________________________________________________________" << endl;
}


int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}












