/*Usando el operador módulo %, hacer un programa que lee un número del teclado
entre 3 y 4000, y usando un ciclo determina si es un número primo o no.*/

#include <stdio.h>

int main(void) {
    int n;
    int es_primo = 1;

    printf("Escribe un numero entre 3 y 4000 para ver si es primo: ");
    scanf("%d", &n);

    if (n < 3 || n > 4000) {
        printf("El numero debe estar entre 3 y 4000.\n");
        return 1; //para cerrar el programa
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            es_primo = 0;
            break;
        }
    }

    if (es_primo && n > 1) {
        printf("%d es un numero primo.\n", n);
    } else {
        printf("%d no es un numero primo.\n", n);
    }

    return 0;
}
