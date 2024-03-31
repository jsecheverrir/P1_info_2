#include <iostream>
using namespace std;
#include "funciones.h"


int main() {
    const int longitudMaxima = 100;
    char llave[longitudMaxima];

    cout << "Ingrese la llave (solo números, sin espacios): ";
    cin >> llave;

    // Validar la llave
    if (validarLlave(llave, longitudMaxima)) {
        cout << "Llave ingresada correctamente.\n";
    } else {
        cout << "Error: La llave solo debe contener números.\n";
        return 1;
    }

    return 0;
}
/*
{

    int dimension, nuevadimension;
    cout << "Ingrese la dimension de la matriz cuadrada: ";
    cin >> dimension;

    // Validar la dimensión
    if (dimension <= 0 || dimension % 2 == 0) {
        cout << "La dimension debe ser un numero entero impar y positivo." << endl;
        return 1;
    }

    int opcion;
    cout << "1. Rotar la matriz." << endl;
    cout << "2. Redimensionar la matriz." << endl;
    cin >> opcion;

    if (opcion != 1 && opcion != 2) {
        cout << "Opción no válida." << endl;
        return 1;
    }

    if (opcion == 2) {
        cout << "Ingrese la nueva dimension de la matriz: ";
        cin >> nuevadimension;

        // Validar la nueva dimensión
        if (nuevadimension <= 0 || nuevadimension % 2 == 0) {
            cout << "La nueva dimension debe ser un numero entero impar y positivo." << endl;
            return 1;
        }
    }

    int** matriz = nullptr;

    cout << "Matriz original:" << endl;
    crearMatriz(matriz, dimension);
    imprimirMatriz(matriz, dimension);
    cout << endl;

    if (opcion == 1) {
        cout << "Matriz rotada:" << endl;
        rotarMatriz(matriz, dimension);
    } else if (opcion == 2) {
        cout << "Matriz redimensionada:" << endl;
        redimensionarMatriz(matriz, nuevadimension, dimension);
        dimension = nuevadimension;
    }

    imprimirMatriz(matriz, dimension);
    liberarMemoria(matriz, dimension);

    return 0;
}
*/
