#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 256

void leer_matriz(const char *archivo, float ***matriz, int *filas, int *columnas) {
    FILE *file = fopen(archivo, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo %s\n", archivo);
        exit(1);
    }
    fscanf(file, "%d %d", filas, columnas);
    *matriz = (float **)malloc(*filas * sizeof(float *));
    for (int i = 0; i < *filas; i++) {
        (*matriz)[i] = (float *)malloc(*columnas * sizeof(float));
    }
    for (int i = 0; i < *filas; i++) {
        for (int j = 0; j < *columnas; j++) {
            fscanf(file, "%f", &(*matriz)[i][j]);
        }
    }

    fclose(file);
}

void leer_vector(const char *archivo, float **vector, int *tamaño) {
    FILE *file = fopen(archivo, "r");
    if (file == NULL) {
        printf("Error al abrir el archivo %s\n", archivo);
        exit(1);
    }

    fscanf(file, "%d", tamaño);

    *vector = (float *)malloc(*tamaño * sizeof(float));

    for (int i = 0; i < *tamaño; i++) {
        fscanf(file, "%f", &(*vector)[i]);
    }

    fclose(file);
}

void multiplicar_matriz_vector(float **matriz, float *vector, float *resultado, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        resultado[i] = 0;
        for (int j = 0; j < columnas; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }
}

void escribir_vector_binario(const char *archivo, float *vector, int tamaño) {
    FILE *file = fopen(archivo, "wb");
    if (file == NULL) {
        printf("Error al abrir el archivo %s para escritura\n", archivo);
        exit(1);
    }

    fwrite(&tamaño, sizeof(int), 1, file);

    fwrite(vector, sizeof(float), tamaño, file);

    fclose(file);
}

int main() {
    float **matriz_A = NULL, *vector_b = NULL, *resultado = NULL;
    int filas_A, columnas_A, tamaño_b;

    leer_matriz("mat_A.txt", &matriz_A, &filas_A, &columnas_A);

    leer_vector("vec_b.txt", &vector_b, &tamaño_b);

    if (columnas_A != tamaño_b) {
        printf("Error: La matriz A no puede multiplicarse por el vector b (dimensiones incompatibles)\n");
        return 1;
    }

    resultado = (float *)malloc(filas_A * sizeof(float));

    multiplicar_matriz_vector(matriz_A, vector_b, resultado, filas_A, columnas_A);

    escribir_vector_binario("resultado.bin", resultado, filas_A);

    for (int i = 0; i < filas_A; i++) {
        free(matriz_A[i]);
    }
    free(matriz_A);
    free(vector_b);
    free(resultado);

    printf("Multiplicación completada. El resultado se ha guardado en 'resultado.bin'.\n");

    return 0;
}
