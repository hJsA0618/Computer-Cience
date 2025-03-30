/*e) Hacer una función que recibe como parámetros, un vector de enteros y apuntadores a las
variables de tipo float: promedio, varianza, moda, maximo, minimo. La
funcion calcula internamente esos valores y los deja en las direcciones de los apuntadores.*/

#include <stdio.h>
#include <stdlib.h>

void stats(int arr[], int n, float *promedio, float *varianza, float *moda, float *maximo, float *minimo);
void calcularEstadisticas(int *arr, int n, float *promedio, float *varianza, float *moda, float *maximo, float *minimo) {
    
    float suma = 0;
    *maximo = arr[0];
    *minimo = arr[0];
    int maxFrecuencia = 0;

    for (int i = 0; i < n; i++) {
        suma += arr[i];
        if (arr[i] > *maximo) {
            *maximo = arr[i];
        }
        if (arr[i] < *minimo) {
            *minimo = arr[i];
        }

    *promedio = suma / n;
    
    float sumaVarianza = 0;
    for (int i = 0; i < n; i++) {
        sumaVarianza += (arr[i] - *promedio) * (arr[i] - *promedio);
    }
    *varianza = sumaVarianza / n;

}