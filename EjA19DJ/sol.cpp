/*
 * Grupo Mercadona
 * Nicks: Palomitas, LaCabraDeLaLegion, Mr_Tostarica, Dav16d, Zapi y Grooot
 * Nombres: Cristina Alameda, Tania Romero, Alejandro Rivera, David Cruza, David Zapico y Guillermo Garcia Patiño
 */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void mergeSort(vector<int> & q,long long int& inversiones);
void mergeSort(vector<int> & q, int ini, int fin,long long int & inversiones);
void mezcla(vector<int> & q, int ini,unsigned int fin, int m,long long int & inversiones);

void resuelveCaso() {
 //resuelve aqui tu caso
    int numElems;
    long long int inversiones = 0;
    int aux;
    cin >> numElems;
    //cout << numElems;
    vector<int> q(numElems);
    for(int i = 0; i < numElems; i++){
    	cin >> aux;
    	//cout << aux << " ";
    	q[i] = aux;
    }
    //cout << endl;
    //for(int i = 0; i < numElems; i++){
    //	cout << q[i] << " ";
    //}
    //cout << endl;
    mergeSort(q, inversiones);
    cout << inversiones << "\n";
    //Calcula el resultado
    //Escribe el resultado
}

void mergeSort(vector<int> & q,long long int& inversiones){
	mergeSort(q, 0, q.size()-1, inversiones);
	// Primero y ultimo incluidos
}

/*
 * El tamaño del problema es n1 para la funcion mergeSort recursiva
 * En la funcion se ejecutan instrucciones de coste constante y llamadas recursivas
 * La recurrencia queda
 *
 * t(n) = c1 si n <= 1
 * t(n) = 2*t(n1/2) + c2*n su n >= 2
 *
 * Aplicando el resultado teorico de la disminucion del tamaño del problema por cociente
 * con a = 2, k = 1 , b = 2, queda que el algoritmo es de orden n1logn1.
 */

void mergeSort(vector<int> & q, int ini, int fin,long long int & inversiones){
	int m = (ini+fin)/2;
	if(ini < fin){
		//Primero y ultimo incluidos
		mergeSort(q, ini, m, inversiones);
		mergeSort(q, m+1, fin, inversiones);
		mezcla(q, ini, fin, m, inversiones);
	}
}

void mezcla(vector<int> & q, int ini,unsigned int fin, int m,long long int & inversiones){
	vector<int> aux(fin-ini+1);
	//Copio solo los elementos sobre los que voy a operar, el resto no me hacen falta.
	for(unsigned int i = ini; i < fin+1; i++){
		aux[i-ini] = q[i];
	}
	int i = ini;
	unsigned int j = m+1;
	unsigned int k = ini;
	//Voy a ir copiando del aux al original
	while(i <= m && j <= fin ){
		if(aux[i-ini] <= aux[j-ini]){
			q[k] = aux[i-ini];
			k++;
			i++;
		}
		else{
			q[k] = aux[j-ini];
			k++;
			j++;
			inversiones = inversiones + (m+1-i);
			//Si aux[j] > aux[i] tengo una inversion ya que siempre se cumple i < j a la hora de mezclar mitades
			//De hecho, tengo tantas inversiones como numeros me queden por ordenar de la mitad izquierda, ya que esos son los
			//que tengo garantizados que son menores que el que estoy colocando
		}
	}

	while(i <= m){
		q[k] = aux[i-ini];
		i++;
		k++;
	}

	while(j <= fin){
		q[k] = aux[j-ini];
		j++;
		k++;
	}
	//El tamaño del problema para esta funcion es fin-ini = n2
	//Las instrucciones de dentro de los bucles son de coste constante
	//Aplicando la regla de la suma, el coste de todos los bucles es de coste constante
	//En su conjunto, esta funcion recorre el vector de tamaño n2 entero
	//Así que aplicando la regla del producto, el coste de la funcion es lineal en n2.

}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
   ifstream in("casos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif


    int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}
