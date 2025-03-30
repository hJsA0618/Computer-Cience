/*Dado la recta y(x) = a_1 x + a_0, encontrar el punto x_0 donde y(x_0)=0 (donde cruza
la recta en cero), y evaluar y(x) desde x_0 (incluyéndolo) hasta x_0 + 15 avanzado de 1
en 1. Imprimir los valores de y(x) a pantalla.*/

#include <stdio.h>

int main(void) {
    int a_1, a_0;
    float x0,n,y;
    printf("de tu ecuacion en forma y(x) = a_1 x + a_0. escribe a_1 y a_0\n");
    scanf("%d %d", &a_1,&a_0);
    if (a_1 == 0) {
        printf("El coeficiente a_1 no puede ser cero en una recta no vertical.\n");
        return 1;
    }
    x0=-(a_0/(float)a_1);

    printf("Valores de y(x) desde x0 = %.2f hasta x0 + 15:\n", x0);
    for (float n = x0; n <= x0 + 15; n += 1.0) {
        int y = a_1 * n + a_0;
        printf("y(%.2f) = %d\n", n, y);
    }
    getchar();
    return 0;
}

