#include "funciones.h"
#include <iostream>

using namespace std;

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

int calcularDimensionMinima(int fila, int columna) {
    // Calculamos la dimensión mínima como el máximo entre fila y columna
    int dimensionMinima = maximo(fila, columna);

    // Si la dimensión mínima es par, la incrementamos en 1 para asegurar que sea impar
    if (dimensionMinima % 2 == 0) {
        dimensionMinima++;
    }

    return dimensionMinima;
}


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

int*** crearCerradura(int cantidadMatrices, int dimensiones[]) {
    int*** cerradura = new int**[cantidadMatrices]; // Creamos un arreglo de punteros a punteros de enteros para almacenar las matrices

    // Para cada matriz en la cerradura
    for (int i = 0; i < cantidadMatrices; ++i) {
        // Creamos una matriz con la dimensión especificada
        crearMatriz(cerradura[i], dimensiones[i]);
    }

    return cerradura; // Devolvemos el arreglo de matrices
}


void encontrarCeldaCorrespondiente(int*** cerradura, int cantidadMatrices, int* dimensiones, int fila, int columna) {

    // Verificar que la fila y columna ingresadas estén dentro de los límites de cada matriz
    for (int i = 0; i < cantidadMatrices; ++i) {
        if (fila < 0 || fila >= dimensiones[i] + 1 || columna < 0 || columna >= dimensiones[i] + 1) { // +1 para abarcar todo el rango de la matriz
            cout << "La fila o columna ingresada está fuera de los límites de la matriz " << (i + 1) << "." << endl;
            return;
        }
    }

    // Arreglo para almacenar los valores de referencia
    int* valoresReferencia = new int[cantidadMatrices];
    // Obtener el valor de referencia en la primera matriz
    valoresReferencia[0] = cerradura[0][fila - 1][columna - 1]; // Ajuste de índices
    cout << "El valor de la celda correspondiente en la primera matriz es: " << valoresReferencia[0] << endl;

    // Verificar si todas las matrices tienen la misma dimensión
    bool todasMismaDimension = true;
    for (int i = 1; i < cantidadMatrices; ++i) {
        if (dimensiones[i] != dimensiones[0]) {
            todasMismaDimension = false;
            break;
        }
    }
    // Encontrar la celda correspondiente en las matrices restantes de la cerradura y almacenar los valores de referencia
    for (int i = 1; i < cantidadMatrices; ++i) {
        if (todasMismaDimension) {
            // Verificar que las dimensiones de la matriz actual sean mayores o iguales que la fila y columna
            if (fila >= dimensiones[i] + 1 || columna >= dimensiones[i] + 1) {
                cout << "No se puede encontrar la celda correspondiente en la matriz " << (i + 1) << " porque la fila o columna están fuera de los límites." << endl;
                continue;
            }
            // Obtener el valor en la posición correspondiente en la matriz actual
            int valorCorrespondiente = cerradura[i][fila - 1][columna - 1];
            // Almacenar el valor de referencia
            valoresReferencia[i] = valorCorrespondiente;
            cout << "El valor de la celda correspondiente en la matriz " << (i + 1) << " es: " << valorCorrespondiente << endl;
        } else {
            // Ajustar las filas y columnas para matrices de diferente dimensión
            int ajusteFila = (dimensiones[i] - dimensiones[0]) / 2;
            int ajusteColumna = (dimensiones[i] - dimensiones[0]) / 2;

            // Obtener el valor en la posición correspondiente en la matriz actual con ajuste
            int valorCorrespondiente = cerradura[i][fila + ajusteFila - 1][columna + ajusteColumna - 1];
            // Almacenar el valor de referencia
            valoresReferencia[i] = valorCorrespondiente;
            cout << "El valor de la celda correspondiente en la matriz " << (i + 1) << " es: " << valorCorrespondiente << endl;
        }
    }

    // Ahora tenemos todos los valores de referencia almacenados en el arreglo valoresReferencia

    // Pedir al usuario la entrada que contiene las condiciones de la clave
    string entradaCondiciones;
    cout << "Ingrese las condiciones de la clave (en el formato 'condicion1 condicion2 ...', donde 1 es mayor, -1 es menor, y 0 es igual): ";
    cin.ignore(); // Limpiar el buffer del teclado antes de leer la nueva entrada
    getline(cin, entradaCondiciones);

    // Arreglo para almacenar las condiciones de la clave
    int* condiciones = new int[entradaCondiciones.length()];
    int indiceCondicion = 0;

    // Verificar si se cumplen las condiciones para los valores de referencia
    int referenciaAnterior = valoresReferencia[0]; // Inicializar con el primer valor de referencia
    bool condicionesCumplidas = true; // Suponemos que se cumplen todas las condiciones
    for (int i = 0; i < entradaCondiciones.length(); ++i) {
        char condicionChar = entradaCondiciones[i];

        if (condicionChar != '1' && condicionChar != '0' && condicionChar != '-' && condicionChar != ' ') {
            cout << "Error: Formato de entrada de condiciones inválido." << endl;
            delete[] condiciones;
            delete[] valoresReferencia;
            return;
        }

        int condicion;
        if (condicionChar == '-') {
            // Si el carácter es '-', establecer condicion como -1
            condicion = -1;
        } else {
            // De lo contrario, convertir el carácter numérico a su valor entero correspondiente
            condicion = (condicionChar == '0') ? 0 : 1;
        }

        if (i % 2 == 1) {
            condiciones[indiceCondicion++] = condicion;
        } else {
            // Obtener el valor de referencia correspondiente asegurándose de no exceder los límites de valoresReferencia
            int referenciaActual = (i + 1 < cantidadMatrices) ? valoresReferencia[i + 1] : valoresReferencia[cantidadMatrices - 1];

            if ((condicion == 1 && referenciaAnterior <= referenciaActual) ||
                (condicion == -1 && referenciaAnterior >= referenciaActual) ||
                (condicion == 0 && referenciaAnterior != referenciaActual)) {
                condicionesCumplidas = false;
                break;
            }

            referenciaAnterior = referenciaActual;
        }
    }

    // Realizar rotaciones si las condiciones no se cumplen inicialmente
    if (!condicionesCumplidas) {
        int rotaciones = 0;
        while (rotaciones < 4) {
            // Rotar las matrices según el par que estemos evaluando
            for (int i = 0; i < cantidadMatrices - 1; ++i) {
                rotarMatriz(cerradura[i + 1], dimensiones[i + 1]);
                // Actualizar el valor de referencia de la matriz actual
                valoresReferencia[i + 1] = cerradura[i + 1][fila - 1][columna - 1];
            }

            cout << "Cerradura rotada " << (rotaciones + 1) << " vez(es)." << endl;
            cout << "Valores de referencia actualizados: ";
            for (int i = 0; i < cantidadMatrices; ++i) {
                cout << "Matriz " << (i + 1) << ": " << valoresReferencia[i] << " ";
            }
            cout << endl;

            // Verificar si las condiciones se cumplen después de la rotación
            bool condicionesCumplidasDespuesRotacion = true;
            int referenciaAnteriorDespuesRotacion = valoresReferencia[0];
            for (int i = 0; i < entradaCondiciones.length(); ++i) {
                char condicionChar = entradaCondiciones[i];
                int condicion;
                if (condicionChar == '-') {
                    condicion = -1;
                } else {
                    condicion = (condicionChar == '0') ? 0 : 1;
                }
                if (i % 2 == 1) {
                    continue;
                } else {
                    int referenciaActualDespuesRotacion = (i + 1 < cantidadMatrices) ? valoresReferencia[i + 1] : valoresReferencia[cantidadMatrices - 1];
                    if ((condicion == 1 && referenciaAnteriorDespuesRotacion <= referenciaActualDespuesRotacion) ||
                        (condicion == -1 && referenciaAnteriorDespuesRotacion >= referenciaActualDespuesRotacion) ||
                        (condicion == 0 && referenciaAnteriorDespuesRotacion != referenciaActualDespuesRotacion)) {
                        condicionesCumplidasDespuesRotacion = false;
                        break;
                    }
                    referenciaAnteriorDespuesRotacion = referenciaActualDespuesRotacion;
                }
            }

            if (condicionesCumplidasDespuesRotacion) {
                cout << "Las condiciones de la clave se cumplen después de " << (rotaciones + 1) << " rotaciones." << endl;
                break;
            } else {
                rotaciones++;
            }
        }

        if (rotaciones == 4) {
            cout << "No se pudieron cumplir las condiciones después de 4 rotaciones. La cerradura no abre con esta clave." << endl;
        }
    } else {
        // Imprimir el resultado de la verificación de las condiciones
        cout << "Las condiciones de la clave se cumplen para los valores de referencia." << endl;
    }

    // Liberar memoria
    delete[] condiciones;
    delete[] valoresReferencia;
}

