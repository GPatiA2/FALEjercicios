/*
 * ej1.cpp
 *
 *  Created on: 13 ene. 2020
 *      Author: Guille
 */
//
//#include <iostream>
//using namespace std;
//
//
////Precondicion = {numero >= 0}
//
//bool resolver(int numeroOrig){
//	bool entretenido = true;
//	int potencia = 10;
//	int cifra;
//	int cifraAnterior;
//	int numero = numeroOrig;
//	while(numero/potencia != 0 && entretenido){
//		//Invariante {entretenido = forall q: 1 <= q <= |lg(numeroOrig)| + 1 - |lg(numero)| + 1 --> (numeroOrig/(10^q))%10 != (numeroOrig/(10^q-1))%10}
//		//Invariante {entretenido = forall q: 1 <= q <= |lg(numeroOrig)| - |lg(numero)| --> (numeroOrig/(10^q))%10 != (numeroOrig/(10^q-1))%10}
//		//Cota = numero/10
//		cifraAnterior = numero % 10;
//		numero = numero / 10;
//		cifra = numero % 10;
//		entretenido = entretenido && (cifraAnterior != cifra);
//	}
//	return entretenido;
//}
//
////PostCondicion =  {entretenido = forall q: 0 <= q <= |lg(numero)| --> (numero/(10^q))%10 != (numero/(10^q+1))%10}
//
//
//int main(){
//	int numero;
//	bool entretenido = true;
//	cin >> numero;
//
//	while(numero != -1){
//		entretenido = resolver(numero);
//		if(entretenido){cout << "ENTRETENIDO" << endl;}
//		else{cout << "NO ENTRETENIDO" << endl;}
//		cin >> numero;
//	}
//
//
//
//	return 0;
//}
//
//
