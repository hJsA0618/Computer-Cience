#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 100

int my_strcmp(char c1[], char c2[]) {
    int i = 0;
    while (c1[i] != '\0' && c2[i] != '\0') {
        if (c1[i] != c2[i]) {
            return 0; 
        }
        i++;
    }
    
    return (c1[i] == c2[i]);
}

int main (void){
    char cad1[N], cad2[N], cad3[N];
    int valor;
    printf("Ingresa la primera cadena de caracteres: ");
    scanf("%99s", cad1); 

    printf("Ingresa la segunda cadena de caracteres: ");
    scanf("%99s", cad2);

    valor=my_strcmp(cad1, cad2);
    if (valor==1)
    {
        printf("son iguales");
    }
    else
    {
        printf("son diferentes");
    }
    
    
    return 0;
}