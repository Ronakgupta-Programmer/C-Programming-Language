#include <stdio.h>

void printFibonacci(int n);

int main() {
    int terms;

    printf("--- Fibonacci Series Generator ---\n");
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("Fibonacci Series up to %d terms: \n", terms);
        printFibonacci(terms);
    }

    return 0;
}

// Function to print the Fibonacci series
void printFibonacci(int n) {
    int a = 0, b = 1, next;

    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}
