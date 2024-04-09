#include "funciones.h"
#include <iostream>

using namespace std;

int main() {
    int cantidadMatrices;
    string entradaCondiciones;


    // Solicitar la fila y columna para encontrar la celda correspondiente
    int fila, columna;
    cout << "Ingrese la fila y columna de la celda a buscar: ";
    cin >> fila >> columna;
    int dimensionMinima = calcularDimensionMinima(fila,columna);


    cout << "Ingrese las condiciones de la clave (en el formato 'condicion1 condicion2 ...', donde 1 es mayor, -1 es menor, y 0 es igual): ";
    cin.ignore(); // Limpiar el buffer del teclado antes de leer la nueva entrada
    getline(cin, entradaCondiciones);

    cantidadMatrices = entradaCondiciones.length() + 1; //aqui debo poner algo para clave -1

    int* dimensiones = new int[cantidadMatrices]; // Arreglo para almacenar las dimensiones de cada matriz
    for (int i = 0; i < cantidadMatrices; ++i) {
        dimensiones[i] = dimensionMinima;
    }

    // Crear la cerradura de matrices
    int*** cerradura = crearCerradura(cantidadMatrices, dimensiones);

    // Imprimir la cerradura
    for (int i = 0; i < cantidadMatrices; ++i) {
        cout << "Matriz " << (i + 1) << ":" << endl;
        imprimirMatriz(cerradura[i], dimensiones[i]);
        cout << endl;
    }


    // Encontrar la celda correspondiente en cada matriz de la cerradura
    encontrarCeldaCorrespondiente(cerradura,cantidadMatrices, dimensiones, fila, columna);

    // Liberar la memoria utilizada por la cerradura y las dimensiones
    for (int i = 0; i < cantidadMatrices; ++i) {
        liberarMemoria(cerradura[i], dimensiones[i]);
    }
    delete[] dimensiones;
    delete[] cerradura;

    return 0;
}
