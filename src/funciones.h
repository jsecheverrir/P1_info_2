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





//Cerraduras
int obtenerNumeroMatrices(char clave[]);
int*** crearCerradura(int cantidadMatrices, int dimensiones[]);
void encontrarCeldaCorrespondiente(int*** cerradura, int cantidadMatrices, int* dimensiones, int fila, int columna);





#endif // FUNCIONES_H
