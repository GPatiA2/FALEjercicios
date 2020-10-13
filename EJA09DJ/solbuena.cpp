/*
 * solbuena.cpp
 *
 *  Created on: 15 nov. 2019
 *      Author: Guille
 */


#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//long long int calcular(long long int num, long long int potencia10, long long int potencia9);
 int calcular( int num,  int potencia10, int potencia9);
 int calculaUnos(long long int num);

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
	return calcular(num, 10, 9);
}

/*
long long int calcular(long long int numero, long long int potencia10, long long int potencia9){
	//cout << "NUMERO = " << numero << endl;
	//cout << "POT9 = " << potencia9 << endl;
	//cout << "POT10 = " << potencia10 << endl;
	if(numero < 10){
		return numero;
	}
	else if(numero >= 10 && numero < 20){
		return 9;
	}
	else if(numero % 10 == 0){
		return (((numero/10)-1) * 9)+1;
	}
	else{
		if(potencia10 > numero) {
			//cout << "HOLA " << endl;
			int dig_iz = numero / (potencia10/10);
			int dig_der = numero % (potencia10/10);
			//cout << "DIGDER = " << dig_der << endl;
			//cout << "DIGIZQ = " << dig_iz << endl;
			//cout << "_________________" << endl;
			if(dig_iz > 1) {
				//cout << "DEVUELVO " << (dig_iz-1) * (potencia9/9) << "+ la otra llamada" << endl;
				if(dig_der == 0){
					return (dig_iz-1) * (potencia9/9);
				}
				else{
					return (dig_iz-1) * (potencia9/9) + calcular(dig_der, potencia10/10, potencia9/9);
				}
			} else {
				return calcular(dig_der, potencia10/10, potencia9/9);
			}
		} else {
			return calcular(numero, potencia10*10, potencia9*9);
		}
	}

}
*/

