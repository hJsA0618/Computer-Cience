#include <stdio.h>

float evaluar_polinomio(int grado, float coeficientes[], float x) {
    float resultado = 0.0;
    
    for (int i = grado; i >= 0; i--) {
        resultado = resultado * x + coeficientes[i];
    }
    
    return resultado;
}

int main(void) {
    float polinomio1[] = {1, -2, 1}; // x^2 - 2x + 1
    float polinomio2[] = {2, 0, -3};  // 2x^2 - 3
    float polinomio3[] = {4, -1, 0, 5}; // 4x^3 - x + 5
    int grado1 = 2; 
    int grado2 = 2; 
    int grado3 = 3; 
    float puntos[] = {0, 1, 2, 3}; 
    
    printf("Evaluando el polinomio 1 (x^2 - 2x + 1):\n");
    for (int i = 0; i < 4; i++) {
        printf("f(%f) = %f\n", puntos[i], evaluar_polinomio(grado1, polinomio1, puntos[i]));
    }
    printf("\nEvaluando el polinomio 2 (2x^2 - 3):\n");
    for (int i = 0; i < 4; i++) {
        printf("f(%f) = %f\n", puntos[i], evaluar_polinomio(grado2, polinomio2, puntos[i]));
    }
    printf("\nEvaluando el polinomio 3 (4x^3 - x + 5):\n");
    for (int i = 0; i < 4; i++) {
        printf("f(%f) = %f\n", puntos[i], evaluar_polinomio(grado3, polinomio3, puntos[i]));
    }
    return 0;
}