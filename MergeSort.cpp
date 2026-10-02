#include <vector>

using namespace std;

void merge(vector<int>& arreglo, int izquierda, int medio, int derecha) {

    vector<int> temporal;

    int i = izquierda;
    int j = medio + 1;

    while (i <= medio && j <= derecha) {

        if (arreglo[i] < arreglo[j]) {
            temporal.push_back(arreglo[i]);
            i++;
        }
        else {
            temporal.push_back(arreglo[j]);
            j++;
        }
    }

    while (i <= medio) {
        temporal.push_back(arreglo[i]);
        i++;
    }

    while (j <= derecha) {
        temporal.push_back(arreglo[j]);
        j++;
    }

    for (int k = 0; k < temporal.size(); k++) {
        arreglo[izquierda + k] = temporal[k];
    }
}


void mergeSort(vector<int>& arreglo, int izquierda, int derecha) {

    if (izquierda < derecha) {

        int medio = (izquierda + derecha) / 2;

        mergeSort(arreglo, izquierda, medio);
        mergeSort(arreglo, medio + 1, derecha);

        merge(arreglo, izquierda, medio, derecha);
    }
}