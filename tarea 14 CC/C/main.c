#include <stdio.h>
#include <stdlib.h>
#include "circulos.h"

int main(void) {
    Circulo *circulos = NULL;
    int n = 0;

    leerArchivoBinario("circulos.dat", &circulos, &n); 

    int traslapes = contarTraslapes(circulos, n); 
    printf("Número de iírculos que se traslapan: %d\n", traslapes);

    free(circulos); 
    return 0;
}
