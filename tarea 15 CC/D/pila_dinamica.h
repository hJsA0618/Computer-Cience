#ifndef PILA_DINAMICA_H
#define PILA_DINAMICA_H

typedef int Item;

typedef struct Nodo {
    Item valor;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* tope;
} PilaDinamica;

void iniPilaDinamica(PilaDinamica* p);
int pushDinamica(PilaDinamica* p, Item valor);
int popDinamica(PilaDinamica* p, Item* valor);
void liberarPilaDinamica(PilaDinamica* p);

#endif
