#include<stdio.h>
#include<stdlib.h>

void imprimeBinarioRecursive(int n) {
    if (n < 2)
        printf("%d", n);
    else {
        imprimeBinarioRecursive(n / 2); // división entera
        printf("%d", n % 2);        
    }
}

int main(int narg, char *args[]) {
    int n;
    if (narg > 1) { // args[0] es el nombre del programa
        n = atoi(args[1]);
    } else {
        n = 48; // valor por defecto
    }

    printf("\n%d en binario es: ", n);        
    imprimeBinarioRecursive(n);
    printf("\n");        

    return 0;
}
