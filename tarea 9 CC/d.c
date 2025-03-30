#include <stdio.h>

void calcularIntegral(double* polinomio, int grado, double* integral) {
    for (int i = 0; i <= grado; i++) {
        integral[i + 1] = polinomio[i] / (i + 1); 
    }
    integral[0] = 0; 
}

void imprimirPolinomio(double* polinomio, int grado) {
    for (int i = 0; i <= grado; i++) {
        printf("%+.2fx^%d ", polinomio[i], grado - i);
    }
    printf("\n");
}

int main(void) {
    double polinomio1[] = {3, 2, 1}; 
    int grado1 = 2;
    double integral1[grado1 + 2]; 
    calcularIntegral(polinomio1, grado1, integral1);

    printf("Polinomio 1: ");
    imprimirPolinomio(polinomio1, grado1);
    printf("Integral del Polinomio 1: ");
    imprimirPolinomio(integral1, grado1 + 1);

    double polinomio2[] = {4, -2, 0, 5}; 
    int grado2 = 3;
    double integral2[grado2 + 2]; 

    calcularIntegral(polinomio2, grado2, integral2);

    printf("\nPolinomio 2: ");
    imprimirPolinomio(polinomio2, grado2);
    printf("Integral del Polinomio 2: ");
    imprimirPolinomio(integral2, grado2 + 1);

    return 0;
}
