#include <stdio.h>
#include <stdlib.h>

#define LONGITUD 100000

double Varianza(double *arraylargononon, int n) {
    double suma = 0.0, sumaCuadrados = 0.0;
    for (int i = 0; i < n; i++) {
        suma += arraylargononon[i];
        sumaCuadrados += arraylargononon[i] * arraylargononon[i];
    }
    double media = suma / n;
    return (sumaCuadrados / n) - (media * media);
}

int main(void) {
    double arraylargononon[LONGITUD];
    unsigned int semilla;

    printf("Ingresa la semilla para los numeros aleatorios: ");
    scanf("%u", &semilla);
    srand(semilla);

    for (int i = 0; i < LONGITUD; i++) {
        arraylargononon[i] = (double)(rand() % 100);
    }
    double primervarianza = Varianza(arraylargononon, 20000);
    printf("Varianza de los primeros 20000 elementos: %.2f\n", primervarianza);
    double varianzaDeLaMita = Varianza(arraylargononon + 35000, 30000);
    printf("Varianza de 30000 elementos del medio: %.2f\n", varianzaDeLaMita);
    double varianzaFInal = Varianza(arraylargononon + 50000, 50000);
    printf("Varianza de los ultimos 50000 elementos: %.2f\n", varianzaFInal);

    return 0;
}
