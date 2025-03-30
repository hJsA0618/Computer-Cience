#include <stdio.h>
#include <stdlib.h>
#include "gaussiana.h"

int main(void) {
    int n = 3;
    double **A, *b, *x;

    crearMemoria(&A, &b, &x, n);
    leerDatos("matrizA.txt", "vectorB.txt", A, b, n);
    eliminacionGaussiana(A, b, n);
    sustitucionHaciaAtras(A, b, x, n);
    escribirSolucion("solucion.txt", x, n);
    liberarMemoria(A, b, x, n);

    return 0;
}
