#ifndef CIRCULOS_H
#define CIRCULOS_H

typedef struct {
    float x;
    float y;
    float r;
} Circulo;

void crearArchivoBinario(const char *nombreArchivo, int N, unsigned int semilla);
void leerArchivoBinario(const char *nombreArchivo);

#endif
