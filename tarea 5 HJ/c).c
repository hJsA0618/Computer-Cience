/*Hacer un programa que adivine un número entre un valor inicial (por
ejemplo 1) y un valor final (por ejemplo 1,000,000) en a los más
ceil(log2(final-inicial+1+1)) intentos (siendo ceil() la
función techo). El programa pregunta las 3 opciones : ¿adivinado?, o
es ¿mayor? o es ¿menor? ('a','<','>'). Deben de usar un ciclo do-
while. Para hacerlo, programar una función que recibe el intervalo, haga
la búsqueda, y regrese por la izquiera el número de intentos (iteraciones)
que usó. int main(void){...} manda a llamar a dicha función e
imprime cuantos intentos se utilizaron. Basen su programa en el código
lee_char_teclado.c.*/
#include <stdio.h>

int adivinarNumero(int bajo, int alto);

int adivinarNumero(int bajo, int alto) {
    int medio;
    char respuesta;
    int intentos = 0;  // Contador de intentos

    do {
        medio = bajo + (alto - bajo) / 2;
        intentos++;

        printf("Intento %d: Es el numero %d? (a para Adivinado, < para Menor, > para Mayor): ", intentos, medio);
        scanf(" %c", &respuesta); // Espacio antes de %c para leer el caracter correctamente

        switch (respuesta) {
            case 'a':
                // El numero ha sido adivinado
                printf("He adivinado tu numero en %d intentos! Es %d.\n", intentos, medio);
                return intentos;
            
            case '>':
                // El numero es mayor que medio
                bajo = medio + 1;
                break;
            
            case '<':
                // El numero es menor que medio
                alto = medio - 1;
                break;
            
            default:
                // Respuesta no valida
                printf("Respuesta no valida. Por favor ingresa 'a', '<', o '>'.\n");
                intentos--; // No contar el intento por respuesta invalida
                break;
        }
    } while (bajo <= alto);

    // Si se sale del bucle, significa que el numero no esta en el rango dado
    printf("No pude adivinar tu numero en el rango dado despues de %d intentos.\n", intentos);
    return intentos;
}

int main(void) {
    int bajo = 1;
    int alto = 1000000;

    printf("Piensa en un numero entero del %d al %d.\n", bajo, alto);
    printf("Responde 'a' si el numero es el propuesto.\n");
    printf("Responde '<' si el numero es menor que el propuesto.\n");
    printf("Responde '>' si el numero es mayor que el propuesto.\n");

    int intentos = adivinarNumero(bajo, alto);

    printf("Numero de intentos utilizados: %d\n", intentos);

    return 0;
}