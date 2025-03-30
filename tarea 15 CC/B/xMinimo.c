#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "xMinimo.h"

double calculaXMinimo(double (*f)(double), double a, double b, double h) {
    double *x_min = (double *)malloc(sizeof(double));
    double *f_min = (double *)malloc(sizeof(double));
    double current_value;

    if (x_min == NULL || f_min == NULL) {
        printf("Error al asignar memoria dinámica.\n");
        exit(1); 
    }

    *x_min = a;
    *f_min = f(a);

    for (double x = a + h; x <= b; x += h) {
        current_value = f(x);
        if (current_value < *f_min) {
            *f_min = current_value;
            *x_min = x;
        }
    }

    double result = *x_min;
    
    free(x_min);
    free(f_min);

    return result;
}

double f1(double x) {
    return x * x;
}

double f2(double x) {
    return sin(x);
}

double f3(double x) {
    return exp(-x * x);
}
