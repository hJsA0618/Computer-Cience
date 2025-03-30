#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void iniPilaEstatica(pila_estatica *p) {
    p->tope = 0;
    p->dat = (Item *)malloc(MAX_SIZE_PILA * sizeof(Item));
    if (p->dat == NULL) {
        exit(1);
    }
}

int pushEstatica(pila_estatica *p, Item item) {
    if (p->tope >= MAX_SIZE_PILA) {
        return ERROR_PILA_LLENA;
    }
    p->dat[p->tope] = item;
    p->tope++;
    return 0;
}

int popEstatica(pila_estatica *p, Item *item) {
    if (p->tope == 0) {
        return ERROR_PILA_VACIA;
    }
    p->tope--;
    *item = p->dat[p->tope];
    return 0;
}

void liberarPilaEstatica(pila_estatica *p) {
    free(p->dat);
}
