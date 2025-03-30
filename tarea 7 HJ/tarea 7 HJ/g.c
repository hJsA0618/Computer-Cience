/*Hacer la función que calcula la longitud de una cadena de caracteres
int longitudCadena(char cad[]) y probar que funciona para
por lo menos 3 cadenas distintas en int main(void){...}*/


#include <stdio.h>
#define N 100


int longitudCadena(char cadenacaracteres[]);
int longitudCadena(char cadenacaracteres[]) {
    int longitud = 0;
    while (cadenacaracteres[longitud] != '\0') 
    { 
        longitud++;
    }
    return longitud;
}


int main (void){
    char cad1[N], cad2[N], cad3[N];
    printf("Ingresa la primera cadena de caracteres: ");
    scanf("%99s", cad1); 

    printf("Ingresa la segunda cadena de caracteres: ");
    scanf("%99s", cad2);

    printf("Ingresa la tercera cadena de caracteres: ");
    scanf("%99s", cad3);

    printf("La longitud de la primera cadena es: %d\n", longitudCadena(cad1));
    printf("La longitud de la segunda cadena es: %d\n", longitudCadena(cad2));
    printf("La longitud de la tercera cadena es: %d\n", longitudCadena(cad3));
    return 0;
}