/*Definir el nuevo tipo de datos con struct y typedef llamado
Complejo, hacer 3 funciones que: sumen, resten y multipliquen
números complejos, respectivamente. Las 3 funciones deberán regresar
el resultado (el número complejo) por la izquierda.*/

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    float parteReal;
    float parteImaginaria;
} complex;

complex sumaComplex(complex a, complex b) {
    complex resultado;
    resultado.parteReal = a.parteReal + b.parteReal;
    resultado.parteImaginaria = a.parteImaginaria + b.parteImaginaria;
    return resultado;
}

complex restaComplex(complex a, complex b) {
    complex resultado;
    resultado.parteReal = a.parteReal - b.parteReal;
    resultado.parteImaginaria = a.parteImaginaria - b.parteImaginaria;
    return resultado;
}

complex productComplex(complex a, complex b) {
    complex resultado;
    resultado.parteReal = (a.parteReal * b.parteReal) - (a.parteImaginaria * b.parteImaginaria);
    resultado.parteImaginaria = (a.parteReal * b.parteImaginaria) + (a.parteImaginaria * b.parteReal);
    return resultado;
}

void imprimirComplex(complex c) {
    if (c.parteImaginaria >= 0) {
        printf("%.2f + %.2fi\n", c.parteReal, c.parteImaginaria);
    } else {
        printf("%.2f - %.2fi\n", c.parteReal, -c.parteImaginaria);
    }
}

int main() {
    complex a, b;

    printf("Ingresa el número complejo A (parte real y parte imaginaria): ");
    scanf("%f %f", &a.parteReal, &a.parteImaginaria);
    
    printf("Ingresa el número complejo B (parte real y parte imaginaria): ");
    scanf("%f %f", &b.parteReal, &b.parteImaginaria);
    
    complex suma = sumaComplex(a, b);
    printf("Suma: ");
    imprimirComplex(suma);

    complex resta = restaComplex(a, b);
    printf("Resta: ");
    imprimirComplex(resta);

    complex producto = productComplex(a, b);
    printf("Multiplicación: ");
    imprimirComplex(producto);
    
    return 0;
}
