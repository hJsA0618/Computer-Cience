#ifndef PILA_ESTATICA_H
#define PILA_ESTATICA_H

#define MAX_TAM_PILA 100
typedef int Item;

typedef struct {
    Item datos[MAX_TAM_PILA];
    int tope;
} PilaEstatica;

void iniPilaEstatica(PilaEstatica* p);
int pushEstatica(PilaEstatica* p, Item valor);
int popEstatica(PilaEstatica* p, Item* valor);
int pilaVacia(PilaEstatica* p);
int pilaLlena(PilaEstatica* p);


#endif
