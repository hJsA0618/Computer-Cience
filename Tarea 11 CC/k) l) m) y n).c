#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    double *vector; 
} Vector;

typedef struct {
    int nRens;
    int nCols;
    double **matriz;
} Matrix;

// k) Declarar el nuevo tipo de dato Vector que es una estructura conteniendo un apuntador y el tamaño del vector
Vector createVector(int size) {
    Vector vec;
    vec.size = size;
    vec.vector = (double *)malloc(size * sizeof(double));
    return vec;
}

void freeVector(Vector *vec) {
    free(vec->vector);
    vec->vector = NULL;
}

// l) Programar una función que calcula el producto de un escalar por un vector
Vector scalarProduct(double scalar, const Vector *vec) {
    Vector result = createVector(vec->size);
    for (int i = 0; i < vec->size; i++) {
        result.vector[i] = scalar * vec->vector[i];
    }
    return result;
}

// m) Programar una función que calcula el producto interno de 2 vectores
double dotProduct(const Vector *vec1, const Vector *vec2) {
    if (vec1->size != vec2->size) {
        fprintf(stderr, "Error: Los vectores deben tener las mismas dimensiones.\n");
        exit(EXIT_FAILURE);
    }
    double result = 0.0;
    for (int i = 0; i < vec1->size; i++) {
        result += vec1->vector[i] * vec2->vector[i];
    }
    return result;
}

// n) Programar una función que calcula el producto matriz * vector
Vector matrixVectorProduct(const Matrix *mat, const Vector *vec) {
    if (mat->nCols != vec->size) {
        fprintf(stderr, "Error: Las dimensiones de la matriz y el vector no permiten la operación.\n");
        exit(EXIT_FAILURE);
    }
    Vector result = createVector(mat->nRens);
    for (int i = 0; i < mat->nRens; i++) {
        result.vector[i] = 0.0;
        for (int j = 0; j < mat->nCols; j++) {
            result.vector[i] += mat->matriz[i][j] * vec->vector[j];
        }
    }
    return result;
}

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

void freeMatrix(Matrix *mat) {
    for (int i = 0; i < mat->nRens; i++) {
        free(mat->matriz[i]);
    }
    free(mat->matriz);
    mat->matriz = NULL;
}

void printVector(const Vector *vec) {
    for (int i = 0; i < vec->size; i++) {
        printf("%lf ", vec->vector[i]);
    }
    printf("\n");
}

void printMatrix(const Matrix *mat) {
    for (int i = 0; i < mat->nRens; i++) {
        for (int j = 0; j < mat->nCols; j++) {
            printf("%lf ", mat->matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Vector vec1 = createVector(3);
    vec1.vector[0] = 1.0;
    vec1.vector[1] = 2.0;
    vec1.vector[2] = 3.0;

    printf("Vector original:\n");
    printVector(&vec1);

    double scalar = 2.0;
    Vector scaledVector = scalarProduct(scalar, &vec1);
    printf("Producto escalar:\n");
    printVector(&scaledVector);

    Vector vec2 = createVector(3);
    vec2.vector[0] = 4.0;
    vec2.vector[1] = 5.0;
    vec2.vector[2] = 6.0;

    double dotProd = dotProduct(&vec1, &vec2);
    printf("Producto interno: %lf\n", dotProd);

    Matrix mat = createMatrix(3, 3);
    mat.matriz[0][0] = 1.0; mat.matriz[0][1] = 2.0; mat.matriz[0][2] = 3.0;
    mat.matriz[1][0] = 4.0; mat.matriz[1][1] = 5.0; mat.matriz[1][2] = 6.0;
    mat.matriz[2][0] = 7.0; mat.matriz[2][1] = 8.0; mat.matriz[2][2] = 9.0;

    printf("Matriz:\n");
    printMatrix(&mat);

    Vector resultVector = matrixVectorProduct(&mat, &vec1);
    printf("Producto matriz * vector:\n");
    printVector(&resultVector);

    freeVector(&vec1);
    freeVector(&scaledVector);
    freeVector(&vec2);
    freeMatrix(&mat);
    freeVector(&resultVector);

    return 0;
}
