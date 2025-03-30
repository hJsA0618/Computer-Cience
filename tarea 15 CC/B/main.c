#include <stdio.h>
#include "xMinimo.h"

int main(void) {
    double a = -10.0, b = 10.0, h = 0.01;

    double x_min1 = calculaXMinimo(f1, a, b, h);
    printf("El valor de x que minimiza f(x) = x^2 es: %f\n", x_min1);

    double x_min2 = calculaXMinimo(f2, a, b, h);
    printf("El valor de x que minimiza f(x) = sin(x) es: %f\n", x_min2);

    double x_min3 = calculaXMinimo(f3, a, b, h);
    printf("El valor de x que minimiza f(x) = e^(-x^2) es: %f\n", x_min3);

    return 0;
}
