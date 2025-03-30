#include <stdio.h>
#include <stdlib.h>
#include "gaussiana.h"

//<------------------------- funciones prototipo ------------------------------------->//
void leerDatos(const char *fileA, const char *fileB, double **A, double *b, int n );
void eliminacionGaussiana(double **A,double *b, int n);
void sustitucionHaciaAtras(double **A, double *b, double *x, int n);



//<------------------------------------- funciones----------------------------------------->//
void leerDatos(const char *archivoA, const char *archivoB, double **A, double *b, int n) {
    FILE *fileA = fopen(archivoA, "r");
    FILE *fileB = fopen(archivoB, "r");
    if (fileA == NULL || fileB == NULL) {
        printf("Error al abrir los archivos: %s o %s\n", archivoA, archivoB);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(fileA, "%lf", &A[i][j]) != 1) {
                printf("Error al leer el elemento A[%d][%d] del archivo %s\n", i, j, archivoA);
                exit(1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (fscanf(fileB, "%lf", &b[i]) != 1) {
            printf("Error al leer el elemento b[%d] del archivo %s\n", i, archivoB);
            exit(1);
        }
    }

    fclose(fileA);
    fclose(fileB);
}

void eliminacionGaussiana(double **A,double *b, int n){
    for (int k = 0; k < n; k++)
    {
        double max=A[k][k];
        int filaMax=k;
        for (int i = k+1; i < n; i++)
        {
            if (A[i][k]>max)
            {
                max=A[i][k];
                filaMax=i;
            }
            
        }
        if (filaMax!=k)
        {
            for (int j = 0; j < n; j++)
            {
                double temp=A[k][j];
                A[k][j] = A[filaMax][j];
                A[filaMax][j] = temp;
            }
            double temp = b[k];
            b[k] = b[filaMax];
            b[filaMax] = temp;
        }
        for (int i = k+1; i < n; i++)
        {
            double factor = A[i][k]/A[k][k];
            b[i] -= factor * b[k];
            for (int j = 0; j < n; j++)
            {
                A[i][j]-= factor *A[k][j];
            } 
        }
    }    
}


void sustitucionHaciaAtras(double **A, double *b, double *x, int n){
    for (int i = n-1; i >= 0; i--)
    {
        x[i]=b[i];
        for (int j = i+1; j < n; j++)
        {
            x[i] -= A[i][j] * x[j];
        }
        x[i]/=A[i][i];
    }
}

void escribirSolucion(const char *archivo, double *x, int n) {
    FILE *file = fopen(archivo, "w");
    if (file == NULL) {
        printf("Error al abrir el archivo para escribir la solución.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%.6lf\n", x[i]);
    }

    fclose(file);
}
//<------------------creación de memoria -------------------->//
void crearMemoria(double ***A, double **b, double **x, int n) {
    *A = (double **)malloc(n * sizeof(double *));
    if (*A == NULL) {
        printf("Error al reservar memoria para la matriz A.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        (*A)[i] = (double *)malloc(n * sizeof(double));
        if ((*A)[i] == NULL) {
            printf("Error al reservar memoria para la fila %d de la matriz A.\n", i);
            exit(1);
        }
    }
    *b = (double *)malloc(n * sizeof(double));
    if (*b == NULL) {
        printf("Error al reservar memoria para el vector b.\n");
        exit(1);
    }
    *x = (double *)malloc(n * sizeof(double));
    if (*x == NULL) {
        printf("Error al reservar memoria para el vector x.\n");
        exit(1);
    }
}
void liberarMemoria(double **A, double *b, double *x, int n) {
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);
}