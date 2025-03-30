#include "primo.h"

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int nextPrime() {
    static int current = 1;
    do {
        current++;
    } while (!isPrime(current));
    if (current == 1000) {
        current = 1;
    }
    return current;
}
