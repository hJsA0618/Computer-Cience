#include <stdio.h>
#include <math.h>

#define TOLERANCIA 1e-4 // Macro para la tolerancia

// Funcion para calcular la raiz cuadrada usando el algoritmo de Babilonia
float mi_sqrt(float S, float mi_tolerancia) {
    if (S < 0) {
        printf("Error: No se puede calcular la raiz cuadrada de un numero negativo.\n");
        return -1; // Indicamos error con un valor especial
    }

    float x = S;         
    float prev_x;        
    // Iteramos hasta que la diferencia entre valores consecutivos sea menor que la tolerancia
    do {
        prev_x = x;
        x = 0.5 * (S / x + x);
    } while (fabs(x - prev_x) > mi_tolerancia);

    return x; 
}

int main(void) {
    float SS; 

    printf("Introduzca el numero para calcular su raiz cuadrada: ");
    scanf("%f", &SS);

    float xx = mi_sqrt(SS, TOLERANCIA);

    if (xx != -1) {
        printf("La raiz cuadrada de %.2f es %.6f\n", SS, xx);
    } else {
        printf("No se pudo calcular la raiz cuadrada.\n");
    }

    return 0;
}
