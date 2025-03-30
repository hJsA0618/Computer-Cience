/*Hacer un programa que pide al usuario que introduzca los números no-negativos
que quiera. Para avisar que ya ha terminado de introducir los números, el usuario debe
de introducir un número negativo. Se calcula el promedio de los números no-negativos
y se imprime en pantalla.*/

#include "stdio.h"
int main(){
  int n, contador=0, suma=0;
  float promedio;
    printf("escribe los valores que quieres promediar y si quieres parar escribe un negativo\n");
    do {
        scanf("%d", &n);
        if (n >= 0) {
            suma += n;
            contador++;
        }
    } while (n >= 0);

    if (contador > 0) {
        promedio = suma / (float)contador;
        printf("El promedio de los numeros ingresados es %.2f\n", promedio);
    } else {
        printf("No se han ingresado numeros validos.c");
    }
    getchar();
    return 0;
}/*
██████████████████████████████████████████████████████████████████████
█─█─█▄─▄▄─█─▄▄▄─█─▄─▄─█─▄▄─█▄─▄▄▀█████▄─▄██▀▄─██▄─█─▄█▄─▄█▄─▄▄─█▄─▄▄▀█
█─▄─██─▄█▀█─███▀███─███─██─██─▄─▄███─▄█─███─▀─███▄▀▄███─███─▄█▀██─▄─▄█
▀▄▀▄▀▄▄▄▄▄▀▄▄▄▄▄▀▀▄▄▄▀▀▄▄▄▄▀▄▄▀▄▄▀▀▀▄▄▄▀▀▀▄▄▀▄▄▀▀▀▄▀▀▀▄▄▄▀▄▄▄▄▄▀▄▄▀▄▄▀*/