
// NOMBRE Y APELLIDOS

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void vueltaAtras(const vector<vector<int>> & tiempos, unsigned int funcionario, vector<bool> & asignado, const vector<int> & minimos, int sumaActual, int & sumaMejor){
	for(unsigned int i = 0; i < tiempos.size(); i++){
		sumaActual += tiempos[funcionario][i];
		if(!asignado[i]){
			asignado[i] = true;
			if(funcionario == tiempos.size()-1){
				if(sumaActual < sumaMejor){
					sumaMejor = sumaActual;
				}
			}
			else{
				if((sumaActual + minimos[funcionario + 1]) < sumaMejor){
					vueltaAtras(tiempos, funcionario + 1, asignado, minimos, sumaActual, sumaMejor);
				}
			}
			asignado[i] = false;
		}
		sumaActual -= tiempos[funcionario][i];
	}
}


bool resuelveCaso() {

    //Leer caso de prueba
	int tamanio;
	cin >> tamanio;
    if (tamanio == 0){
        return false;
    }
	else{
		//Lectura de los datos
		vector<vector<int>> tiempos(tamanio, vector<int>(tamanio));
		for(unsigned int i = 0; i < tiempos.size(); i++){
			for(unsigned int j = 0; j < tiempos.size(); j++){
				cin >> tiempos[i][j];
			}
		}

//		for(unsigned int i = 0; i < tiempos.size(); i++){
//			for(unsigned int j = 0; j < tiempos.size(); j++){
//				cout << tiempos[i][j] << " ";
//			}
//			cout << endl;
//		}
//
//		cout << "EL TAMAÑO ES " << tiempos.size() << endl;

		unsigned int funcionario = 0;

		//Marcador que llevara que trabajos han sido asignados
		vector<bool> asignado(tamanio);
		for(unsigned int i = 0; i < asignado.size(); i++){
			asignado[i] = false;
		}

		//Valores de las soluciones actual y mejor
		int sumaActual = 0;
		int sumaMejor = 0;

		//Vector de minimios de todos los trabajos para poda de optimalidad
		vector<int> minimos(tamanio);
		int minimoParcial = 0;
		for(unsigned int i = 0; i < tiempos.size(); i++){
			minimoParcial = tiempos[i][0];
			for(unsigned int j = 0; j < tiempos.size(); j++){
				if(minimoParcial > tiempos[i][j]){minimoParcial = tiempos[i][j];}
			}
			minimos[i] = minimoParcial;
		}

		for (unsigned int j = tiempos.size()-1; j > 0; j--){
			minimos[j - 1] += minimos[j];
		}

		for(unsigned int i = 0; i < tiempos.size(); i++){
			sumaMejor += tiempos[i][i];
		}

		vueltaAtras(tiempos, funcionario, asignado, minimos, sumaActual, sumaMejor);

		cout << sumaMejor << endl;
		 return true;
    }

    //Resolver problema
    //Escribir resultado

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
    //system("pause");
#endif
    return 0;
}
