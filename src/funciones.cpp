#include "funciones.h"
#include <iostream>

using namespace std;

void crearMatriz(int** &matriz, int dimension) {
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



int*** crearCerradura(int* tamanos, int numMatrices) {
    int*** cerradura = new int**[numMatrices];

    for (int i = 0; i < numMatrices; ++i) {
        int dimension = tamanos[i];
        crearMatriz(cerradura[i], dimension);
    }

    return cerradura;
}

void imprimirCerradura(int*** cerradura, int numMatrices, int* tamanos) {
    for (int i = 0; i < numMatrices; ++i) {
        cout << "Matriz " << i+1 << ":" << endl;
        imprimirMatriz(cerradura[i], tamanos[i]);
        cout << endl;
    }
}

void liberarCerradura(int*** cerradura, int numMatrices, int* tamanos) {
    for (int i = 0; i < numMatrices; ++i) {
        int dimension = tamanos[i];
        for (int j = 0; j < dimension; ++j) {
            delete[] cerradura[i][j];
        }
        delete[] cerradura[i];
    }
    delete[] cerradura;
}

bool validarClave() {
    char caracter;
    bool espacioAnterior = false; // Para verificar que no haya espacios consecutivos
    bool numeroPrevio = false;    // Para verificar que haya al menos un número

    cout << "Ingrese una clave separada por espacios, use solo numeros: ";

    while (std::cin.get(caracter) && caracter != '\n') {
        if (caracter == ' ') {
            if (!numeroPrevio) {
                std::cin.ignore(10000, '\n'); // Ignorar hasta nueva línea
                return false; // No hay un número antes de un espacio
            }
            espacioAnterior = true;
        } else if (caracter >= '0' && caracter <= '9') {
            numeroPrevio = true;
            espacioAnterior = false;
        } else {
            std::cin.ignore(10000, '\n'); // Ignorar hasta nueva línea
            return false; // Carácter no válido
        }
    }

    return numeroPrevio && !espacioAnterior; // No debe haber un espacio al final
}

bool validarCoordenadas(int*** cerradura, int* tamanos, int numMatrices, int fila, int columna) {
    for (int i = 0; i < numMatrices; ++i) {
        if (fila < 1 || fila > tamanos[i] || columna < 1 || columna > tamanos[i]) {
            cout << "Error: La celda indicada (" << fila << ", " << columna << ") no existe en toda la cerradura." << endl;
            return false;
        }
    }
    return true;
}







