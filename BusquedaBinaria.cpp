#include <vector>

using namespace std;

int busquedaBinaria(const vector<int>& arreglo, int numero) {

    int izquierda = 0;
    int derecha = arreglo.size() - 1;

    while (izquierda <= derecha) {

        int medio = (izquierda + derecha) / 2;

        if (arreglo[medio] == numero) {
            return medio;
        }

        if (arreglo[medio] < numero) {
            izquierda = medio + 1;
        }
        else {
            derecha = medio - 1;
        }
    }

    return -1;
}