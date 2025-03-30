/*d) Hacer un programa en C que usando un ciclo for(... ; ... ; ...) calcule y
reporte en pantalla la suma: 2+4+6+..+5502+5504. 
*/

#include <stdio.h>

int main(void) {
    int suma = 0;
    for (int n = 2; n <= 5504; n+=2)
    {
        suma += n;
    }
        printf("La suma de los numeros del 2 al 5504 es: %d\n", suma);
    getchar();
    return 0;
}/*
██████████████████████████████████████████████████████████████████████
█─█─█▄─▄▄─█─▄▄▄─█─▄─▄─█─▄▄─█▄─▄▄▀█████▄─▄██▀▄─██▄─█─▄█▄─▄█▄─▄▄─█▄─▄▄▀█
█─▄─██─▄█▀█─███▀███─███─██─██─▄─▄███─▄█─███─▀─███▄▀▄███─███─▄█▀██─▄─▄█
▀▄▀▄▀▄▄▄▄▄▀▄▄▄▄▄▀▀▄▄▄▀▀▄▄▄▄▀▄▄▀▄▄▀▀▀▄▄▄▀▀▀▄▄▀▄▄▀▀▀▄▀▀▀▄▄▄▀▄▄▄▄▄▀▄▄▀▄▄▀*/