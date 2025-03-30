#include "suma.h"

int sumaRecursiva(int vector[], int n) {
    if (n == 0) {
        return 0;
    } else {
        return vector[0] + sumaRecursiva(vector + 1, n - 1);
    }
}
