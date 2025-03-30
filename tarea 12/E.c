#include <stdio.h>
#include <stdlib.h>

float **leerMatrizDesdeArchivo(const char *nombreArchivo, int *r, int *c) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return NULL;
    }

    fscanf(archivo, "%d %d", r, c);

    float **matriz = (float **)malloc(*r * sizeof(float *));
    for (int i = 0; i < *r; i++) {
        matriz[i] = (float *)malloc(*c * sizeof(float));
    }

    for (int i = 0; i < *r; i++) {
        for (int j = 0; j < *c; j++) {
            fscanf(archivo, "%f", &matriz[i][j]);
        }
    }

    fclose(archivo);
    return matriz;
}

void liberarMatriz(float **matriz, int r) {
    for (int i = 0; i < r; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void imprimirMatriz(float **matriz, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int r, c;

    float **matriz = leerMatrizDesdeArchivo("matriz.txt", &r, &c);

    if (matriz == NULL) {
        return 1;
    }

    printf("Matriz leída desde el archivo:\n");
    imprimirMatriz(matriz, r, c);
    liberarMatriz(matriz, r);

    return 0;
}
