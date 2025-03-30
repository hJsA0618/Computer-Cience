#include <stdio.h>
#include <stdlib.h>
#include "Complejo.h"

int main() {
    int N = 5;
    Complejo *numbers = (Complejo *)malloc(N * sizeof(Complejo));
    
    if (numbers == NULL) {
        printf("NO JALO :c.\n");
        return 1;
    }

    numbers[0].real = 3.0; numbers[0].imag = 4.0;  // Magnitude = 5.0
    numbers[1].real = 1.0; numbers[1].imag = 2.0;  // Magnitude = 2.236
    numbers[2].real = 5.0; numbers[2].imag = 12.0; // Magnitude = 13.0
    numbers[3].real = 0.0; numbers[3].imag = 1.0;  // Magnitude = 1.0
    numbers[4].real = 7.0; numbers[4].imag = 24.0; // Magnitude = 25.0

    printAndSort(numbers, N, cmpfunc);

    free(numbers);
    return 0;
}
