#include <stdio.h>
#include "suma.h"

int main() {
    int vector[] = {1, 2, 3, 4, 5};
    int n = sizeof(vector) / sizeof(vector[0]);
    
    int suma = sumaRecursiva(vector, n);
    
    printf("La suma de los elementos del vector es: %d\n", suma);
    
    return 0;
}
