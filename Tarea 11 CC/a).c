/*a) Hacer una función que recibe como parámetro un unsigned int (por ejemplo unsigned
int a = 255), y que usa un ciclo para mandar a la pantalla la trama de bits que componen al
número (por ejemplo 00000000000000000000000011111111). Para eso usar una máscara
inicializada al primer bit como unsigned int mask = 1, y usar corrimientos a la izquierda
para pasar cada vez el siguiente bit.*/

#include <stdio.h>
#include <stdlib.h>


void bits(unsigned int a);
void bits(unsigned int a){
    unsigned int mask = 1;
    for (int i = 0; i < (sizeof(a))*8; i++)
    {
        if (a&mask)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
        mask <<= 1;
    }
    printf("\n");
    return;
}

int main (void){
    unsigned int a=28;
    bits(a);
    return 0;
}