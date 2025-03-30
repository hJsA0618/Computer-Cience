#ifndef PILA_H
#define PILA_H

#define MAX_SIZE_PILA 4
#define ERROR_PILA_LLENA 1
#define ERROR_PILA_VACIA 2

typedef int Item;

typedef struct {
    int tope;
    Item *dat;
} pila_estatica;

typedef struct Nodo {
    Item dato;
    struct Nodo *siguiente;
} Nodo;

typedef struct {
    Nodo *tope;
} pila_dinamica;

void iniPilaEstatica(pila_estatica *p);
int pushEstatica(pila_estatica *p, Item item);
int popEstatica(pila_estatica *p, Item *item);
void liberarPilaEstatica(pila_estatica *p);

void iniPilaDinamica(pila_dinamica *p);
int pushDinamica(pila_dinamica *p, Item item);
int popDinamica(pila_dinamica *p, Item *item);
void liberarPilaDinamica(pila_dinamica *p);

#endif
