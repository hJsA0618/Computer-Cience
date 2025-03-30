#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int* coeficientes; 
    int* exponentes;   
    int grado;         
} poly;

poly crearPolinomio(int grado) {
    poly p;
    p.grado = grado;
    p.coeficientes = (int*)malloc((grado + 1) * sizeof(int));
    p.exponentes = (int*)malloc((grado + 1) * sizeof(int));

    for (int i = 0; i <= grado; i++) {
        printf("Ingresa el coeficiente para x^%d: ", i);
        scanf("%d", &p.coeficientes[i]);
        p.exponentes[i] = i;     }

    return p;
}
float evaluarPolinomio(poly p, float x) {
    float resultado = 0;
    for (int i = 0; i <= p.grado; i++) {
        resultado += p.coeficientes[i] * pow(x, p.exponentes[i]);
    }
    return resultado;
}

void liberarPolinomio(poly* p) {
    free(p->coeficientes);
    free(p->exponentes);
}

int main() {
    int grado;

    printf("Ingresa el grado del polinomio: ");
    scanf("%d", &grado);

    poly p = crearPolinomio(grado);

    float x;
    printf("Ingresa el valor de x para evaluar el polinomio: ");
    scanf("%f", &x);

    float resultado = evaluarPolinomio(p, x);
    printf("El resultado de evaluar el polinomio en x=%.2f es: %.2f\n", x, resultado);

    liberarPolinomio(&p);
    return 0;
}
