#include <stdio.h>

#define N 2

void laHaceTranspuesta(float mat[][N], int nRens, int nCols) {
    for (int i = 0; i < nRens; i++) {
        for (int j = i + 1; j < nCols; j++) {
            float temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void imprimirMatriz(float mat[][N], int nRens, int nCols) {
    for (int i = 0; i < nRens; i++) {
        for (int j = 0; j < nCols; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    float matriz[N][N] = {
        {1.0, 2.0},
        {4.0, 5.0},
    };

    printf("Matriz original:\n");
    imprimirMatriz(matriz, N, N);

    laHaceTranspuesta(matriz, N, N);

    printf("Matriz transpuesta:\n");
    imprimirMatriz(matriz, N, N);

    return 0;
}
