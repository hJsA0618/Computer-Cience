#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

int main(void) {
    nodo *lista = NULL;
    int tamano_lista = 10;

    insertarOrdenado(&lista, rand() % 100);

    for (int i = 1; i < tamano_lista; i++) {
        insertarOrdenado(&lista, rand() % 100);
    }

    printf("\n");
    nodo *aux = lista;
    while (aux != NULL) {
        printf("<Elem = %d> ", aux->obj);
        aux = aux->ptr;
    }
    printf("\n");

    aux = lista;
    while (aux != NULL) {
        nodo* temp = aux->ptr;
        free(aux);
        aux = temp;
    }

    return 0;
}
