#include <stdio.h>

void celsiusToFahrenheit();
void fahrenheitToCelsius();
void celsiusToKelvin();
void kelvinToCelsius();
void fahrenheitToKelvin();
void kelvinToFahrenheit();

int main() {
    int choice;

    printf("--- Temperature Converter ---\n");

    do {
        printf("\nChoose the conversion type:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Celsius to Kelvin\n");
        printf("4. Kelvin to Celsius\n");
        printf("5. Fahrenheit to Kelvin\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: celsiusToFahrenheit(); break;
            case 2: fahrenheitToCelsius(); break;
            case 3: celsiusToKelvin(); break;
            case 4: kelvinToCelsius(); break;
            case 5: fahrenheitToKelvin(); break;
            case 6: kelvinToFahrenheit(); break;
            case 7: printf("Exiting the program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}

// Conversion functions
void celsiusToFahrenheit() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("Temperature in Fahrenheit: %.2f°F\n", fahrenheit);
}

void fahrenheitToCelsius() {
    float fahrenheit, celsius;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("Temperature in Celsius: %.2f°C\n", celsius);
}

void celsiusToKelvin() {
    float celsius, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    kelvin = celsius + 273.15;
    printf("Temperature in Kelvin: %.2f K\n", kelvin);
}

void kelvinToCelsius() {
    float kelvin, celsius;
    printf("Enter temperature in Kelvin: ");
    scanf("%f", &kelvin);
    celsius = kelvin - 273.15;
    printf("Temperature in Celsius: %.2f°C\n", celsius);
}

void fahrenheitToKelvin() {
    float fahrenheit, kelvin;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
    printf("Temperature in Kelvin: %.2f K\n", kelvin);
}

void kelvinToFahrenheit() {
    float kelvin, fahrenheit;
    printf("Enter temperature in Kelvin: ");
    scanf("%f", &kelvin);
    fahrenheit = (kelvin - 273.15) * 9 / 5 + 32;
    printf("Temperature in Fahrenheit: %.2f°F\n", fahrenheit);
}
