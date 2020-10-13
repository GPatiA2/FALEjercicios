// Nombre del alumno
//Usuario del juez de examen

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int resolver(std::vector<int> const& v){
	unsigned int ini = 0;
	unsigned int tamanio = 0;
	for(unsigned int i = 1; i < v.size(); i++){
		if(v[i] <= v[ini] && (tamanio <= i-ini-1)){
			tamanio++;
		}
		else if(v[i] > v[ini]){
			ini = i;
		}
	}
	return tamanio;
}

void resuelveCaso() {
    int numElem; std::cin >> numElem;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i)
        std::cin >> v[i];
    std::cout << resolver(v) << '\n';
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("sample1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos; std::cin >> numCasos; std::cin.ignore();
    for (int i = 0; i < numCasos; ++i) {resuelveCaso();}
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}


////Especifica el problema
////Precondicion: {v.size() > 0}
////Postcondicion: maxlong = max r,s 0<=r<=s<v.size() : forall q: r<q<s ==> v[q] <= v[r]: s-r
//int resolver(std::vector<int> const& v){
//    //Resuelve el problema
//    //Invariante, funcion de cota
//	//Invariante: maxlong = max r,s 0<=r<=s<i : forall q: r<q<i ==> v[q] <= v[r]: i-r
//	//Funcion de cota: v.size() - i
//	int seg = 0;
//	int maxlong = 0;
//	int marca = v[0];
//	for(unsigned int i = 0; i < v.size(); i++){
////		cout << "V[i]     = " << v[i] << " ";
////		cout << " SEG     = " << seg << " ";
////		cout << " MAXLONG = " << maxlong << " " ;
////		cout << " MARCA   = " << marca << endl;
//		if(v[i] > marca){
//			if(maxlong < seg-1){
//				maxlong = seg-1;
//			}
//			marca = v[i];
//			seg = 1;
//		}
//		else{
//			seg++;
//		}
//	}
//	if(maxlong < seg-1){
//		maxlong = seg-1;
//	}
//	return maxlong;
//}
////Analisis del coste
//// Coste lineal.
