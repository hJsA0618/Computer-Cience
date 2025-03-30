/*Utiliza un ciclo for para imprimir en pantalla la tabla de multiplicar del número 1024,
desde multiplicado por 1 hasta multiplicado por 100*/

#include <stdio.h>

int main(void) {
    for (int n = 1; n <= 100; n++)
    {
        printf("%d\n",(n*1024));
    }
        

    return 0;
}