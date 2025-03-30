/*e) Hacer una función que recibe como parámetros, un vector de enteros y apuntadores a las
variables de tipo float: promedio, varianza, moda, maximo, minimo. La
funcion calcula internamente esos valores y los deja en las direcciones de los apuntadores.*/

#include <stdio.h>
#include <stdlib.h>

void stats(int arr[], int n, float *promedio, float *varianza, float *moda, float *maximo, float *minimo);
void calcularEstadisticas(int *arr, int n, float *promedio, float *varianza, float *moda, float *maximo, float *minimo) {
    if (n <= 0) {
        *promedio = *varianza = *moda = *maximo = *minimo = 0;
        return; // Si no hay elementos, salimos
    }

    // Inicializar variables
    float suma = 0;
    *maximo = arr[0];
    *minimo = arr[0];
    int *frecuencias = (int *)malloc(100 * sizeof(int)); // Suponiendo que los números están entre 0 y 99
    if (frecuencias == NULL) {
        fprintf(stderr, "Error al asignar memoria para frecuencias\n");
        return; // Salir si hay un error de asignación
    }

    // Inicializar el arreglo de frecuencias a cero
    for (int i = 0; i < 100; i++) {
        frecuencias[i] = 0;
    }

    int maxFrecuencia = 0;

    // Calcular suma, máximo, mínimo y frecuencias
    for (int i = 0; i < n; i++) {
        suma += arr[i];

        if (arr[i] > *maximo) {
            *maximo = arr[i];
        }
        if (arr[i] < *minimo) {
            *minimo = arr[i];
        }

        frecuencias[arr[i]]++; // Contar frecuencias para la moda
        if (frecuencias[arr[i]] > maxFrecuencia) {
            maxFrecuencia = frecuencias[arr[i]];
            *moda = arr[i];
        }
    }

    *promedio = suma / n;

    // Calcular varianza
    float sumaVarianza = 0;
    for (int i = 0; i < n; i++) {
        sumaVarianza += (arr[i] - *promedio) * (arr[i] - *promedio);
    }
    *varianza = sumaVarianza / n;

    // Liberar memoria
    free(frecuencias);
}