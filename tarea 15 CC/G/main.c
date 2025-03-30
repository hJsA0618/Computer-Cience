#include <stdio.h>
#include <stdlib.h>
#include "lee_impares.h"

int main(void) {
    int m;
    int* impares = leeImpares2Enteros("file_numbers_0_100.txt", &m);

    if (impares != NULL) {
        printf("Numeros impares leidos del archivo:\n");
        for (int i = 0; i < m; i++) {
            printf("%d ", impares[i]);
        }
        printf("\n");

        free(impares); 
    } else {
        printf("No se pudieron leer los numeros impares.\n");
    }

    return 0;
}
