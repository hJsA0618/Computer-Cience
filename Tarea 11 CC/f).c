/*f) Hacer una función que recibe como parámetro un apuntador a una matriz cuadrada (la matriz
debe de ser definida como estructura, conteniendo nRens, nCols y el arreglo 2D), y deja en
ella misma su transpuesta. Usar -> en su código. Usar para todo memoria dinámica.*/


#include <stdio.h>

typedef struct {
    int nRens;   
    int nCols;   
    int **arreglo; 
} Matriz;

Matriz* crearMatriz(int n) {
    Matriz* m = (Matriz*)malloc(sizeof(Matriz));
    m->nRens = n;
    m->nCols = n; 
    m->arreglo = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        m->arreglo[i] = (int*)malloc(n * sizeof(int));
    }
    return m;
}

void liberarMatriz(Matriz* m) {
    for (int i = 0; i < m->nRens; i++) {
        free(m->arreglo[i]);
    }
    free(m->arreglo);
    free(m);
}

void imprimirMatriz(Matriz* m) {
    for (int i = 0; i < m->nRens; i++) {
        for (int j = 0; j < m->nCols; j++) {
            printf("%d ", m->arreglo[i][j]);
        }
        printf("\n");
    }
}

void transponerMatriz(Matriz* m) {
    for (int i = 0; i < m->nRens; i++) {
        for (int j = i + 1; j < m->nCols; j++) {
            int temp = m->arreglo[i][j];
            m->arreglo[i][j] = m->arreglo[j][i];
            m->arreglo[j][i] = temp;
        }
    }
}

int main() {
    int n;

    printf("Ingrese el tamano de la matriz cuadrada: ");
    scanf("%d", &n);
    Matriz* matriz = crearMatriz(n);

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz->arreglo[i][j]);
        }
    }

    printf("Matriz original:\n");
    imprimirMatriz(matriz);

    transponerMatriz(matriz);

    printf("Matriz transpuesta:\n");
    imprimirMatriz(matriz);

    liberarMatriz(matriz);

    return 0;
}