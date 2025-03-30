#include <stdio.h>

int main() {
    int a = 10, b = 5, c = 2;
    int resultado;
    int logico1, logico2;

    resultado = a + b * c;
    printf("a + b * c = %d\n", resultado);

    resultado = (a + b) * c;
    printf("(a + b) * c = %d\n", resultado);

    resultado = a / b - c;
    printf("a / b - c = %d\n", resultado);

    resultado = a / (b - c);
    printf("a / (b - c) = %d\n", resultado);

    printf("a <= b: %s\n", (a <= b) ? "verdadero" : "falso");
    printf("a > b: %s\n", (a > b) ? "verdadero" : "falso");

    logico1 = (a > b) && (b < c);
    logico2 = (a > b) || (b < c);

    printf("(a > b) && (b < c): %s\n", logico1 ? "verdadero" : "falso");
    printf("(a > b) || (b < c): %s\n", logico2 ? "verdadero" : "falso");

    resultado = a;
    resultado += b;
    printf("resultado += b: %d\n", resultado);

    resultado = a + b * c - (a / b) + c;
    printf("a + b * c - (a / b) + c = %d\n", resultado);

    return 0;
}
