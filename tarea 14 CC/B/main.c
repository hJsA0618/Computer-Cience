#include <stdio.h>
#include "circulos.h"

int main(void) {
    int N = 5;
    unsigned int semilla = 12345;

    crearArchivoBinario("circulos.dat", N, semilla);
    leerArchivoBinario("circulos.dat");

    return 0;
}
