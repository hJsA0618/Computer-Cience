/* d) Dado un arreglo de caracteres char vc[24] , llenarlo con las 24 primeras letras del
lenguaje inglés (de la 'a' a la 'x') en orden ascendente con un ciclo for. Posteriormente,
poner un apuntador aptrLI de tipo unsigned int al inicio del vector vc (quizá necesites
hacer un cast entre tipos de apuntadores), imprimir en pantall todos los unsigned int que
caben en ese espacio de memoria. Explicar por qué salen los números que salen en pantalla. */
#include <stdio.h>
#include <stdlib.h>
#define N 24
void llenarvec (char vec[]);
void llenarvec (char vec[]){
    int i=0;
    for (int i = 0; i < N; i++)
        {
            vec[i]='a'+i;
            i++;
        }
    vec[i] = '\0'; 
    }

int main(void) {
    char vc[N + 1];
    llenarvec(vc);
    unsigned int *aptrLI = (unsigned int *)vc;
    for (int i = 0; i < (N + 1) / sizeof(unsigned int); i++) {
        printf("%u\n", aptrLI[i]); 
    }
    return 0;
}