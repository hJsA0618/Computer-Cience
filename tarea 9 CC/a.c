/*Hacer una función que se le manda un arreglo de caracteres (una
cadena de caracteres con terminador '\0') con longitud no mayor a
1000 caracteres, y elimina de ella espacios y comas (la cadena resultante
es más corta). Si te facilita las cosas, para hacer el trabajo, puedes usar
de manera interna un arreglo de caracteres auxiliar char
buffer[1024].*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
// <-------------- define --------------->
#define BUFFER 1024

// <------------- funciones ------------->
void eliminaspace (char vecA[]);
void eliminaspace (char vecA[BUFFER]){
    char vecB[BUFFER];
    int j=0; 
    for(int i=0;i<(strlen(vecA));i++){
        if(vecA[i]!=' '&& vecA[i]!=','){
            vecB[j]=vecA[i];
            j++;
        }
    }
    printf("%s \n",vecB);
}

int main (void){
    char vector[BUFFER];
    printf("manda tu cadena carnal: \n");
    //scanf("%s",vector);
    fgets(vector, sizeof(vector), stdin);
    eliminaspace(vector);
    return 0;
}