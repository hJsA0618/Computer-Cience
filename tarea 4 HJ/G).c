#include <stdio.h>
#include <math.h>
#include <limits.h> //Para que no se valla al infinito

unsigned long long mi_fact(unsigned int v) {
    unsigned long long r = 1;
    for (int i = 2; i <= v; i++) {
        r *= i;
        if (r > ULLONG_MAX / i) {
            // Factorial demasiado grande
            return ULLONG_MAX;
        }
    }
    return r;
}

double exp(double x) {
    double value = 0;
    double term = 1; // x^0 / 0! = 1
    int n = 0;

    while (fabs(term) > 1e-10) { // Terminar cuando el término es suficientemente pequeño
        value += term;
        n++;
        term *= x / n;
    }

    return value;
}

int main() {
    double x;
    printf("Introduce el valor de x para calcular exp(x): ");
    scanf("%lf", &x);

    double result = exp(x);
    printf("exp(%f) = %.10f\n", x, result);

    return 0;
}

