#include <stdio.h>
#include <stdlib.h>

int compararFloats(const void *a, const void *b) {
    return (*(float *)a > *(float *)b) - (*(float *)a < *(float *)b);
}

void obtenerMinimos(float vecA[], float vecB[], int N, int M) {
    qsort(vecA, N, sizeof(float), compararFloats);

    for (int i = 0; i < M; i++) {
        vecB[i] = vecA[i];
    }
}

int main() {
    int N, M;
    
    printf("Ingresa el tamano de vecA (N): ");
    scanf("%d", &N);
    printf("Ingresa el tamano de vecB (M, debe ser menor que N): ");
    scanf("%d", &M);
    
    if (M >= N) {
        printf("El tamano de vecB debe ser menor que el tamano de vecA.\n");
        return 1;
    }
    float vecA[N];
    float vecB[M];
    int semilla;
    printf("Ingresa la semilla para los numeros aleatorios: ");
    scanf("%d", &semilla);
    srand(semilla);
    for (int i = 0; i < N; i++) {
        vecA[i] = (float)(rand() % 100) + (float)(rand() % 100) / 100; // Números aleatorios entre 0 y 99.99
    }
    printf("Contenido de vecA: ");
    for (int i = 0; i < N; i++) {
        printf("%.2f ", vecA[i]);
    }
    printf("\n");
    obtenerMinimos(vecA, vecB, N, M);
    printf("Contenido de vecB (M numeros mas pequenos): ");
    for (int i = 0; i < M; i++) {
        printf("%.2f ", vecB[i]);
    }
    printf("\n");
    return 0;
}
