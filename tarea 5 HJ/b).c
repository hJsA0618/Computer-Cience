/*Hacer una función que reciba un valor unsigned int v por
parámetro y que lo multiplique por 32 usando corrimientos a la
izquierda. Reportar: ¿qué pasa si el resultado ya no cabe en un
unsigned int después de los corrimientos?*/

//operador a bits
#include <stdio.h>

unsigned int multibinario (unsigned int n);
void passtobinary ();

void passtobinary(unsigned long long n) {
    int num_bits = 64; // Número de bits en un entero de 64 bits
    for (int i = num_bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);

        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

unsigned int multibinario(unsigned int n) {
    return n << 5;
}
    
int main(void) {
    int m, resultado;
    printf("Pasa el numero que quieres multiplicar por 32: ");
    scanf("%d", &m);
    resultado = multibinario(m);
    printf("El resultado de multiplicar %d por 32 es: %d\n", m, resultado);
    
    printf("El resultado en binario es: ");
    passtobinary(resultado);
    return 0;
}