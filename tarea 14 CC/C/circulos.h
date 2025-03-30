#ifndef CIRCULOS_H
#define CIRCULOS_H

typedef struct {
    float x, y, r;
} Circulo;

void leerArchivoBinario(const char *nombreArchivo, Circulo **circulos, int *n);
int contarTraslapes(Circulo *circulos, int n);

#endif
