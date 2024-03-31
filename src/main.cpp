#include <iostream>
using namespace std;
#include "funciones.h"


int main() {
    // Pedimos al usuario que ingrese los tamaños de las matrices de la cerradura
    cout << "Ingrese el número de matrices en la cerradura: ";
    int numMatrices;
    cin >> numMatrices;

    int* tamanos = new int[numMatrices];
    for (int i = 0; i < numMatrices; ++i) {
        cout << "Ingrese el tamaño de la matriz " << i + 1 << ": ";
        cin >> tamanos[i];
    }

    // Creamos la cerradura
    int*** cerradura = crearCerradura(tamanos, numMatrices);

    // Imprimimos la cerradura
    cout << "Cerradura creada:" << endl;
    imprimirCerradura(cerradura, numMatrices, tamanos);

    // Pedimos al usuario que ingrese la clave
    cout << "Ingrese la clave separada por espacios (fila columna valor): ";
    int fila, columna;
    cin >> fila >> columna;

    // Validamos las coordenadas ingresadas
    if (!validarCoordenadas(cerradura, tamanos, numMatrices, fila, columna)) {
        liberarCerradura(cerradura, numMatrices, tamanos);
        delete[] tamanos;
        return 1; // Salir del programa con código de error
    }

    // Liberamos la memoria de la cerradura y finalizamos el programa
    liberarCerradura(cerradura, numMatrices, tamanos);
    delete[] tamanos;
    cout << "La celda indicada existe en toda la cerradura." << endl;
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
