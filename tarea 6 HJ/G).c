/*g) Hacer un programa que declara un arreglo grande de floats y los
llena con números aleatorios entre 0 y 1. Hacer una función que recorra
el arreglo y cuente e indique en pantalla cuantos números son menores que 0.7 .*/

#include <stdio.h>
#include <stdlib.h>

#define N 100

void imprimeVectorFloat(float miVec[], int n);
int contarMenoresQue(float miVec[], int n, float limite);

void imprimeVectorFloat(float miVec[], int n) {
    printf("\n--------------");
    for (int i = 0; i < n; i++) {
        printf("\npos=%d,\tvalor=%f", i, miVec[i]);
    }
    printf("\n--------------");
}

int contarMenoresQue(float miVec[], int n, float limite) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (miVec[i] < limite) {
            contador++;
        }
    }
    return contador;
}

int main(void) {
    float vec[N];

    for (int i = 0; i < N; i++) {
        vec[i] = (float)rand() / RAND_MAX;
    }

    imprimeVectorFloat(vec, N);
    int conteo = contarMenoresQue(vec, N, 0.7);
    printf("\nCantidad de numeros menores que 0.7: %d\n", conteo);

    return 0;
}
