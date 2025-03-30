#include <stdio.h>
#include <stdlib.h>
#include "pila_estatica.h"

void iniPilaEstatica(PilaEstatica* p) {
    p->tope = -1;
}

int pushEstatica(PilaEstatica* p, Item valor) {
    if (p->tope >= MAX_TAM_PILA - 1) {
        return 0; 
    }
    p->tope++;
    p->datos[p->tope] = valor;
    return 1;
}

int popEstatica(PilaEstatica* p, Item* valor) {
    if (p->tope == -1) {
        return 0;
    }
    *valor = p->datos[p->tope];
    p->tope--;
    return 1;
}

int pilaVacia(PilaEstatica* p) {
    return p->tope == -1;
}

int pilaLlena(PilaEstatica* p) {
    return p->tope >= MAX_TAM_PILA - 1;
}

