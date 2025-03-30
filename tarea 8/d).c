#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

float razon_aurea(int n) {
    if (n <= 1) return 1.0; // /{0}
    int fn = fibonacci(n);
    int fn_minus_1 = fibonacci(n - 1);
    return (float)fn / fn_minus_1;
}

int main(void) {
    int n;

    printf("Ingresa el número de términos para calcular la Razón Áurea: ");
    scanf("%d", &n);

    printf("Aproximaciones de la Razón Áurea:\n");
    for (int i = 2; i <= n; i++) {
        printf("F(%d) = %d, F(%d) = %d, Razón Áurea ≈ %.6f\n", 
               i, fibonacci(i), i - 1, fibonacci(i - 1), razon_aurea(i));
    }

    return 0;
}