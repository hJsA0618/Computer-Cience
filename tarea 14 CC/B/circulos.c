#include <stdio.h>
#include <stdlib.h>
#include "circulos.h"

void crearArchivoBinario(const char *nombreArchivo, int N, unsigned int semilla) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    srand(semilla);

    fwrite(&N, sizeof(int), 1, archivo);

    for (int i = 0; i < N; i++) {
        Circulo c;
        c.x = (float)(rand() % 101) / 10.0;
        c.y = (float)(rand() % 101) / 10.0;
        c.r = (float)(rand() % 191) / 100.0 + 0.1;

        fwrite(&c, sizeof(Circulo), 1, archivo);
    }

    fclose(archivo);
}

void leerArchivoBinario(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(1);
    }

    int N;
    fread(&N, sizeof(int), 1, archivo);

    Circulo *circulos = (Circulo *)malloc(N * sizeof(Circulo));
    if (circulos == NULL) {
        perror("Error al asignar memoria");
        exit(1);
    }

    fread(circulos, sizeof(Circulo), N, archivo);

    for (int i = 0; i < N; i++) {
        printf("Circulo %d: x = %.2f, y = %.2f, r = %.2f\n", i + 1, circulos[i].x, circulos[i].y, circulos[i].r);
    }

    free(circulos);
    fclose(archivo);
}
