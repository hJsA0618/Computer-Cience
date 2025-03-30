#include <stdio.h>

void verificarFloat(float valor) {
    unsigned int *pInt;
    unsigned int bits;

    pInt = (unsigned int*)&valor;
    bits = *pInt;

    printf("Representación en bits de %f:\n", valor);
    for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
        printf("%u", (bits >> i) & 1);
    }
    printf("\n");

    unsigned int expectedBits = 0x3E200000;
    if (bits == expectedBits) {
        printf("La representacion en bits coincide con la esperada.\n");
    } else {
        printf("La representacion en bits NO coincide con la esperada.\n");
    }
}

int main() {
    float valor = 0.15625f;
    verificarFloat(valor);
    return 0;
}
