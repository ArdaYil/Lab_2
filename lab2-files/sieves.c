#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

// Written by Bader
void print_number(int value) {
    static int counter = 0;
    printf("%10d", value);  // right-aligned, width 10 as in the template/output
    counter++;
    if (counter % COLUMNS == 0) {
        printf("\n");
    }
}

// Written by Arda
void print_sieves(int n) {
    if (n < 2) {  // nothing to print
        printf("\n");
        return;
    }

    // Assign array and size
    char is_prime[n + 1];

    /* Initialize: assume all numbers are prime, then fix 0 and 1 */
    for (int i = 0; i <= n; i++) is_prime[i] = 1;
    is_prime[0] = 0;
    is_prime[1] = 0;

    /* Classic Sieve of Eratosthenes */
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                is_prime[multiple] = 0;
            }
        }
    }

    /* Print primes using print_number */
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            print_number(i);
        }
    }
    printf("\n");  // final newline
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <max_number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    print_sieves(n);
    return 0;
}