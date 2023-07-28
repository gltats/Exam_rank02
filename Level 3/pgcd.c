// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e 
// 1$
// $> ./pgcd | cat -e
// $

#include <stdio.h>
#include <stdlib.h>

// Function to calculate the Greatest Common Divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("\n");
        return 0;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    // Check if the input numbers are strictly positive
    if (num1 <= 0 || num2 <= 0) {
        printf("Invalid input\n");
        return 1;
    }

    int result = gcd(num1, num2);
    printf("%d\n", result);

    return 0;
}