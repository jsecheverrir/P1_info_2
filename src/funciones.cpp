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



void extraerFilaColumna(char clave[], int& fila, int& columna) {
    // Extraer fila y columna a evaluar
    fila = clave[0] - '0';
    columna = clave[1] - '0';
}

bool verificarCondiciones(char clave[]) {
    int i = 3; // Comenzamos desde el tercer carácter
    while (clave[i] != '\0') {
        if (clave[i] != '1' && clave[i] != '0' && clave[i] != '-') {
            cout << "Error: Los valores de condición deben ser 1, 0 o -1." << endl;
            return false;
        }
        i++;
    }
    return true;
}

int obtenerDimension(char clave[]) {
    int fila = clave[0] - '0';
    int columna = clave[1] - '0';
    return (fila > columna) ? fila : columna; // Elegimos el mayor como la dimensión
}

int ajustarDimension(int dimension) {
    if (dimension % 2 == 0)
        dimension++; // Ajustar la dimensión si es par
    return dimension;
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

// Función para crear la cerradura
int*** crearCerradura(int cantidadMatrices, int dimension) {
    int*** cerradura = new int**[cantidadMatrices];
    for (int i = 0; i < cantidadMatrices; ++i) {
        cerradura[i] = new int*[dimension];
        crearMatriz(cerradura[i], dimension); // Crear matriz usando la función existente
    }
    return cerradura;
}

bool abrirCerradura(int*** cerradura, int numMatrices, int dimension, char clave[]) {

    int numCondiciones = 0;
    while (clave[numCondiciones + 2] != '\0') { // Calcular la longitud de la clave
        numCondiciones++;
    }


    int* condiciones = new int[numCondiciones];// Obtener las condiciones de la clave
    for (int i = 0; i < numCondiciones; ++i) {
        if (clave[i + 2] == '-') {
            condiciones[i] = -1;
        } else {
            condiciones[i] = clave[i + 2] - '0';
        }
    }


    int fila, columna; // Extraer fila y columna a evaluar
    extraerFilaColumna(clave, fila, columna);


    fila -= 1; // Ajustar las coordenadas para reflejar el índice de la matriz
    columna -= 1;

    for (int k = 0; k < numMatrices - 1; ++k) {
        int valorActual = cerradura[k][fila][columna]; // Utilizar las coordenadas ajustadas
        int valorSiguiente = cerradura[k + 1][fila][columna]; // Utilizar las coordenadas ajustadas
        int condicion = condiciones[k];
        cout << "Celda (" << fila+1 << ", " << columna+1 << ") en la matriz " << k+ 1 << ": " << valorActual << endl;
        cout << "Celda (" << fila+1 << ", " << columna+1 << ") en la matriz " << k + 2 << ": " << valorSiguiente << endl;
        cout << "Condicion para esta comparacion: " << condicion << endl;
        if ((condicion == 1 && valorActual <= valorSiguiente) ||
            (condicion == 0 && valorActual != valorSiguiente) ||
            (condicion == -1 && valorActual >= valorSiguiente)) {
            cout << "Las condiciones no se cumplen." << endl;


            //aqui esta el problema, no se donde

            if (condicion == 1) { // Si la condición es 1, redimensionar la matriz actual
                redimensionarMatriz(cerradura[k], dimension + 2, dimension);
                cout << "Matriz " << k + 1 << " redimensionada." << endl;
                // Volver a imprimir la matriz redimensionada
                cout << "Matriz " << k + 1 << " redimensionada:" << endl;
                imprimirMatriz(cerradura[k], dimension + 2);
                cout << endl;
                // Volver a evaluar las condiciones con la nueva dimensión
                return abrirCerradura(cerradura, numMatrices, dimension + 2, clave);
            }
            // Si la condición es -1, redimensionar la siguiente matriz en la secuencia
            else if (condicion == -1) {
                redimensionarMatriz(cerradura[k + 1], dimension + 2, dimension);
                cout << "Matriz " << k + 2 << " redimensionada." << endl;
                // Volver a imprimir la matriz redimensionada
                cout << "Matriz " << k + 2 << " redimensionada:" << endl;
                imprimirMatriz(cerradura[k + 1], dimension + 2);
                cout << endl;
                // Volver a evaluar las condiciones con la nueva dimensión
                return abrirCerradura(cerradura, numMatrices, dimension + 2, clave);
            }
            delete[] condiciones;
            return false; // Las condiciones no se cumplen
        }
    }
    // Si se cumplen todas las condiciones, la cerradura se abre
    delete[] condiciones;
    cout << "Todas las condiciones se cumplen, la cerradura se abre." << endl;
    return true;
}
