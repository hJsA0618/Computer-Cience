/*b) Hacer un programa en C que usando un solo ciclo for(... ; ... ; ...)
imprima en pantalla los números -100,-98,…,-2,0,1,2,3,4,…,
499,500,600,603,606,…,999. (¡OJO! Notar que hay una discontinuidad de tamaño 100).*/

#include <stdio.h>

int main(void) {
    for (int n = -100; n <= 999; ) 
    {
        if (n <= -2) 
        {
            // Imprimir de -100 a -2 con incremento de 2
            printf("%d ", n);
            n += 2;  // Incrementar de 2 en 2
        } 
        else if (n <= 500) 
        {
            // Imprimir de 0 a 500 con incremento de 1
            printf("%d ", n);
            n += 1;  // Incrementar en 1
        } 
        else if (n < 600) 
        {
            // Saltar directamente a 600
            n = 600;
        } 
        else 
        {
            // Imprimir de 600 a 999 con incremento de 3
            printf("%d ", n);
            n += 3;  // Incrementar de 3 en 3
        }
    }

    return 0;
}

