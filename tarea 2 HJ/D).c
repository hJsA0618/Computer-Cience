/*Hacer un programa en C que convierta una cantidad dada en pesos mexicanos a
dólares Estado-Unidences y Canadiences (las dos conversiones en el mismo
programa). Debe de leer la cantidad de pesos desde el teclado (con scanf() ).
*/
#include <stdio.h>
#include <math.h>
int main(void)
{
    int opcion;
    float mxn, usa, canada;

    printf("Hola Bienvenido, ingresa 1 si quieres pasar tus pesos a dolares de usa o 2 a dolares canadiences\n");
    scanf("%d", &opcion);
        if (opcion==1){
            printf("ingresa tus pesos mexicanos\n");
            scanf("%f", &mxn);
            usa=mxn*19.13;
            printf("tienes %.2f en dolares estadounidenses\n\a", usa);
        }
        else if (opcion==2){
            printf("ingresa tus pesos mexicanos\n");
            scanf("%f", &mxn);
            canada=mxn/14.12;
            printf("tienes %.2f en dolares canadiences\n\a", canada);
        }
        else {
        printf("Opcion no valida.\n");
        return 1;  // Salida del programa en caso de opción no válida
        }
    getchar();
    getchar();
    return 0;
}
/*
──▒▒▒▒▒▒───▄████▄
─▒─▄▒─▄▒──███▄█▀
─▒▒▒▒▒▒▒─▐████──█─█
─▒▒▒▒▒▒▒──█████▄
─▒─▒─▒─▒───▀████▀

*/