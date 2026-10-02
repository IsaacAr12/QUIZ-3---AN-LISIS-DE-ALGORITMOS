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

        // MERGE SORT

        vector<int> copia = arreglo;

        auto inicioMerge = high_resolution_clock::now();

        mergeSort(copia, 0, copia.size() - 1);

        auto finMerge = high_resolution_clock::now();

        double tiempoMerge =
            duration<double, milli>(finMerge - inicioMerge).count();


        // BUSQUEDA BINARIA
        // La busqueda binaria necesita que el arreglo este ordenado

        sort(arreglo.begin(), arreglo.end());


        volatile int resultado = 0;

        auto inicioBinaria = high_resolution_clock::now();

        // Se repite porque una sola busqueda es demasiado rapida para medirla

        for (int i = 0; i < 100000; i++) {
            resultado += busquedaBinaria(arreglo, -1);
        }

        auto finBinaria = high_resolution_clock::now();


        double tiempoBinaria =
            duration<double, milli>(finBinaria - inicioBinaria).count();


        // Promedio de una sola busqueda

        tiempoBinaria = tiempoBinaria / 100000;


        // VALORES TEORICOS

        double logN = log2(n);

        double nLogN = n * log2(n);


        // RESULTADOS

        cout << n << ","
             << tiempoBinaria << ","
             << tiempoMerge << ","
             << logN << ","
             << nLogN << endl;
    }


    return 0;
}