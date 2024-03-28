#include <iostream>
using namespace std;

//Prototipos de funciones
void crearmatriz();
void redimensionarMatriz();
void rotarMatriz();
void imprimirMatriz();

#include <iostream>
using namespace std;

void crearmatriz(int** matriz, int dimension) {
    int contador = 1;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            if (i == dimension / 2 && j == dimension / 2) {
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = contador++;
            }
        }
    }

    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void rotarMatriz(int** matriz, int dimension) {
    int** rotado = new int*[dimension];
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
    
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < dimension; ++i) {
        delete[] rotado[i];
    }
    delete[] rotado;
}


int main() {
    int dimension;
    cout << "Ingrese la dimension de la matriz cuadrada: ";
    cin >> dimension;

    if (dimension <= 0) {
        cout << "La dimension debe ser un numero entero positivo." << endl;
        return 1;
    }

    int** matriz = new int*[dimension];
    for (int i = 0; i < dimension; ++i) {
        matriz[i] = new int[dimension];
    }

    crearmatriz(matriz,dimension);

    rotarMatriz(matriz,dimension);

    for (int i = 0; i < dimension; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
