/*Usar 2 ciclos for anidados para imprimir en pantalla de manera automática las
tablas de multiplicar desde el 2 hasta un valor k, y mostrar la tabla empezando en 1 y
hasta multiplicar por un numero M. k y M se leen desde teclado, tu programa debe de
funcionar para diferentes valores de k y M. Por ejemplo, para k=5 y M = 6, se muestra
en pantalla:*/

#include <stdio.h>

void imprimirTablas(int k, int M) {
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= M; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }
}

int main(void) {
    int k, M;
    printf("ingresa tus valores para hacer la tabla de multiplicar\n");
    printf("k hasta que valor se quiere multiplicar y M hasta la tabla que se quiere llegar\n");
    scanf("%d %d",&k, &M);

    imprimirTablas(k,M);

    getchar();
    return 0;
}