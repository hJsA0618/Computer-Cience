/*Haz un programa tipo reloj que muestre en pantalla cronológicamente todas las
posibles horas del día segundo-a-segundo en formato HH:MM:SS desde 00:00:00
hasta 23:59:59. OJO! Todos los valores se imprimen inmediatamente en cuanto se
generen con ciclos. (Es decir, no se trata de simular un reloj en tiempo real, se trata
solo de imprimir todos los números posibles ordenados).*/

#include <stdio.h>

int main(void) {
    int h, m, s;

    for (h = 0; h < 24; ++h) {
        for (m = 0; m < 60; ++m) {
            for (s = 0; s < 60; ++s) {
                printf("%02d:%02d:%02d\n", h, m, s);
            }
        }
    }
    getchar();
    return 0;
}
