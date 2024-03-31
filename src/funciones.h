#ifndef FUNCIONES_H
#define FUNCIONES_H



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

bool validarClave();
bool validarCoordenadas(int*** cerradura, int* tamanos, int numMatrices, int fila, int columna);
bool validarClaveCerradura(int*** cerradura, int* tamanos, int numMatrices, int clave[]);




#endif // FUNCIONES_H
