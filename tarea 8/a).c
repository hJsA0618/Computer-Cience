#include <stdio.h>
#include <string.h>

#define N 100

int my_strcmp(char c1[], char c2[]) {
    int i = 0;
    while (c1[i] != '\0' && c2[i] != '\0') {
        if (c1[i] != c2[i]) {
            return 1;
        }
        i++;
    }
    return (c1[i] == c2[i]) ? 0 : 1;
}

int main(void) {
    char cad1[N], cad2[N];
    int valor_mi, valor_std;

    printf("Ingresa la primera cadena de caracteres: ");
    fgets(cad1, N, stdin);
    cad1[strcspn(cad1, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Ingresa la segunda cadena de caracteres: ");
    fgets(cad2, N, stdin);
    cad2[strcspn(cad2, "\n")] = '\0'; // Eliminar el salto de línea

    valor_mi = my_strcmp(cad1, cad2);
    valor_std = strcmp(cad1, cad2);

    if (valor_mi == 0) {
        printf("my_strcmp: Las cadenas son iguales\n");
    } else {
        printf("my_strcmp: Las cadenas son diferentes\n");
    }

    if (valor_std == 0) {
        printf("strcmp: Las cadenas son iguales\n");
    } else {
        printf("strcmp: Las cadenas son diferentes\n");
    }

    return 0;
}
