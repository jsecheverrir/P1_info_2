#include "funciones.h"
#include <iostream>


using namespace std;

void encontrarCeldaCorrespondiente(int*** cerradura, int cantidadMatrices, int* dimensiones, int fila, int columna) {
    fila--;
    columna--;

    if (fila < 0 || fila >= dimensiones[0] || columna < 0 || columna >= dimensiones[0]) {
        cout << "La fila o columna ingresada está fuera de los límites de la matriz 1." << endl;
        return;
    }

    int filaCero = dimensiones[0] / 2;
    int columnaCero = dimensiones[0] / 2;

    int contadorFila = 0, contadorColumna = 0;

    if (fila > filaCero) contadorFila = fila - filaCero;
    else if (fila < filaCero) contadorFila = -(filaCero - fila);

    if (columna > columnaCero) contadorColumna = columna - columnaCero;
    else if (columna < columnaCero) contadorColumna = -(columnaCero - columna);

    for (int i = 0; i < cantidadMatrices; ++i) {
        int nuevaFila = (dimensiones[i] / 2) + contadorFila;
        int nuevaColumna = (dimensiones[i] / 2) + contadorColumna;

        if (nuevaFila >= 0 && nuevaFila < dimensiones[i] && nuevaColumna >= 0 && nuevaColumna < dimensiones[i]) {
            // Obtener el valor en la posición calculada
            int valorCorrespondiente = cerradura[i][nuevaFila][nuevaColumna];
            cout << "El valor de la celda correspondiente en la matriz " << (i + 1) << " es: " << valorCorrespondiente << endl;
        } else {
            cout << "No se puede encontrar la celda correspondiente en la matriz " << (i + 1) << " porque la fila o columna están fuera de los límites." << endl;
        }
    }
}

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
    //fila=fila-1;
    //columna=columna-1;

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
