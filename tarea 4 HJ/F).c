#include <stdio.h>
#include <math.h>

void imprimir(int n) {
    double resultado = 0.0;

    for (int i = 0; i <= n; i++) {
        resultado += pow(-1, i) / (2 * i + 1);
        printf("Para i = %d, (-1)^%d / (2 * %d + 1) = %.6f\n", i, i, i, pow(-1, i) / (2 * i + 1));
    }

    double pi = resultado * 4;
    printf("El valor aproximado de pi con n = %d es: %.6f\n", n, pi);
}

int main() {
    int n;

    printf("Introduce el valor maximo de n: ");
    scanf("%d", &n);

    imprimir(n);

    return 0;
}
