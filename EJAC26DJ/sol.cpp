//Guillermo Garcia Patiño Lenza

//FALTA PONERLE LA PODA

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void vueltaAtras(const vector<int> & anchoM, const vector<int> & anchoC, const vector<vector<int>> & calidades, vector<bool> & carreteraPuesta, const vector<int> & maxMaquinas, unsigned int maquina, int maxTotal, int & mejorSol, int solActual){
	for(unsigned int i = 0; i < anchoC.size(); i++){
		if(!carreteraPuesta[i] && anchoM[maquina] <= anchoC[i]){
			//if(solActual + (maxTotal - maxMaquinas[maquina]) > mejorSol){
				carreteraPuesta[i] = true;
				solActual += calidades[maquina][i];
				maxTotal -= maxMaquinas[maquina];
				if(maquina == anchoM.size()-1){
					if(solActual > mejorSol){
						mejorSol = solActual;
					}
				}
				else{
					maquina++;
					vueltaAtras(anchoM, anchoC, calidades, carreteraPuesta, maxMaquinas, maquina, maxTotal, mejorSol, solActual);
					maquina--;
				}
				carreteraPuesta[i] = false;
				solActual -= calidades[maquina][i];
				maxTotal += maxMaquinas[maquina];
			//}
		}


	}
}


void resuelveCaso() {
 //resuelve aqui tu caso
    //Lee los datos
	int carreteras;
	int maquinas;
	cin >> maquinas;
	cin >> carreteras;

	vector<int> anchoM(maquinas);
	for(int i = 0; i < maquinas; i++){
		cin >> anchoM[i];
	}

	vector<int> anchoC(carreteras);
	for(int i = 0; i < carreteras; i++){
		cin >> anchoC[i];
	}

	vector<vector<int>> calidades (maquinas, vector<int>(carreteras));
	for(int i = 0; i < maquinas; i++){
		for(int j = 0; j < carreteras; j++){
			cin >> calidades[i][j];
		}
	}

		//	for(int i = 0; i < maquinas; i++){
		//		for(int j = 0; j < carreteras; j++){
		//			cout << calidades[i][j] << " ";
		//		}
		//		cout << endl;
		//	}
		//	cout << "______________________________________________________" << endl;

	//Calcula el resultado

    vector<int> maxMaquinas(carreteras);
    int maxParcial;
    int maxTotal = 0;
    for(int j = 0; j < carreteras; j++){
    	maxParcial = calidades[0][j];
    	for(int i = 0; i < maquinas; i++){
    		if(maxParcial < calidades[i][j]){maxParcial = calidades[i][j];}
    	}
    	maxTotal += maxParcial;
    	maxMaquinas[j] = maxParcial;
    }

		//    for(int i = 0; i < carreteras; i++){
		//    	cout << maxMaquinas[i] << " ";
		//    }
		//    cout << endl;
		//    cout << maxTotal << endl;
		//    cout << "______________________________" << endl;

    int mejorSol = 0;
    int solActual = 0;
    unsigned int maquina = 0;

    vector<bool> carreteraPuesta(maquinas);
    for(int i = 0; i < maquinas; i++){
    	carreteraPuesta[i] = false;
    }

    vueltaAtras(anchoM, anchoC, calidades, carreteraPuesta, maxMaquinas, maquina, maxTotal, mejorSol, solActual);

    cout << mejorSol << endl;
	//Escribe el resultado
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
