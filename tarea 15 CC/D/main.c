#include <stdio.h>
#include <stdlib.h>
#include "pila_dinamica.h"

void pruebaPilaDinamica() {
    PilaDinamica p;
    iniPilaDinamica(&p);

    int i;
    for (i = 0; i < 5; i++) {
        pushDinamica(&p, i);
    }

    int valor;
    while (popDinamica(&p, &valor)) {
        printf("Popped: %d\n", valor);
    }

    liberarPilaDinamica(&p);
}

int main() {
    pruebaPilaDinamica();
    return 0;
}
