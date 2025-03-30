#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Complejo.h"

float magnitud(Complejo c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

int cmpfunc(const void *a, const void *b) {
    Complejo *c1 = (Complejo *)a;
    Complejo *c2 = (Complejo *)b;

    float mag1 = magnitud(*c1);
    float mag2 = magnitud(*c2);

    if (mag1 < mag2) return -1;
    if (mag1 > mag2) return 1;
    return 0;
}

void printAndSort(Complejo *vals, int N, int (*funComp)(const void *, const void *)) {
    printf("Before sorting the list is: \n");
    for (int n = 0; n < N; n++) {
        printf("Complex number %d: %.2f + %.2fi\n", n+1, vals[n].real, vals[n].imag);
    }

    qsort(vals, N, sizeof(Complejo), funComp);

    printf("\nAfter sorting the list is: \n");
    for (int n = 0; n < N; n++) {
        printf("Complex number %d: %.2f + %.2fi\n", n+1, vals[n].real, vals[n].imag);
    }
    printf("\n");
}
