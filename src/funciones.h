#ifndef FUNCIONES_H
#define FUNCIONES_H


const int MAX_ELEMENTOS_CLAVE = 100; // Tamaño máximo para la clave
const int MAX_NUM_MATRICES = 10; // Máximo número de matrices permitidas




//Manejo de matrices
void crearMatriz(int** &matriz, int dimension);
void rotarMatriz(int** matriz, int dimension);
void imprimirMatriz(int** matriz, int dimension);
void liberarMemoria(int** matriz, int dimension);
void redimensionarMatriz(int **&matriz,int dimension,int Newdimension);

//Manejo cerraduras

int*** crearCerradura(int* tamanos, int numMatrices);
void liberarCerradura(int*** cerradura, int numMatrices, int* tamanos);
void imprimirCerradura(int*** cerradura, int numMatrices, int* tamanos);


//Manejo llaves

bool validarClave(int clave[], int numElementos);

//Abrir cerraduras
bool validarCoordenadas( int* tamanos, int numMatrices, int fila, int columna);
bool verificarReglas(int*** cerradura, int fila, int columna, int clave[]);
bool validarClaveCerradura(int*** cerradura, int* tamanos, int numMatrices, int clave[]);

//desafio 1
void generarCerradura();




#endif // FUNCIONES_H
