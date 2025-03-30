/*Hacer un programa usando un ciclo for(... ; ... ; ...) en C que calcule y
reporte en pantalla la suma: 1+2+3...5503+5504. Verificar a mano que el resultado es
correcto con la fórmula de Gauss : n(n+1)/2.*/

#include <stdio.h>

int main(void) {
    int suma = 0;
    for (int n = 1; n <= 5504; n++)
    {
        suma += n;
    }
        printf("La suma de los numeros del 1 al 5504 es: %d\n", suma);

    return 0;
}/*
██████████████████████████████████████████████████████████████████████
█─█─█▄─▄▄─█─▄▄▄─█─▄─▄─█─▄▄─█▄─▄▄▀█████▄─▄██▀▄─██▄─█─▄█▄─▄█▄─▄▄─█▄─▄▄▀█
█─▄─██─▄█▀█─███▀███─███─██─██─▄─▄███─▄█─███─▀─███▄▀▄███─███─▄█▀██─▄─▄█
▀▄▀▄▀▄▄▄▄▄▀▄▄▄▄▄▀▀▄▄▄▀▀▄▄▄▄▀▄▄▀▄▄▀▀▀▄▄▄▀▀▀▄▄▀▄▄▀▀▀▄▀▀▀▄▄▄▀▄▄▄▄▄▀▄▄▀▄▄▀*/