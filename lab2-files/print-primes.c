/*
 print-primes.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/

#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 6

// Written by arda
int is_prime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Written by Bader
void print_number(int value) {
    static int counter = 0;  // keeps track of numbers per row
    printf("%10d", value);   // 10 spaces wide, right-aligned
    counter++;

    if (counter % COLUMNS == 0) {
        printf("\n");  // new row
    }
}

// Written by Bader
void print_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            print_number(i);
        }
    }
    printf("\n");  // final newline
}

// 'argc' contains the number of program arguments, and
// 'argv' is an array of char pointers, where each
// char pointer points to a null-terminated string.
int main(int argc, char *argv[]) {
    if (argc == 2) {
        print_primes(atoi(argv[1]));
    } else
        printf("Please state an integer number.\n");
    return 0;
}
