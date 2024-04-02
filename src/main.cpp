#include "funciones.h"
#include <iostream>


using namespace std;



int main() {
    char clave[100]; // Suponemos que la clave tendrá como máximo 100 caracteres
    cout << "Ingrese la clave (sin espacios): ";
    cin >> clave;

    // Validar la entrada del usuario
    if (!validarEntrada(clave)) {
        return 1;
    }

    // Extraer fila y columna de la clave
    int fila, columna;
    extraerFilaColumna(clave, fila, columna);

    // Verificar condiciones en la clave
    if (!verificarCondiciones(clave)) {
        return 1;
    }

    // Obtener la dimensión de las matrices
    int dimension = obtenerDimension(clave);
    // Ajustar la dimensión para asegurar que sea impar
    dimension = ajustarDimension(dimension);

    // Obtener el número de matrices para la cerradura
    int numMatrices = obtenerNumeroMatrices(clave);

    // Crear la cerradura
    int*** cerradura = crearCerradura(numMatrices, dimension);

    // Imprimir las matrices de la cerradura
    for (int i = 0; i < numMatrices; ++i) {
        cout << "Matriz " << i + 1 << ":" << endl;
        imprimirMatriz(cerradura[i], dimension);
        cout << endl;
    }

    // Verificar si la cerradura se abre con la clave proporcionada
    if (abrirCerradura(cerradura, numMatrices, dimension, clave)) {
        cout << "La cerradura se abre con la clave proporcionada." << endl;
    } else {
        cout << "La cerradura no se abre con la clave proporcionada." << endl;
    }

    // Liberar memoria de la cerradura
    for (int i = 0; i < numMatrices; ++i) {
        liberarMemoria(cerradura[i], dimension);
    }
    delete[] cerradura;

    return 0;
}
