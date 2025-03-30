#include <stdio.h>
#include <stdlib.h>
#include "torres_hanoi.h"  // Incluir el archivo de cabecera

void mostrarTorres(pila_estatica *A, pila_estatica *B, pila_estatica *C) {
    int i;
    Item disc;
    
    system("cls");

    for (i = MAX_SIZE_PILA - 1; i >= 0; i--) {
        if (i < A->tope) {
            printf("| %d |  ", A->dat[i]);
        } else {
            printf("|   |  ");
        }
        
        if (i < B->tope) {
            printf("| %d |  ", B->dat[i]);
        } else {
            printf("|   |  ");
        }
        
        if (i < C->tope) {
            printf("| %d |  ", C->dat[i]);
        } else {
            printf("|   |  ");
        }
        
        printf("\n");
    }
    
    printf("|___|  |___|  |___|\n");
    printf("  A     B     C \n");
}

void moverDisco(pila_estatica *from, pila_estatica *to, Item *disco) {
    popEstatica(from, disco);
    pushEstatica(to, *disco);
}

void hanoi(int n, pila_estatica *A, pila_estatica *B, pila_estatica *C) {
    Item disco;
    if (n == 1) {
        popEstatica(A, &disco);
        pushEstatica(C, disco);
        mostrarTorres(A, B, C);
        getchar();  // Espera de Enter para continuar
    } else {
        hanoi(n - 1, A, C, B);
        popEstatica(A, &disco);
        pushEstatica(C, disco);
        mostrarTorres(A, B, C);
        getchar();  // Espera de Enter para continuar
        hanoi(n - 1, B, A, C);
    }
}
