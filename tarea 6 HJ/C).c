#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

void imprimeVectores(float x[], float y[], int n) {
    printf("\n--------------");
    for (int i = 0; i < n; i++) {
        printf("\nX=%.2f,\tY=%.2f", x[i], y[i]);
    }
    printf("\n--------------");
}

int main(void) {
    float x[N], y[N], theta, cx, cy;

    // Pedir las coordenadas del centro del círculo de radio 2
    printf("Dime las coordenadas para tu centro del círculo con radio 2 (cx cy): ");
    scanf("%f %f", &cx, &cy); // Leer las coordenadas

    // Generar coordenadas (x, y) en el primer cuadrante
    for (int i = 0; i < N; i++) {
        x[i] = ((float)rand() / RAND_MAX) * 5; 
        y[i] = ((float)rand() / RAND_MAX) * 5; 
    }
    
    printf("Coordenadas en el primer cuadrante:\n");
    imprimeVectores(x, y, N);
    
    // Generar coordenadas (x, y) en el círculo de radio 1 con centro en (0, 0)
    printf("\nCoordenadas en el círculo de radio 1:\n");
    for (int i = 0; i < N; i++) {
        theta = ((float)rand() / RAND_MAX) * 2 * M_PI; // Genera un ángulo aleatorio
        x[i] = cos(theta); // x = cos(θ)
        y[i] = sin(theta); // y = sin(θ)
    }
    imprimeVectores(x, y, N); // Imprimir fuera del bucle

    // Generar coordenadas (x, y) en el círculo de radio 2 con centro en (cx, cy)
    printf("\nCoordenadas en el círculo de radio 2:\n");
    for (int i = 0; i < N; i++) {
        theta = ((float)rand() / RAND_MAX) * 2 * M_PI; // Genera un ángulo aleatorio
        x[i] = cx + 2 * cos(theta); // x = cx + 2 * cos(θ)
        y[i] = cy + 2 * sin(theta); // y = cy + 2 * sin(θ)
    }
    imprimeVectores(x, y, N);
    
    return 0;
}

