#ifndef FUNCIONES_H
#define FUNCIONES_H


const int MAX_ELEMENTOS_CLAVE = 100; // Tamaño máximo para la clave
const int MAX_NUM_MATRICES = 10; // Máximo número de matrices permitidas

//Otros
int maximo(int a, int b);
int calcularDimensionMinima(int fila, int columna);


//Manejo de matrices
void crearMatriz(int** &matriz, int dimension);
void rotarMatriz(int** matriz, int dimension);
void imprimirMatriz(int** matriz, int dimension);
void liberarMemoria(int** matriz, int dimension);
void redimensionarMatriz(int **&matriz,int dimension,int Newdimension);

//Clave
bool validarEntrada(char entrada[]);
void separarClave(char clave[], int &fila, int &columna, char &regla);


//Cerraduras
int obtenerNumeroMatrices(char clave[]); //esta es para cuando vamosa generar cerradura cuando solo tenemos clave
int*** crearCerradura(int cantidadMatrices, int dimensiones[]);
void encontrarCeldaCorrespondiente(int*** cerradura, int cantidadMatrices, int* dimensiones, int fila, int columna);







#endif // FUNCIONES_H
