#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

nodo* createNode(int el_obj) {
    nodo* ret = (nodo*) malloc(sizeof(nodo));
    ret->obj = el_obj;
    ret->ptr = NULL;
    return ret;
}

void insertarOrdenado(nodo **lista, int valor) {
    nodo *newNode = createNode(valor);
    nodo *current = *lista;
    nodo *prev = NULL;

    if (current == NULL || current->obj >= valor) {
        newNode->ptr = current;
        *lista = newNode;
    } else {
        while (current != NULL && current->obj < valor) {
            prev = current;
            current = current->ptr;
        }
        prev->ptr = newNode;
        newNode->ptr = current;
    }
}
