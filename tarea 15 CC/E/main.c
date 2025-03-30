#include <stdio.h>
#include "pila.h"
#include "torres_hanoi.h" 

int main() {
    pila_estatica A, B, C;
    iniPilaEstatica(&A);
    iniPilaEstatica(&B);
    iniPilaEstatica(&C);

    for (int i = MAX_SIZE_PILA; i > 0; i--) {
        pushEstatica(&A, i);
    }

    printf("Estado inicial de las torres:\n");
    mostrarTorres(&A, &B, &C);

    getchar(); 

    hanoi(MAX_SIZE_PILA, &A, &B, &C);

    liberarPilaEstatica(&A);
    liberarPilaEstatica(&B);
    liberarPilaEstatica(&C);

    return 0;
}
