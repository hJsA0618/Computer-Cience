/*j) Llenar un vector de tipo char de tamaño 1000 con caracteres (de
manera aleatoria con letras de la 'a' a la 'z'). Hacer una función que
busque si en ese arreglo existe la palabra "oso", si existe regresa TRUE
por la izquierda, si no, regresa FALSE.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void llenarArreglo(char arr[], int size);
int buscarPalabra(char arr[], const char *palabra);

int main(void) {
    char arr[SIZE];

    // Inicializar la semilla para números aleatorios
    srand(time(NULL));

    // Llenar el arreglo con caracteres aleatorios de 'A' a 'Z'
    llenarArreglo(arr, SIZE);

    // Imprimir parte del arreglo (opcional)
    printf("Arreglo de caracteres: \n");
    for (int i = 0; i < 100; i++) { // Imprimimos solo los primeros 100 caracteres
        printf("%c ", arr[i]);
    }
    printf("\n");

    // Buscar la palabra "OSO"
    if (buscarPalabra(arr, "OSO")) {
        printf("La palabra 'OSO' fue encontrada en el arreglo.\n");
    } else {
        printf("La palabra 'OSO' NO fue encontrada en el arreglo.\n");
    }

    return 0;
}

void llenarArreglo(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 65 + rand() % 26;  // Genera un carácter aleatorio entre 'A' y 'Z'
    }
}

int buscarPalabra(char arr[], const char *palabra) {
    int longitud = 0;
    while (palabra[longitud] != '\0') {
        longitud++;
    }

    for (int i = 0; i <= SIZE - longitud; i++) {
        int j;
        for (j = 0; j < longitud; j++) {
            if (arr[i + j] != palabra[j]) {
                break;
            }
        }
        if (j == longitud) { // Si se encontró la palabra
            return 1; // TRUE
        }
    }

    return 0; // FALSE
}
