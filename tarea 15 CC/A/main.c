#include <stdio.h>
#include "primo.h"

int main() {
    for (int i = 0; i < 10; i++) {
        printf("%d ", nextPrime());
    }
    return 0;
}
