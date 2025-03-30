#include <stdio.h>
#include <math.h>

// Función a: Resolver ecuacion cuadratica
void resolver_ecuacion_cuadratica() {
    int a, b, c;
    float disc, root1, root2;
    printf("Para resolver la ecuacion cuadratica, ingresa los coeficientes a, b y c: ");
    scanf("%d %d %d", &a, &b, &c);
    disc = ((b * b) - (4 * a * (float)c));
    if (disc > 0) {
        root1 = (-b + sqrt(disc)) / (2 * (float)a);
        root2 = (-b - sqrt(disc)) / (2 * (float)a);
        printf("Tu respuesta 1 es %.2f y tu respuesta 2 es %.2f\n", root1, root2);
    } else if (disc == 0) {
        root1 = root2 = -b / (2 * (float)a);
        printf("Tus respuestas son %.2f y %.2f\n", root1, root2);
    } else {
        float realPart = -b / (2 * (float)a);
        float imaginaryPart = sqrt(-disc) / (2 * (float)a);
        printf("Tus respuestas son %.2f + %.2fi y %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
}

// Función b: Imprimir numeros con diferentes incrementos
void imprimir_numeros() {
    for (int n = -100; n <= 999; ) {
        if (n <= -2) {
            printf("%d ", n);
            n += 2;
        } else if (n <= 500) {
            printf("%d ", n);
            n += 1;
        } else if (n < 600) {
            n = 600;
        } else {
            printf("%d ", n);
            n += 3;
        }
    }
    printf("\n");
}

// Función c: Sumar numeros del 1 al 5504
void sumar_numeros() {
    int suma = 0;
    for (int n = 1; n <= 5504; n++) {
        suma += n;
    }
    printf("La suma de los numeros del 1 al 5504 es: %d\n", suma);
}

// Función d: Sumar numeros pares del 2 al 5504
void sumar_numeros_pares() {
    int suma = 0;
    for (int n = 2; n <= 5504; n += 2) {
        suma += n;
    }
    printf("La suma de los numeros del 2 al 5504 es: %d\n", suma);
}

// Función e: Calcular promedio de numeros ingresados por el usuario
void calcular_promedio() {
    int n, contador = 0, suma = 0;
    float promedio;
    printf("Escribe los valores que quieres promediar y si quieres parar escribe un negativo\n");
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
        printf("No se han ingresado numeros validos.\n");
    }
}

// Función f: Calcular y(x) de la ecuacion de la recta
void calcular_ecuacion_recta() {
    int a_1, a_0;
    float x0, n, y;
    printf("Para calcular y(x) de la ecuacion de la recta, ingresa a_1 y a_0: ");
    scanf("%d %d", &a_1, &a_0);
    if (a_1 == 0) {
        printf("El coeficiente a_1 no puede ser cero en una recta no vertical.\n");
        return;
    }
    x0 = -(a_0 / (float)a_1);

    printf("Valores de y(x) desde x0 = %.2f hasta x0 + 15:\n", x0);
    for (n = x0; n <= x0 + 15; n += 1.0) {
        y = a_1 * n + a_0;
        printf("y(%.2f) = %.2f\n", n, y);
    }
}

// Función g: Imprimir numeros con distancia excluida
void imprimir_numeros_con_distancia() {
    int d, k;
    printf("Ingresa una distancia d y un numero k: ");
    scanf("%d %d", &d, &k);
    for (int n = 1; n <= 1000; n++) {
        if (n <= (k - d) || n >= (k + d)) {
            printf("%d ", n);
        }
    }
    printf("\n");
}

// Función h: Imprimir multiplos de 1024 del 1 al 100
void imprimir_multiplos() {
    for (int n = 1; n <= 100; n++) {
        printf("%d\n", (n * 1024));
    }
}

// Función i: Imprimir todas las horas, minutos y segundos
void imprimir_reloj() {
    int h, m, s;
    for (h = 0; h < 24; ++h) {
        for (m = 0; m < 60; ++m) {
            for (s = 0; s < 60; ++s) {
                printf("%02d:%02d:%02d\n", h, m, s);
            }
        }
    }
}

// Función j: Verificar si un numero es primo
void verificar_numero_primo() {
    int n;
    int es_primo = 1;

    printf("Escribe un numero entre 3 y 4000 para verificar si es primo: ");
    scanf("%d", &n);

    if (n < 3 || n > 4000) {
        printf("El numero debe estar entre 3 y 4000.\n");
        return;
    }

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            es_primo = 0;
            break;
        }
    }

    if (es_primo && n > 1) {
        printf("%d es un numero primo.\n", n);
    } else {
        printf("%d no es un numero primo.\n", n);
    }
}

int main(void) {
    int opcion;

    printf("Selecciona una opcion (1-10):\n");
    printf("1. Resolver ecuacion cuadratica\n");
    printf("2. Imprimir numeros con diferentes incrementos\n");
    printf("3. Sumar numeros del 1 al 5504\n");
    printf("4. Sumar numeros pares del 2 al 5504\n");
    printf("5. Calcular promedio de numeros ingresados\n");
    printf("6. Calcular y(x) de la ecuacion de la recta\n");
    printf("7. Imprimir numeros con distancia excluida\n");
    printf("8. Imprimir multiplos de 1024 del 1 al 100\n");
    printf("9. Imprimir todas las horas, minutos y segundos\n");
    printf("10. Verificar si un numero es primo\n");

    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            resolver_ecuacion_cuadratica();
            break;
        case 2:
            imprimir_numeros();
            break;
        case 3:
            sumar_numeros();
            break;
        case 4:
            sumar_numeros_pares();
            break;
        case 5:
            calcular_promedio();
            break;
        case 6:
            calcular_ecuacion_recta();
            break;
        case 7:
            imprimir_numeros_con_distancia();
            break;
        case 8:
            imprimir_multiplos();
            break;
        case 9:
            imprimir_reloj();
            break;
        case 10:
            verificar_numero_primo();
            break;
        default:
            printf("Opcion no valida.\n");
            break;
    }

    return 0;
}
