#include <iostream>
using namespace std;

//Prototipos de funciones
void crearMatriz(int** matriz, int dimension);
void rotarMatriz(int** matriz, int dimension);
void imprimirMatriz(int** matriz, int dimension);
void liberarMemoria(int** matriz, int dimension);
void redimensionarMatriz(int **matriz,int dimension,int Newdimension);

void crearMatriz(int** matriz, int dimension) {
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
}

void rotarMatriz(int** matriz, int dimension) {
    int** rotado = new int*[dimension],n=dimension;
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
    
    imprimirMatriz(rotado,dimension);
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

void redimensionarMatriz(int **matriz, int nuevadimension, int viejadimension) {
    int** nuevaMatriz = new int*[nuevadimension];
    for (int i = 0; i < nuevadimension; ++i) {
        nuevaMatriz[i] = new int[nuevadimension];
    }

    for (int i = 0; i < viejadimension; ++i) {
        for (int j = 0; j < viejadimension; ++j) {
            if (i < nuevadimension && j < viejadimension) {
                nuevaMatriz[i][j] = matriz[i][j];
            }
        }
    }
    liberarMemoria(matriz,viejadimension);

    matriz = nuevaMatriz;

}
int main() {
    int dimension,nuevadimension;
    cout << "Ingrese la dimension de la matriz cuadrada: ";
    cin >> dimension;
    cin >> nuevadimension;

    if (dimension <= 0) {
        cout << "La dimension debe ser un numero entero positivo." << endl;
        return 1;
    }

    int** matriz = new int*[dimension];
    for (int i = 0; i < dimension; ++i) {
        matriz[i] = new int[dimension];
    }

    crearMatriz(matriz,dimension);
    imprimirMatriz(matriz,dimension);
    cout<<endl;

    rotarMatriz(matriz,dimension);
    redimensionarMatriz(matriz,nuevadimension,dimension);
    liberarMemoria(matriz,dimension);

    return 0;
}
