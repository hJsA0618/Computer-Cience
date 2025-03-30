#ifndef COMPLEJO_H
#define COMPLEJO_H

typedef struct {
    float real;
    float imag;
} Complejo;

float magnitud(Complejo c);
int cmpfunc(const void *a, const void *b);
void printAndSort(Complejo *vals, int N, int (*funComp)(const void *, const void *));

#endif 
