#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int filas;
    int columnas;
    int **data;
} Matriz;

void crearMatriz(Matriz *m, int filas, int columnas) {
    m->filas = filas;
    m->columnas = columnas;

    m->data = (int **)malloc(filas * sizeof(int *));
    for (int i = 0; i < filas; i++) {
        m->data[i] = (int *)malloc(columnas * sizeof(int));
    }
}

void transponerMatriz(Matriz *m, Matriz *transpuesta) {
    crearMatriz(transpuesta, m->columnas, m->filas);
    for (int i = 0; i < m->filas; i++) {
        for (int j = 0; j < m->columnas; j++) {
            transpuesta->data[j][i] = m->data[i][j];
        }
    }
}

void multiplicarMatrices(Matriz *m1, Matriz *m2, Matriz *producto) {
    if (m1->columnas != m2->filas) {
        fprintf(stderr, "No se puede multiplicar: dimensiones incompatibles.\n");
        return;
    }

    crearMatriz(producto, m1->filas, m2->columnas);
    for (int i = 0; i < producto->filas; i++) {
        for (int j = 0; j < producto->columnas; j++) {
            producto->data[i][j] = 0;
            for (int k = 0; k < m1->columnas; k++) {
                producto->data[i][j] += m1->data[i][k] * m2->data[k][j];
            }
        }
    }
}

void imprimirMatriz(Matriz *m) {
    for (int i = 0; i < m->filas; i++) {
        for (int j = 0; j < m->columnas; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

void liberarMatriz(Matriz *m) {
    for (int i = 0; i < m->filas; i++) {
        free(m->data[i]);
    }
    free(m->data);
}

int main() {
    Matriz m1, m2, m_transpuesta, resultado;

    printf("Ejemplo 1: Multiplicacion valida de matrices\n");
    crearMatriz(&m1, 2, 3); 
    m1.data[0][0] = 1; m1.data[0][1] = 2; m1.data[0][2] = 3;
    m1.data[1][0] = 4; m1.data[1][1] = 5; m1.data[1][2] = 6;

    crearMatriz(&m2, 3, 2); 
    m2.data[0][0] = 7; m2.data[0][1] = 8;
    m2.data[1][0] = 9; m2.data[1][1] = 10;
    m2.data[2][0] = 11; m2.data[2][1] = 12;

    printf("Matriz 1:\n");
    imprimirMatriz(&m1);
    printf("Matriz 2:\n");
    imprimirMatriz(&m2);

    multiplicarMatrices(&m1, &m2, &resultado);
    printf("Resultado de la multiplicacion:\n");
    imprimirMatriz(&resultado);

    liberarMatriz(&resultado);
    liberarMatriz(&m1);
    liberarMatriz(&m2);
    printf("\nEjemplo 2: Multiplicacion invalida de matrices\n");

    Matriz m3, m4;
    crearMatriz(&m3, 3, 2); 
    m3.data[0][0] = 1; m3.data[0][1] = 2;
    m3.data[1][0] = 3; m3.data[1][1] = 4;
    m3.data[2][0] = 5; m3.data[2][1] = 6;

    crearMatriz(&m4, 3, 2); 
    m4.data[0][0] = 7; m4.data[0][1] = 8;
    m4.data[1][0] = 9; m4.data[1][1] = 10;
    m4.data[2][0] = 11; m4.data[2][1] = 12;

    printf("Matriz 3:\n");
    imprimirMatriz(&m3);
    printf("Matriz 4:\n");
    imprimirMatriz(&m4);

    multiplicarMatrices(&m3, &m4, &resultado); 
    liberarMatriz(&resultado); 
    liberarMatriz(&m3);
    liberarMatriz(&m4);

    return 0;
}
