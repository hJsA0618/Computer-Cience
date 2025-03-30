#include <stdio.h>
#include <stdlib.h>

#define SEED 1234

double generarNormal() {
    double suma = 0.0;
    for (int i = 0; i < 12; i++) {
        suma += (double)rand() / RAND_MAX;
    }
    return suma - 6.0;
}

double*** crearCubo(int tajadas, int renglones, int columnas) {
    double ***cubo = (double ***)malloc(tajadas * sizeof(double **));

    for (int i = 0; i < tajadas; i++) {
        cubo[i] = (double **)malloc(renglones * sizeof(double *));
        for (int j = 0; j < renglones; j++) {
            cubo[i][j] = (double *)malloc(columnas * sizeof(double));
        }
    }

    return cubo;
}

void liberarCubo(double ***cubo, int tajadas, int renglones) {
    for (int i = 0; i < tajadas; i++) {
        for (int j = 0; j < renglones; j++) {
            free(cubo[i][j]);
        }
        free(cubo[i]);
    }
    free(cubo);
}

void llenarCuboConNormales(double ***cubo, int tajadas, int renglones, int columnas) {
    for (int i = 0; i < tajadas; i++) {
        for (int j = 0; j < renglones; j++) {
            for (int k = 0; k < columnas; k++) {
                cubo[i][j][k] = generarNormal();
            }
        }
    }
}

void imprimirCubo(double ***cubo, int tajadas, int renglones, int columnas) {
    for (int i = 0; i < tajadas; i++) {
        printf("Tajada %d:\n", i + 1);
        for (int j = 0; j < renglones; j++) {
            for (int k = 0; k < columnas; k++) {
                printf("%.2f ", cubo[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int tajadas, renglones, columnas;

    printf("Ingrese el numero de tajadas: ");
    scanf("%d", &tajadas);
    printf("Ingrese el numero de renglones: ");
    scanf("%d", &renglones);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    srand(SEED);

    double ***cubo = crearCubo(tajadas, renglones, columnas);

    llenarCuboConNormales(cubo, tajadas, renglones, columnas);

    imprimirCubo(cubo, tajadas, renglones, columnas);

    liberarCubo(cubo, tajadas, renglones);

    return 0;
}
