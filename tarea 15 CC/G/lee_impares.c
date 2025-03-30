#include <stdio.h>
#include <stdlib.h>
#include "lee_impares.h"

int* leeImpares2Enteros(char *nombreArchivo, int *m) {
    FILE *file = fopen(nombreArchivo, "r");
    if (!file) {
        perror("Error al abrir el archivo");
        *m = 0;
        return NULL;
    }

    fscanf(file, "%d", m);  

    int *numeros = (int*) malloc(sizeof(int) * (*m));
    if (!numeros) {
        perror("Error de memoria");
        *m = 0;
        fclose(file);
        return NULL;
    }

    int num;
    int count = 0;
    while (fscanf(file, "%d", &num) == 1) {
        if (num % 2 != 0) {  
            numeros[count++] = num;
        }
    }

    *m = count;
    fclose(file);
    return numeros;
}
