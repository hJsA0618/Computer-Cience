/* Hacer un programa en C que encuentre las raíces de una ecuación cuadrática a
x^2+b x+c=0. Debe de leer los 3 coeficientes desde el teclado. Usar la funcion sqrt()
para calcular la raiz cuadrada, deben incluir #include <math.h> para usarla.
Explicación del método en https://miprofe.com/raices-de-ecuaciones-cuadraticas/.*/
#include <stdio.h>
#include <math.h>
int main(void) {
    int a,b,c;
    float disc,root1,root2;
    printf("Hola ingresa tus coeficientes en orden a b c con espacios: \n");
    scanf("%d %d %d", &a, &b, &c);
    disc=((b*b)-(4*a*(float)c));
    if (disc>0)
    {
        root1=(-b+(sqrt(disc)))/(2*(float)a);
        root2=(-b-(sqrt(disc)))/(2*(float)a);
        printf("tu respuesta 1 es %.2f y tu respuesta 2 es %.2f\n",root1,root2);
    }
    else if (disc == 0) {
        root1 = root2 = -b / (2 * (float)a);
        printf("Tus respuestas son %.2f y %.2f\n", root1, root2);
    } 
    else {
        float realPart = -b / (2 * (float)a);
        float imaginaryPart = sqrt(-disc) / (2 * (float)a);
        printf("Tus respuestas son %.2f + %.2fi y %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}