#include <stdio.h>
#include <stdlib.h>

void escribirMatrizEnArchivo(const char *nombreArchivo, float **matriz, int r, int c) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "%d %d\n", r, c);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fprintf(archivo, "%.6f ", matriz[i][j]);
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
}

float **crearMatriz(int r, int c) {
    float **matriz = (float **)malloc(r * sizeof(float *));
    for (int i = 0; i < r; i++) {
        matriz[i] = (float *)malloc(c * sizeof(float));
    }
    return matriz;
}

void liberarMatriz(float **matriz, int r) {
    for (int i = 0; i < r; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int r, c;

    printf("Ingrese el numero de renglones (r): ");
    scanf("%d", &r);
    printf("Ingrese el numero de columnas (c): ");
    scanf("%d", &c);

    if (r <= 0 || c <= 0) {
        printf("Las dimensiones de la matriz deben ser mayores que 0.\n");
        return 1;
    }

    float **matriz = crearMatriz(r, c);

    printf("Ingrese los valores de la matriz:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    escribirMatrizEnArchivo("matriz.txt", matriz, r, c);
    printf("Matriz escrita en el archivo matriz.txt\n");

    liberarMatriz(matriz, r);

    return 0;
}
