/*b) Hacer un programa que declara una variable a de tipo double, una b de tipo int y un
arreglo arr de N=10 variables tipo float. Inicializar todas ellas a cero. Ahora, sin usar
ninguna de las variables a, b ni arr en ninguna de las sigientes instrucciones: modificar todas
las variables a un valor que tu quieras (usando variables de tipo apuntador) y mandar a pantalla
su nuevo valor usando la función printf().*/

#include <stdio.h>
#include <stdlib.h>
#define N 10

void modificaVal(double *x, int *y, float arrZ[]);
void modificaVal(double *x, int *y, float arrZ[]) {
    *x = 1.0;
    *y = 2;
    for (int i = 0; i < N; i++) {
        arrZ[i] = 4.0f;
    }
}

int main(void){
    double a=0;
    int b=0;
    float arr[N]={0};
    modificaVal(&a, &b, arr);
    printf("%f, %d, %f\n", a, b, arr[9]);
    return 0;
}