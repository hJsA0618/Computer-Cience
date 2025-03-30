#include <stdio.h>

void sumarPolinomios(float* polinomio1, int grado1, float* polinomio2, int grado2, float* resultado) {
    int max_grado = (grado1 > grado2) ? grado1 : grado2;

    for (int i = 0; i <= max_grado; i++) {
        resultado[i] = 0;
    }

    for (int i = 0; i <= grado1; i++) {
        resultado[max_grado - grado1 + i] += polinomio1[i];
    }

    for (int i = 0; i <= grado2; i++) {
        resultado[max_grado - grado2 + i] += polinomio2[i];
    }
}

void imprimirPolinomio(float* polinomio, int grado) {
    for (int i = 0; i <= grado; i++) {
        printf("%+.2f*x^%d ", polinomio[i], grado - i);
    }
    printf("\n");
}

int main(void) {
    float polinomio1[] = {2, 3, 4};
    int grado1 = 2;
    float polinomio2[] = {1, 0, 2};
    int grado2 = 2;
    float resultado1[grado1 > grado2 ? grado1 + 1 : grado2 + 1];

    sumarPolinomios(polinomio1, grado1, polinomio2, grado2, resultado1);

    printf("Polinomio 1: ");
    imprimirPolinomio(polinomio1, grado1);
    printf("Polinomio 2: ");
    imprimirPolinomio(polinomio2, grado2);
    printf("Suma de Polinomios: ");
    imprimirPolinomio(resultado1, (grado1 > grado2) ? grado1 : grado2);

    float polinomio3[] = {3, -1, 0, 1};
    int grado3 = 3;
    float polinomio4[] = {5, 2, 0};
    int grado4 = 2;
    float resultado2[grado3 + 1];

    sumarPolinomios(polinomio3, grado3, polinomio4, grado4, resultado2);

    printf("\nPolinomio 3: ");
    imprimirPolinomio(polinomio3, grado3);
    printf("Polinomio 4: ");
    imprimirPolinomio(polinomio4, grado4);
    printf("Suma de Polinomios: ");
    imprimirPolinomio(resultado2, (grado3 > grado4) ? grado3 : grado4);

    return 0;
}
