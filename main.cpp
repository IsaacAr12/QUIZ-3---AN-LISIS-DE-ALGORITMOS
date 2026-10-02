#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using namespace chrono;


// Funciones que estan en los otros archivos

int busquedaBinaria(const vector<int>& arreglo, int numero);

void mergeSort(vector<int>& arreglo, int izquierda, int derecha);


int main() {

    srand(time(nullptr));

    // Tamanos de los arreglos
    int tamanos[] = {
        1000,
        5000,
        10000,
        50000,
        100000
    };

    cout << "N,BusquedaBinaria(ms),MergeSort(ms),log2(N),Nlog2(N)" << endl;


    for (int n : tamanos) {

        // Crear arreglo
        vector<int> arreglo(n);

        // Llenar arreglo con numeros aleatorios
        for (int i = 0; i < n; i++) {
            arreglo[i] = rand() % 1000000;
        }
    }


    return 0;
}