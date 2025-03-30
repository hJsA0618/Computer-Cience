#include <stdio.h>
#include "ordenar.h"

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original: ");
    imprimirArreglo(arr, n);

    ordenarIterativo(arr, n);

    printf("Arreglo ordenado: ");
    imprimirArreglo(arr, n);

    return 0;
}
