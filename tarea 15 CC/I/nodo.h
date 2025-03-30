#ifndef NODO_H
#define NODO_H

typedef struct Nodo {
    int obj;
    struct Nodo *ptr;
} nodo;

nodo* createNode(int el_obj);
void insertarOrdenado(nodo **lista, int valor);

#endif // NODO_H
