#include <stdio.h>
#include <math.h>


double f(double x) {
    return x * x; 
}
double sumaRiemann(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double suma = 0.0;
    for (int i = 0; i < n; i++) {
        double x_mid = a + (i + 0.5) * h;
        suma += func(x_mid);  
    }

    return suma * h;
}

int main() {
    double a, b;
    int n;
    printf("Ingrese el valor de a (inicio del intervalo): ");
    scanf("%lf", &a);
    printf("Ingrese el valor de b (fin del intervalo): ");
    scanf("%lf", &b);
    printf("Ingrese el número de subintervalos n: ");
    scanf("%d", &n);
    double resultado = sumaRiemann(f, a, b, n);
    printf("La estimación de la integral es: %.6lf\n", resultado);

    return 0;
}
