/*b) Suponiendo que tienes una cadena de caracteres en minúsculas y sin
acentos, programar una función que, usando la función del inciso a)
para eliminar caracteres inútiles, indica si la cadena es un palíndromo o
no. Probar su programa con palíndromos del tipo:*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
// <-------------- define --------------->
#define BUFFER 1024


// <------------- declaracion de funciones ------------->
void eliminaspace (char vecA[]);
void checkpalindromo (char vetorA[BUFFER]);

// <----------------------- funciones ------------------>

void eliminaspace (char vecA[BUFFER]){
    char vecB[BUFFER];
    int j=0; 
    for(int i=0;i<(strlen(vecA));i++){
        if(vecA[i]!=' '&& vecA[i]!=','){
            vecB[j]=vecA[i];
            j++;
        }
    }
    vecB[j] = '\0';
    strcpy(vecA, vecB);
   // printf("%s \n",vecB);
}

void checkpalindromo (char vetorA[BUFFER]){
    eliminaspace(vetorA);
    int max,i,j;
    max=strlen(vetorA);
    for( i=0;i<(max/2);i++){
        j=max-1-i;
        if (vetorA[i]!=vetorA[j]){
            printf("no son palindromos");
            return;
        }
    }
    printf("La cadena es un palindromo.\n"); // Solo imprime si fue exitoso
}


int main (void){
    char vector[BUFFER];
    printf("manda tu cadena carnal: \n");
    //scanf("%s",vector);
    fgets(vector, sizeof(vector), stdin);
        vector[strcspn(vector, "\n")] = 0;
    checkpalindromo(vector);
    return 0;
}