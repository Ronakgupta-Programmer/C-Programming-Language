#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowercase(char str[]);

int main() {
    char str[100];
    int length, i, isPalindrome = 1;

    printf("--- Palindrome Checker ---\n");
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Convert to lowercase for case-insensitive check
    toLowercase(str);

    length = strlen(str);

    // Check if the string is a palindrome
    for (i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }

    return 0;
}

// Function to convert a string to lowercase
void toLowercase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
