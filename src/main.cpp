#include "funciones.h"
#include <iostream>


using namespace std;



int main() {
    int cantidadMatrices;
    cout << "Ingrese la cantidad de matrices en la cerradura: ";
    cin >> cantidadMatrices;

    int* dimensiones = new int[cantidadMatrices]; // Arreglo para almacenar las dimensiones de cada matriz

    // Pedir al usuario las dimensiones de cada matriz
    for (int i = 0; i < cantidadMatrices; ++i) {
        cout << "Ingrese la dimension de la matriz " << (i + 1) << ": ";
        cin >> dimensiones[i];
    }

    // Crear la cerradura de matrices
    int*** cerradura = crearCerradura(cantidadMatrices, dimensiones);

    // Imprimir la cerradura
    for (int i = 0; i < cantidadMatrices; ++i) {
        cout << "Matriz " << (i + 1) << ":" << endl;
        imprimirMatriz(cerradura[i], dimensiones[i]);
        cout << endl;
    }

    // Solicitar la fila y columna para encontrar la celda correspondiente
    int fila, columna;
    cout << "Ingrese la fila y columna de la celda a buscar: ";
    cin >> fila >> columna;

    // Encontrar la celda correspondiente en cada matriz de la cerradura
    encontrarCeldaCorrespondiente(cerradura, cantidadMatrices, dimensiones, fila, columna);

    // Liberar la memoria utilizada por la cerradura y las dimensiones
    for (int i = 0; i < cantidadMatrices; ++i) {
        liberarMemoria(cerradura[i], dimensiones[i]);
    }
    delete[] dimensiones;
    delete[] cerradura;

    return 0;
}
