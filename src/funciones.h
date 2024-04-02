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

//Clave
bool validarEntrada(char entrada[]);
void extraerFilaColumna(char clave[], int& fila, int& columna);
bool verificarCondiciones(char clave[]);
int obtenerDimension(char clave[]);
int ajustarDimension(int dimension);

//Cerraduras
int obtenerNumeroMatrices(char clave[]);
int*** crearCerradura(int cantidadMatrices, int dimension);
bool abrirCerradura(int*** cerradura, int numMatrices, int dimension, char clave[]);



#endif // FUNCIONES_H
