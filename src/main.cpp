#include "funciones.h"
#include <iostream>


using namespace std;



int main() {
    int numMatrices;
    cout << "Ingrese el numero de matrices en la cerradura: ";
    cin >> numMatrices;

    int* tamanos = new int[numMatrices];
    for (int i = 0; i < numMatrices; ++i) {
        cout << "Ingrese la dimension de la matriz " << i+1 << ": ";
        cin >> tamanos[i];
    }

    int*** cerradura = crearCerradura(tamanos, numMatrices);

    cout << "Ingrese la clave separada por espacios (fila columna valor): ";
    int clave[3];
    for (int i = 0; i < 3; ++i) {
        cin >> clave[i];
    }

    if (validarClaveCerradura(cerradura, tamanos, numMatrices, clave)) {
        cout << "La clave abre la cerradura correctamente." << endl;
    } else {
        cout << "La clave no abre la cerradura." << endl;
    }

    liberarCerradura(cerradura, numMatrices, tamanos);
    delete[] tamanos;

    return 0;
}
