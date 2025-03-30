#include <stdio.h>
#include <stdlib.h>
#include "pila_dinamica.h"

void iniPilaDinamica(PilaDinamica* p) {
    p->tope = NULL;
}

int pushDinamica(PilaDinamica* p, Item valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        return 0;
    }
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = p->tope;
    p->tope = nuevoNodo;
    return 1;
}

int popDinamica(PilaDinamica* p, Item* valor) {
    if (p->tope == NULL) {
        return 0;
    }
    Nodo* temp = p->tope;
    *valor = temp->valor;
    p->tope = p->tope->siguiente;
    free(temp);
    return 1;
}

void liberarPilaDinamica(PilaDinamica* p) {
    Nodo* temp;
    while (p->tope != NULL) {
        temp = p->tope;
        p->tope = p->tope->siguiente;
        free(temp);
    }
}
