/*g) Imprimir los números de 1 a 1000 que NO estén más cerca de una distancia d de un
número dado k (leer d y k desde teclado).*/

#include <stdio.h>

int main(void) {
    int n,d,k;
    printf("di una distancia d de un numero dado k en la serie del 1 al 1000 para no imprimir los valores en k con distancia d \n" );
    scanf("%d %d", &d, &k);
    for(n=1; n<=1000; n++)
    {
        if (n <= (k-d))
        {
            // Imprimir de 1 a "k-d"
            printf("%d ", n);
        } 
        else if (n >= (k+d)) 
        {
            // Imprimir de k+d hasta 1000
            printf("%d ", n);
        } 
    }
    getchar();
    getchar();
    return 0;
}/*
██████████████████████████████████████████████████████████████████████
█─█─█▄─▄▄─█─▄▄▄─█─▄─▄─█─▄▄─█▄─▄▄▀█████▄─▄██▀▄─██▄─█─▄█▄─▄█▄─▄▄─█▄─▄▄▀█
█─▄─██─▄█▀█─███▀███─███─██─██─▄─▄███─▄█─███─▀─███▄▀▄███─███─▄█▀██─▄─▄█
▀▄▀▄▀▄▄▄▄▄▀▄▄▄▄▄▀▀▄▄▄▀▀▄▄▄▄▀▄▄▀▄▄▀▀▀▄▄▄▀▀▀▄▄▀▄▄▀▀▀▄▀▀▀▄▄▄▀▄▄▄▄▄▀▄▄▀▄▄▀*/