#include "funciones.h"
#include <iostream>

using namespace std;


void crearMatriz(int** &matriz, int dimension) {


    // Ajustar la dimensión si es par
    if (dimension % 2 == 0)
        dimension++;
    int contador = 1;
    matriz = new int*[dimension];
    for (int i = 0; i < dimension; ++i) {
        matriz[i] = new int[dimension];
    }
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            if (i == dimension / 2 && j == dimension / 2) {
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = contador++;
            }
        }
    }
}

void rotarMatriz(int** matriz, int dimension) {
    int** rotado = new int*[dimension];//n=dimension;
    for (int i = 0; i < dimension; ++i) {
        rotado[i] = new int[dimension];
    }

    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            rotado[dimension - j - 1][i] = matriz[i][j];
        }
    }

    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            matriz[i][j] = rotado[i][j];
        }
    }

    //imprimirMatriz(rotado,dimension);
    liberarMemoria(rotado,dimension);
}

void imprimirMatriz(int **matriz,int dimension){
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout<<endl;
    }
}

void liberarMemoria(int **matriz,int dimension){
    for (int i = 0; i < dimension; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void redimensionarMatriz(int **&matriz, int nuevadimension, int viejadimension) {
    int** nuevaMatriz = new int*[nuevadimension];
    for (int i = 0; i < nuevadimension; ++i) {
        nuevaMatriz[i] = new int[nuevadimension];
    }

    int contador = 1;
    for (int i = 0; i < nuevadimension; ++i) {
        for (int j = 0; j < nuevadimension; ++j) {
            if (i == nuevadimension / 2 && j == nuevadimension / 2) {
                nuevaMatriz[i][j] = 0;
            } else {
                nuevaMatriz[i][j] = contador++;
            }
        }
    }

    liberarMemoria(matriz,viejadimension);
    matriz = nuevaMatriz;

}
/*
bool validarEntrada(char entrada[]) {
    // Verificar si los caracteres son dígitos o espacios
    for (int i = 0; entrada[i] != '\0'; ++i) {
        if (!(entrada[i] >= '0' && entrada[i] <= '9') && entrada[i] != ' ' && entrada[i] != '-') {
            cout << "Error: Entrada no válida." << endl;
            return false;
        }
    }
    return true;
}


int obtenerNumeroMatrices(char clave[]) {
    int contador = 0;
    for (int i = 0; clave[i] != '\0'; ++i) {
       if (clave[i] != ' ' && clave[i] != '-') {
            contador++;
        }
    }
    return contador - 1;
}
*/

int*** crearCerradura(int cantidadMatrices, int dimensiones[]) {
    int*** cerradura = new int**[cantidadMatrices]; // Creamos un arreglo de punteros a punteros de enteros para almacenar las matrices

    // Para cada matriz en la cerradura
    for (int i = 0; i < cantidadMatrices; ++i) {
        // Creamos una matriz con la dimensión especificada
        crearMatriz(cerradura[i], dimensiones[i]);
    }

    return cerradura; // Devolvemos el arreglo de matrices
}

void encontrarCeldaCorrespondiente(int*** cerradura, int cantidadMatrices, int* dimensiones, int fila, int columna) {
    // Verificar que la fila y columna ingresadas estén dentro de los límites de cada matriz
    for (int i = 0; i < cantidadMatrices; ++i) {
        if (fila < 0 || fila >= dimensiones[i]+1 || columna < 0 || columna >= dimensiones[i]+1) {
            cout << "La fila o columna ingresada está fuera de los límites de la matriz " << (i + 1) << "." << endl;
            return;
        }
    }

    // Obtener el valor de referencia en la primera matriz
    int valorReferencia = cerradura[0][fila-1][columna-1];
    cout << "El valor de la celda correspondiente en la primera matriz es: " << valorReferencia << endl;

    // Verificar si todas las matrices tienen la misma dimensión
    bool todasMismaDimension = true;
    for (int i = 1; i < cantidadMatrices; ++i) {
        if (dimensiones[i] != dimensiones[0]) {
            todasMismaDimension = false;
            break;
        }
    }

    // Encontrar la celda correspondiente en las matrices restantes de la cerradura
    for (int i = 1; i < cantidadMatrices; ++i) {
        if (todasMismaDimension) {
            // Verificar que las dimensiones de la matriz actual sean mayores o iguales que la fila y columna
            if (fila >= dimensiones[i]+1 || columna >= dimensiones[i]+1) {
                cout << "No se puede encontrar la celda correspondiente en la matriz " << (i + 1) << " porque la fila o columna están fuera de los límites." << endl;
                continue;
            }
            // Obtener el valor en la posición correspondiente en la matriz actual
            int valorCorrespondiente = cerradura[i][fila-1][columna-1];
            cout << "El valor de la celda correspondiente en la matriz " << (i + 1) << " es: " << valorCorrespondiente << endl;
        } else {
            // Obtener el valor en la posición correspondiente en la matriz actual sin ajustar fila y columna
            int valorCorrespondiente = cerradura[i][fila][columna];
            cout << "El valor de la celda correspondiente en la matriz " << (i + 1) << " es: " << valorCorrespondiente << endl;
        }
    }
}
