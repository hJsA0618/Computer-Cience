#ifndef TORRES_HANOI_H
#define TORRES_HANOI_H

#include "pila.h"

void mostrarTorres(pila_estatica *A, pila_estatica *B, pila_estatica *C);
void moverDisco(pila_estatica *from, pila_estatica *to, Item *disco);
void hanoi(int n, pila_estatica *A, pila_estatica *B, pila_estatica *C);

#endif 