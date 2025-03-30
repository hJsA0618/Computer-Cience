#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double f(double x) {
    return exp(-x * x);  
}

double integracionMonteCarlo(double (*func)(double), double a, double b, int n) {
    double suma = 0.0;
    double x;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {

        x = a + (b - a) * ((double)rand() / RAND_MAX);
        suma += func(x);
    }
    return (b - a) * suma / n;
}

int main() {
    double a, b;
    int n;
    printf("Ingrese el valor de a (inicio del intervalo): ");
    scanf("%lf", &a);
    printf("Ingrese el valor de b (fin del intervalo): ");
    scanf("%lf", &b);
    printf("Ingrese el número de puntos aleatorios n: ");
    scanf("%d", &n);

    double resultado = integracionMonteCarlo(f, a, b, n);
    printf("La estimación de la integral por Monte Carlo es: %.6lf\n", resultado);

    return 0;
}
