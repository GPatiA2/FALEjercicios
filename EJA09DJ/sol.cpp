/*
 * Grupo Mercadona
 * Nicks: Grooot, LaCabraDeLaLegion, Palomitas, Mr_TostaRica, Dav16d, Zapi
 * Ejercicio A09
 */
/*
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int calcular(int num, int potencia10, int potencia9);
int calculaUnos(int num);

bool resuelveCaso() {

    //Leer caso de prueba
	int num;
	int sol;
	cin >> num;
    if (!std::cin)
        return false;
    sol = calculaUnos(num);
    cout << "=========" << endl;
    cout << sol << "\n";
    cout << "=========" << endl;
    //Resolver problema
    //Escribir resultado
    return true;
}

int calculaUnos(int num){
	return calcular(num, 1, 1);
}

int calcular(int numero, int potencia10, int potencia9){
	int potencia = potencia10;
	int dig_izq;
	int dig_der;
	int true_resto;
	int resto;
	int num2;
	cout << "_____________________________________________________________________" << endl;
	cout << "NUMERO = " << numero << endl;
	cout << "POTENCIA10 = " << potencia10 << endl;
	cout << "NUMERO / POTENCIA " << numero/potencia10 << endl;
	dig_izq = numero / potencia10;
	cout << "DIGIZQ = " << dig_izq << endl;

	if(dig_izq == 1){
		cout << "NUMERO / POTENCIA < 10" << endl;
		cout << "DEVUELVO = " << potencia9 << endl;
		return potencia9;
	}
	else if(dig_izq == 0){
		cout << "DEVUELVO 0" << endl;
		return 0;
	}
	else if(dig_izq > 1){
		if(dig_izq < 10){
			cout << " DEVUELVO = " << potencia9 << " * " << (dig_izq-1)<< " = " << potencia9 * (dig_izq-1) << endl;
			return potencia9 * (dig_izq -1);
		}
		else{
			dig_der = numero % potencia10;
			cout << "DIGDER = " << dig_der << endl;
			potencia10 *= 10;
			resto = (numero / potencia10) * potencia10;
			cout << "RESTO = " << resto << endl;
			true_resto = resto/potencia10;
			num2 = numero % potencia10;
			cout << "TRUE RESTO = " << true_resto << endl;
			cout << "NUM2 " << num2 << endl;

			if(num2 == 0){ // CAMBIAR ESTO, SI ESTOY EN 500, DEVUELVO 4*9*9 y le sumo uno si el numero de más a la izquierda no es el 0.
				if(true_resto != 1 && true_resto < 10){
					cout << "DOS LLAMADAS" << endl;
					if(dig_der != 0){
						cout << "LLAMADAS = " << resto << " " << potencia10 << "  Y  " << num2 << " " << "1" << endl;
						return calcular(resto, potencia10, potencia9*9) + calcular(num2, 1, 1);
					}
					else{
						cout << "LLAMADAS = " << resto << " " << potencia10 << "  Y  " << num2 << " " << "1" << " + 1"<< endl;
						return calcular(resto, potencia10, potencia9*9) + calcular(num2, 1, 1)+1;
					}
				}
				else{
					cout << "UNA LLAMADA" << resto << " " << potencia10 << endl;
					return calcular(resto, potencia10, potencia9*9);
				}
			}
			else{
				cout << "LLAMADAS = " << resto << " " << potencia10 << "  Y  " << num2 << " " << "1" << endl;
				return calcular(resto, potencia10, potencia9*9) + calcular(num2, 1, 1);
			}
		}
	}
	cout << "_______________________________________________________________" << endl;
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
*/
