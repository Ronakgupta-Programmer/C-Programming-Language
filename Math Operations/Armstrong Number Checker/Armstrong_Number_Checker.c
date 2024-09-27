#include <stdio.h>
#include <math.h>

int main() {
    int number, originalNumber, remainder, n = 0, result = 0;

    printf("--- Armstrong Number Checker ---\n");
    printf("Enter an integer (or -1 to exit): ");
    
    while (1) {
        scanf("%d", &number);
        
        if (number == -1) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        originalNumber = number;

        // Count the number of digits
        while (originalNumber != 0) {
            originalNumber /= 10;
            n++;
        }

        originalNumber = number;

        // Calculate the sum of the powers of its digits
        while (originalNumber != 0) {
            remainder = originalNumber % 10;
            result += pow(remainder, n);
            originalNumber /= 10;
        }

        // Check if the number is an Armstrong number
        if (result == number) {
            printf("%d is an Armstrong number.\n", number);
        } else {
            printf("%d is not an Armstrong number.\n", number);
        }

        // Reset variables for the next iteration
        n = 0;
        result = 0;

        printf("Enter another integer (or -1 to exit): ");
    }

    return 0;
}
