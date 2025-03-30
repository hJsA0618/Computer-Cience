#include <stdio.h>
#include <stdlib.h>

int esPrimo(int num) {
    if (num <= 1) return 0; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int filtrarPrimosYMultiplo(int vecA[], int vecB[], int N, int val) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (esPrimo(vecA[i]) || (vecA[i] % val == 0)) {
            vecB[count] = vecA[i];
            count++;
        }
    }
    return count; 
}

int main() {
    int N = 10;     int vecA[N];
    int vecB[N];
    int val;


    int semilla;
    printf("Ingresa la semilla para los numeros aleatorios: ");
    scanf("%d", &semilla);
    srand(semilla); 

    for (int i = 0; i < N; i++) {
        vecA[i] = rand() % 100; // Números aleatorios entre 0 y 99
    }

    
    printf("Contenido de vecA: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", vecA[i]);
    }
    printf("\n");

        printf("Ingresa un valor para filtrar múltiplos: ");
    scanf("%d", &val);

    
    int cantidad = filtrarPrimosYMultiplo(vecA, vecB, N, val);

    
    printf("Contenido de vecB (primos o multiplos de %d): ", val);
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", vecB[i]);
    }
    printf("\n");

    return 0;
}
