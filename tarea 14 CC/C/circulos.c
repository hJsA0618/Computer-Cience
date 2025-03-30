#include <stdio.h>
#include <stdlib.h>
#include "circulos.h"
#include <math.h>

void leerArchivoBinario(const char *nombreArchivo, Circulo **circulos, int *n) {
    FILE *file = fopen(nombreArchivo, "rb");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    fread(n, sizeof(int), 1, file); 
    *circulos = (Circulo *)malloc(*n * sizeof(Circulo));
    if (*circulos == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    fread(*circulos, sizeof(Circulo), *n, file);

    fclose(file);
}

int contarTraslapes(Circulo *circulos, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float dx = circulos[i].x - circulos[j].x;
            float dy = circulos[i].y - circulos[j].y;
            float distanciaCuadrada = dx * dx + dy * dy;
            float sumaRadios = circulos[i].r + circulos[j].r;
            if (distanciaCuadrada < sumaRadios * sumaRadios) {
                count++; 
            }
        }
    }
    return count;
}
