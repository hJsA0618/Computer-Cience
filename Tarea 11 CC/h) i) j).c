#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nRens;
    int nCols;
    double **matriz; 
} Matrix;

// h) Declarar el nuevo tipo de dato Matrix
Matrix createMatrix(int nRens, int nCols) {
    Matrix mat;
    mat.nRens = nRens;
    mat.nCols = nCols;

    mat.matriz = (double **)malloc(nRens * sizeof(double *));
    for (int i = 0; i < nRens; i++) {
        mat.matriz[i] = (double *)malloc(nCols * sizeof(double));
    }
    return mat;
}

// i)
void freeMatrix(Matrix *mat) {
    for (int i = 0; i < mat->nRens; i++) {
        free(mat->matriz[i]);
    }
    free(mat->matriz);
    mat->matriz = NULL;
}

// j) Hacer una función que calcula la transpuesta de una matriz
Matrix transposeMatrix(const Matrix *original) {
    Matrix transposed = createMatrix(original->nCols, original->nRens);
    for (int i = 0; i < original->nRens; i++) {
        for (int j = 0; j < original->nCols; j++) {
            transposed.matriz[j][i] = original->matriz[i][j];
        }
    }
    return transposed;
}

//i)
void printMatrix(const Matrix *mat) {
    for (int i = 0; i < mat->nRens; i++) {
        for (int j = 0; j < mat->nCols; j++) {
            printf("%lf ", mat->matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Matrix mat = createMatrix(3, 2);
    mat.matriz[0][0] = 1.0; mat.matriz[0][1] = 2.0;
    mat.matriz[1][0] = 3.0; mat.matriz[1][1] = 4.0;
    mat.matriz[2][0] = 5.0; mat.matriz[2][1] = 6.0;

    printf("Matriz original:\n");
    printMatrix(&mat);

    Matrix transposed = transposeMatrix(&mat);
    printf("Matriz transpuesta:\n");
    printMatrix(&transposed);

    freeMatrix(&mat);
    freeMatrix(&transposed);

    return 0;
}
