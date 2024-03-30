#include <iostream>
using namespace std;

//Prototipos de funciones
void crearMatriz(int** &matriz, int dimension);
void rotarMatriz(int** matriz, int dimension);
void imprimirMatriz(int** matriz, int dimension);
void liberarMemoria(int** matriz, int dimension);
void redimensionarMatriz(int **&matriz,int dimension,int Newdimension);

//Definicion de funciones
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

void redimensionarMatriz(int **&matriz, int nuevadimension, int viejadimension) {
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
    int dimension, nuevadimension;
    cout << "Ingrese la dimension de la matriz cuadrada: ";
    cin >> dimension;

    if (dimension <= 0 || dimension % 2 == 0) {
        cout << "La dimension debe ser un numero entero impar y positivo." << endl;
        return 1;
    }

    
    cout << "Ingrese la nueva dimension de la matriz: ";
    cin >> nuevadimension;

    if (nuevadimension <= 0 || nuevadimension % 2 == 0) {
        cout << "La nueva dimension debe ser un numero entero impar y positivo." << endl;
        return 1;
    }

    int** matriz = nullptr;

    cout<<"Matriz original:"<<endl;
    crearMatriz(matriz, dimension);
    imprimirMatriz(matriz, dimension);
    cout << endl;

    cout<<"Matriz rotada:"<<endl;
    rotarMatriz(matriz, dimension);
    cout<<endl;

    cout<<"Matriz redimensionada:"<<endl;
    redimensionarMatriz(matriz, nuevadimension, dimension);
    imprimirMatriz(matriz, nuevadimension);
    liberarMemoria(matriz, nuevadimension);

    return 0;
}
