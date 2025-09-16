/*
 pointers.c
 By David Broman.
 Last modified: 2015-09-15
 This file is in the public domain.
*/

#include <stdio.h>
#include <stdlib.h>

// Written by Arda
static const char text1[] = "This is a string.";
static const char text2[] = "Yet another thing.";

// Written by Arda
static int list1[sizeof(text1)];
static int list2[sizeof(text2)];

// Written by Arda
static int counter = 0;

// Written by Bader
void copycodes(const char *src, int *dst, int *counter) {
    const unsigned char *p = (const unsigned char *)src;  // a0
    int *q = dst;                                         // a1
    int *c = counter;                                     // a2

    // loop:
    while (*p != 0) {    // lb t0,0(a0); beqz t0,done
        *q = (int)(*p);  // sw t0,0(a1)
        p = p + 1;       // addi a0,a0,1
        q = q + 1;       // addi a1,a1,4  (int is 4 bytes)
        int t1 = *c;     // lw  t1,0(a2)
        t1 = t1 + 1;     // addi t1,t1,1
        *c = t1;         // sw  t1,0(a2)
    }
    // done: jr ra
}

// Written by Arda
void printlist(const int *lst) {
    printf("ASCII codes and corresponding characters.\n");
    while (*lst != 0) {
        printf("0x%03X '%c' ", *lst, (char)*lst);
        lst++;
    }
    printf("\n");
}

void endian_proof(const char *c) {
    printf("\nEndian experiment: 0x%02x,0x%02x,0x%02x,0x%02x\n",
           (int)*c, (int)*(c + 1), (int)*(c + 2), (int)*(c + 3));
}

// Written by Bader
void work(void) {
    // Matches:
    //   la a0,text1; la a1,list1; la a2,counter; jal copycodes
    //   la a0,text2; la a1,list2; la a2,counter; jal copycodes
    extern const char text1[];
    extern const char text2[];
    extern int list1[];
    extern int list2[];
    extern int counter;

    copycodes(text1, list1, &counter);
    copycodes(text2, list2, &counter);
}

int main(void) {
    work();
    printf("\nlist1: ");
    printlist(list1);
    printf("\nlist2: ");
    printlist(list2);
    printf("\nCount = %d\n", counter);

    endian_proof((char *)&counter);
}
