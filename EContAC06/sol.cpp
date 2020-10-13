/*
 * La Cabra de la Legion
 * Groot
 *
 * Tania Romero Segura
 * Guillermo Garcia Patiño Lenza
 *
 * Grupo Mercadona
 */

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10;

void vueltaAtras(const int donaciones[MAX][MAX] ,const int vetos [MAX][MAX] ,const int n, int marcador[MAX] , bool puesto [MAX], int artista, int coste, int & mejorCoste, bool & haySolucion, const int maximo[MAX], int & maximoglobal){
	for(int i = 0; i < n; i++){
		if(!puesto[i]){
			puesto[i] = true;
			coste += donaciones[i][artista];
			maximoglobal -= maximo[i];
			marcador[artista] = i;
			//cout << "ARTISTA = " << artista << endl;
			if(artista > 0){
				if((coste + maximoglobal > mejorCoste) /*&& (vetos[i][marcador[artista]-1] == 1)*/){
					if(vetos[i][marcador[artista-1]] == 1){
						if(artista == n-1){
							cout << "SOLUCION ALCANZADA DE COSTE " << coste << endl;
							cout << "EL MAXIMO GLOBAL ES " << maximoglobal << endl;
							haySolucion = true;
							if(coste > mejorCoste){
								mejorCoste = coste;
							}

						}
						else{
							artista++;
							vueltaAtras(donaciones, vetos, n, marcador, puesto, artista, coste, mejorCoste, haySolucion, maximo, maximoglobal);
							artista--;
						}
					}
					else{
						//cout << "NO SE LLEGA POR VETOS" << endl;
					}
				}
				else{
					//cout << "NO SE LLEGA POR EL COSTE" << endl;
				}
			}
		}
		else{
			artista++;
			vueltaAtras(donaciones, vetos, n, marcador, puesto, artista, coste, mejorCoste, haySolucion, maximo, maximoglobal);
			artista--;
		}

		puesto[i] = false;
		coste -= donaciones[i][artista];
		maximoglobal += maximo[i];
		marcador[artista] = -1;


	}








}


void resuelveCaso() {
 //resuelve aqui tu caso
    //Lee los datos
	int n;
	cin >> n;
	int donaciones[MAX][MAX];

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> donaciones[i][j];
		}
	}

	int vetos[MAX][MAX];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> vetos[i][j];
		}
	}

	bool haySolucion = false;;
	int mejorCoste = 0;

	int marcador[MAX];
	int artista = 0;

	bool puesto[MAX];
	for(int i = 0; i < n; i++){
		puesto[i] = false;
	}
	for(int i = 0; i < n; i++){
		marcador[i] = -1;
	}

	int coste = 0;

	//Calculo de la cota: sera un numero que contenga la suma de los maximos de todos los artistas.
	//Se irá actualizando el maximo cada vez que se ponga un artista --> se resta de la suma de los maximos el minimo de ese artista
	int maximo[n];
	int maximoglobal = 0;

	int maximoParcial;
	for(int j = 0; j < n; j++){
		maximoParcial = donaciones[0][j];
		for(int i = 0; i < n; i++){
			if(donaciones[i][j] > maximoParcial){maximoParcial = donaciones[i][j]; }
		}
		maximoglobal += maximoParcial;
		maximo[j] = maximoParcial;
		//cout << "COLUMNA " << j << " MAXIMO " << maximoParcial << endl;
	}
	cout << "TENGO " << n << " ARTISTAS" << endl;
	cout << "EL MAXIMO QUE HE CALCULADO ES" << maximoglobal << endl;
	for(int i = 0; i < n; i++){
		cout << maximo[i] << " ";
	}
	cout << endl;

	vueltaAtras(donaciones, vetos, n, marcador, puesto, artista, coste, mejorCoste, haySolucion, maximo, maximoglobal);
    //Calcula el resultado
    //Escribe el resultado
	if(haySolucion){
		cout << mejorCoste << endl;
	}
	else{
		cout <<"NEGOCIA CON LOS ARTISTAS" << endl;
	}
	//cout << "___________________________________________________" << endl;
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
    //system("PAUSE");
#endif

    return 0;
}


/*
 * cout << "COLOCANDO ARTISTA EN LA POSICION " << artista << endl;
		//Para la posicion [artista], voy a ir probando cada artista posible
		if(!puesto[i]){ //Si no lo he puesto aun
			if(artista-1 >= 0){
				if(vetos[i][marcador[artista-1]] == 1){ //Si admite tocar despues del artista anterior
					cout << "EN LA POSICION " << artista << " PONGO EL ARTISTA " << i <<endl;
					marcador[artista] = i; 				//En la posicion [artista] pongo el artista que estoy mirando
					puesto[i] = true; 					//Anoto que ese artista ya lo he puesto
					minimoglobal -= minimo[i];			//Minimo global lleva la suma de los minimos, asi que la cota inferior mas alta que se me ocurre es, sumarle al coste que llevo la suma de todos los minimos
														//	excepto el coste minimo del artista que acabo de poner, asi que ya no afecta
					coste += donaciones[i][artista];	//Al coste le sumo el coste del artista en esa posicion.
					cout << "LLEVO UN COSTE DE " << coste << endl;

					if(coste + minimoglobal > mejorCoste){ //Si el coste que llevo mas la suma de los minimos de los que me quedan por poner es mayor que el mejorCoste que llevo, sigo adelante
						if(artista == n-1){
							if (coste > mejorCoste){
								mejorCoste = coste;
							}
							cout << "HAY SOLUCION " << endl;
							haySolucion = true;
							marcador[artista] = -1;
							puesto[i] = false;
							minimoglobal += minimo[i];
							coste -= donaciones[i][artista];
						}
						else{
							artista++;
							vueltaAtras(donaciones, vetos, n, marcador, puesto, artista, coste, mejorCoste, haySolucion, minimo, minimoglobal);
							marcador[artista] = -1;
							puesto[i] = false;
							minimoglobal += minimo[i];
							coste -= donaciones[i][artista];
						}

					}
					else{
						//Si el coste no me va a quedar mejor que el que tengo, no sigo por ese camino.
						marcador[artista] = -1;
						puesto[i] = false;
						minimoglobal += minimo[i];
						coste -= donaciones[i][artista];
					}
				}
			}
			else{
				cout << "EN LA POSICION " << artista << " PONGO EL ARTISTA " << i << endl;
				marcador[artista] = i; 				//En la posicion [artista] pongo el artista que estoy mirando
				puesto[i] = true; 					//Anoto que ese artista ya lo he puesto
				minimoglobal -= minimo[i];			//Minimo global lleva la suma de los minimos, asi que la cota inferior mas alta que se me ocurre es, sumarle al coste que llevo la suma de todos los minimos
													//	excepto el coste minimo del artista que acabo de poner, asi que ya no afecta
				coste += donaciones[i][artista];	//Al coste le sumo el coste del artista en esa posicion.
				artista++;							//Voy a poner un artista en la siguiente posicion

				vueltaAtras(donaciones, vetos, n, marcador, puesto, artista, coste, mejorCoste, haySolucion, minimo, minimoglobal);
				//Al acabar con todas las posibilidades de esa rama, quito el ultimo artista de donde esta, resto el coste, actualizo el minimo global
				//No resto de artista porque va por referencia.
				marcador[artista] = -1;
				puesto[i] = false;
				minimoglobal += minimo[i];
				coste -= donaciones[i][artista];
			}
		}
 *
 */
