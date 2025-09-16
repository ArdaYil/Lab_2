// Assignment 3 — Task 2 (heap allocation)
// Typed by: <YOUR NAME>
// Partner:  <PARTNER NAME>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLUMNS 6

// Written by Bader
static void print_number(int value) {
    static int counter = 0;
    printf("%10d", value);  // right-aligned, width 10 to match the template
    counter++;
    if (counter % COLUMNS == 0) {
        printf("\n");
    }
}

// Written by Arda
static void print_sieves(int n) {
    if (n < 2) {
        printf("\n");
        return;
    }

    // Allocate (n+1) bytes on the heap: 1 = assumed prime, 0 = composite
    unsigned char *is_prime = (unsigned char *)malloc((size_t)(n + 1));
    if (!is_prime) {
        fprintf(stderr, "Error: out of memory.\n");
        return;
    }

    // Initialize to 1 (assume prime), then fix 0 and 1
    memset(is_prime, 1, (size_t)(n + 1));
    is_prime[0] = 0;
    is_prime[1] = 0;

    // Mark composites
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                is_prime[multiple] = 0;
            }
        }
    }

    // Print primes using print_number
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            print_number(i);
        }
    }
    printf("\n");

    // Release heap memory
    free(is_prime);
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