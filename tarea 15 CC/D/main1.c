#include <stdio.h>
#include "pila_estatica.h"

void pruebaPilaEstatica() {
    PilaEstatica p;
    iniPilaEstatica(&p);

    int i;
    for (i = 0; i < 5; i++) {
        if (!pushEstatica(&p, i)) {
            printf("Pila llena, no se puede insertar el valor: %d\n", i);
        }
    }

    int valor;
    while (popEstatica(&p, &valor)) {
        printf("Popped: %d\n", valor);
    }
}


int main() {
    pruebaPilaEstatica();
    return 0;
}
