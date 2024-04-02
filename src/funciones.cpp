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

    while (cin.get(caracter) && caracter != '\n') {
        if (caracter == ' ') {
            if (!numeroPrevio) {
                cin.ignore(10000, '\n'); // Ignorar hasta nueva línea
                return false; // No hay un número antes de un espacio
            }
            espacioAnterior = true;
        } else if (caracter >= '0' && caracter <= '9') {
            numeroPrevio = true;
            espacioAnterior = false;
        } else {
            cin.ignore(10000, '\n'); // Ignorar hasta nueva línea
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

bool verificarReglas(int*** cerradura, int fila, int columna, int clave[], int numMatrices) {
    int condicion1 = clave[2];
    int condicion2 = clave[3];

    int valorActual = cerradura[0][fila - 1][columna - 1];
    int valorSiguiente = cerradura[1][fila - 1][columna - 1];
    int valorSiguiente2 = cerradura[2][fila - 1][columna - 1];

    if (condicion1 == 1 && valorActual <= valorSiguiente) {
        return false;
    }
    if (condicion1 == 0 && valorActual != valorSiguiente) {
        return false;
    }
    if (condicion1 == -1 && valorActual >= valorSiguiente) {
        return false;
    }

    if (condicion2 == 1 && valorSiguiente <= valorSiguiente2) {
        return false;
    }
    if (condicion2 == 0 && valorSiguiente != valorSiguiente2) {
        return false;
    }
    if (condicion2 == -1 && valorSiguiente >= valorSiguiente2) {
        return false;
    }

    return true;
}



bool validarClaveCerradura(int*** cerradura, int* tamanos, int numMatrices, int clave[]) {
    int fila = clave[0];
    int columna = clave[1];

    // Verificar si la fila y la columna están dentro de los límites de la cerradura
    if (!validarCoordenadas(cerradura, tamanos, numMatrices, fila, columna)) {
        cout << "Las coordenadas de la clave estan fuera de los limites de la cerradura." << endl;
        return false;
    }

    // Imprimir la cerradura inicial
    cout << "Cerradura inicial:" << endl;
    for (int i = 0; i < numMatrices; ++i) {
        cout << "Matriz " << i + 1 << ":" << endl;
        imprimirMatriz(cerradura[i], tamanos[i]);
        cout << endl;
    }

    // Imprimir las celdas evaluadas
    cout << "Celdas evaluadas: ";
    for (int i = 0; i < numMatrices; ++i) {
        cout << cerradura[i][fila - 1][columna - 1] << " ";
    }
    cout << endl;

    // Verificar las reglas con las matrices neutras
    if (verificarReglas(cerradura, fila, columna, clave, numMatrices)) {
        cout << "Clave valida sin necesidad de rotar." << endl;
        return true; // Clave válida sin necesidad de rotar
    }

    // Aplicar hasta tres rotaciones para cada par de matrices antes de verificar las reglas nuevamente
    for (int i = 0; i < numMatrices; ++i) {
        for (int j = i + 1; j < numMatrices; ++j) {
            for (int k = 0; k < 3; ++k) {
                rotarMatriz(cerradura[i], tamanos[i]);
                rotarMatriz(cerradura[j], tamanos[j]);

                cout << "Matrices " << i + 1 << " y " << j + 1 << " rotadas " << k + 1 << " veces." << endl;

                // Imprimir las matrices rotadas
                cout << "Cerradura despues de rotacion:" << endl;
                for (int l = 0; l < numMatrices; ++l) {
                    cout << "Matriz " << l + 1 << ":" << endl;
                    imprimirMatriz(cerradura[l], tamanos[l]);
                    cout << endl;
                }

                // Imprimir las celdas evaluadas después de la rotación
                cout << "Celdas evaluadas: ";
                for (int m = 0; m < numMatrices; ++m) {
                    cout << cerradura[m][fila - 1][columna - 1] << " ";
                }
                cout << endl;

                // Verificar las reglas con las matrices rotadas
                if (verificarReglas(cerradura, fila, columna, clave, numMatrices)) {
                    cout << "Clave valida después de una rotacion." << endl;
                    return true; // Clave válida después de una rotación
                }
            }
        }
    }

    cout << "La clave no abre la cerradura." << endl;
    return false; // Clave inválida después de tres rotaciones para cada par de matrices
}

void generarCerradura() {
    int clave[100]; // Definimos un arreglo grande para la clave
    int numElementos = 0;

    // Ingresar la clave separada por espacios
    cout << "Ingrese la clave en el siguiente formato, donde x son numeros, seguidos de una O mayuscula, esta sin espacio (X X X X....O): ";
    while (cin >> clave[numElementos]) {
        numElementos++;
    }

    // Calcular el número de matrices en la cerradura
    int numMatrices = (numElementos - 1);
    cout << "Numero de matrices en la cerradura: " << numMatrices << endl;

    // Obtener los tamaños de las matrices a partir de los dos primeros elementos de la clave
    int* tamanos = new int[numElementos - 1];
    for (int i = 0; i < numElementos - 1; ++i) {
        tamanos[i] = clave[i];
        // Ajustar la dimensión de la matriz si alguno de los dos primeros números es par
        if (i < 2 && clave[i] % 2 == 0) {
            tamanos[i]++;
        }
    }

    // Generar la cerradura utilizando los tamaños obtenidos y la función crearCerradura
    int*** cerradura = crearCerradura(tamanos, numMatrices);

    // Liberar la memoria utilizada por los tamaños de las matrices
    delete[] tamanos;

    // Imprimir las matrices de la cerradura
    for (int i = 0; i < numMatrices; ++i) {
        cout << "Matriz " << i + 1 << ":" << endl;
        imprimirMatriz(cerradura[i], clave[i]);
        cout << endl;
    }

    // Liberar la memoria utilizada por la cerradura
    for (int i = 0; i < numMatrices; ++i) {
        liberarMemoria(cerradura[i], clave[i]);
    }
    delete[] cerradura;
}