int calcular(int numero, int potencia10, int potencia9){
	int dig_derecha;
	int parte_izquierda;

	cout << "__________________________________________________________________________" << endl;
	cout << "NUMERO = " << numero << endl;
	cout << "POTENCIA 10 = " << potencia10 << endl;
	cout << "POTENCIA 9 = " << potencia9 << endl;
	if(numero < 10){
		return numero;
	}
	else if(numero >= 10 && numero < 20){
		return 9;
	}
	else if(numero % 10 == 0){
		return (((numero/10)-1)*9)+1;
	}
	else{
		if(potencia10 > numero){
			parte_izquierda = numero / (potencia10/10);
			dig_derecha = numero%(potencia10/10);

			cout << "DIG DERECHA = " << dig_derecha << endl;
			cout << "PARTE IZQUIERDA = " << parte_izquierda << endl;

			if(parte_izquierda > 1){
				if(dig_derecha == 0){
					return (parte_izquierda-1)*(potencia9/9);
				}
				else{
					return (parte_izquierda-1)*(potencia9/9)+calcular(dig_derecha, potencia10/10, potencia9/9);
				}
			} else{
				return calcular(dig_derecha, potencia10/10, potencia9/9);
			}
		} else{
			return calcular(numero,potencia10*10,potencia9*9);
		}
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

/*
 * dig_derecha = numero % potencia10;
	parte_izquierda = (numero / potencia10) * potencia10;
 * if(numero == 0){ // EL 0 es caso directo
		cout << "CASO 0" << endl;
		system("PAUSE");
		cout << "DEVUELVO 0" << endl;
		return 0;
	}
	else if(numero >= 10 && numero < 20){ //Los casos 10,11,12,13,14,15,16,17,18,19 son directos
		cout << "CASO 10,11,12,13,14,15,16,17,18,19" << endl;
		system("PAUSE");
		cout << "DEVUELVO 9" << endl;
		return 9;
	}
	else if(numero < 10 && numero >= 1){ //Los numeros 1,2,3,4,5,6,7,8,9 son casos directos
		cout << "CASO 1,2,3,4,5,6,7,8,9" << endl;
		system("PAUSE");
		cout << "DEVUELVO " << numero << endl;
		return numero;
	}
	else if(numero < 100 && numero >10 && numero%10 == 0 && prevnum_derecha == 0){  //Para los numeros 20,30,40,50,60,70,80,90 devuelvo (((20/10)-1)*9) los numeros que hay hasta él + él mismo
		cout << "CASO 20,30,40,50,60,70,80,90" << endl;
		system("PAUSE");
		cout << "DEVUELVO " << (((numero/10)-1)*9)+1;
		return (((numero/10)-1)*9)+1;
	}
	else if(numero <100 && numero > 10 && numero%10 == 0 && prevnum_derecha != 0){
		cout << "CASO 2X,3X,4X,5X,6X,7X,8X,9X" << endl;
		system("PAUSE");
		cout << "DEVUELVO " << (((numero/10)-1)*9) << endl;
		return (((numero/10)-1)*9);
	}
	else if(numero/potencia10 == 0){
		cout << "ME HE PASADO, VOY A DEVOLVER" << endl;
		cout << "DEVUELVO " << ((numero*10)/potencia10)*(potencia9/9) << endl;
		return ((numero*10)/potencia10)*(potencia9/9);
	}
	else{ //Para el resto de numeros los descompongo y calculo
		cout << "DOS LLAMADAS" << endl;
		system("PAUSE");
		cout << "LLAMO CON " << parte_izquierda << " " << potencia10*10 << endl;;
		cout << "LLAMO CON" << dig_derecha << " 1" << endl;
		return calcular(parte_izquierda, potencia10*10, potencia9*9, dig_derecha) + calcular(dig_derecha, 1, 1, dig_derecha);
	}
 *
 *
 *
 * ______________________________________________________________________________________________
 * else if(numero % 10 == 0 &&  numero > 10 && numero < 100){
		cout << "LA NUEVA COÑO" << endl;
		return (((numero/10)-1)*9)+1;
	}
	else if(numero/potencia10 == 0){
		if(potencia10/ 10 == 1){
			cout << "POTENCIA 10 / 10 == 1" << endl;
			cout << "DEVUEVLO " << numero/potencia10 << endl;
			return numero/(potencia10/10);
		}
		else{
			cout << "POTENCIA10 / 10 != 1" << endl;
			cout << "DEVUELVO" << ((numero*10/potencia10)-1) * (potencia9/9) << endl;
			return ((numero*10/potencia10)-1) * (potencia9/9);
		}
	}
	else{
		cout << "DOS LLAMADAS" << endl;
		return calcular(parte_izquierda, potencia10*10, potencia9*9) + calcular(dig_derecha, 1, 1);
	}
 *
 *
 * ____________________________________________________________________________________________
 * else if(numero/potencia10 > 1 && numero/potencia10 < 10 && dig_derecha == 0 && numero > 9){
		cout << "DEVUELVO1 " << ((numero/potencia10)-1)*potencia9 << endl;
		return ((numero/potencia10)-1)*potencia9;
	}
	else if(numero/potencia10 == 0){
		cout << "DEVUELVO2 " << ((numero*10/potencia10)-1)*(potencia9/9) << endl;
		return (((numero*10/potencia10)-1)*(potencia9/9));
	}
	else if(numero == 10){
		cout << "DEVUELVO 9" << endl;
		return 9;
	}

 * _______________________________________________________________
if(numero/potencia10 < 10){
			system("PAUSE");
			return ((numero/potencia10 - 1)*potencia9) + calcular(dig_derecha, potencia10, potencia9);
		}
		else{
			return calcular(parte_izquierda, potencia10*10, potencia9*9) + calcular(dig_derecha, potencia10, potencia9);
		}


else if(numero > 0 && numero/potencia10 > 0 && numero/potencia10 < 10){
		cout << "DEVUELVO " << (numero/potencia10)-1 << " * " << potencia9 << endl;
		return (numero/potencia10)-1 * potencia9;
	}
	else{
		cout << "LLAMADA A CALCULAR(" << parte_izquierda << ", " << potencia10*10 << ", " << potencia9*9 << ")" << endl;
		cout << "LLAMADA A CALCULAR(" << dig_derecha << ", " << potencia10 << ", " << potencia9 << ")" << endl;
		return calcular(parte_izquierda, potencia10*10, potencia9*9) + calcular(dig_derecha, 1, 1);
	}













*/
