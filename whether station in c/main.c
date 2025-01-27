#include <stdio.h>

// Function to convert Celsius to Fahrenheit
void celsius_to_fahrenheit() {
    double celsius, fahrenheit;
    printf("Enter the temperature in Celsius: ");
    scanf("%lf", &celsius); // Read a double value
    fahrenheit = celsius * 1.8 + 32;
    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert Fahrenheit to Celsius
void fahrenheit_to_celsius() {
    double fahrenheit, celsius;
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit); // Read a double value
    celsius = (fahrenheit - 32) / 1.8;
    printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
}

// Main function with a menu for the user
int main() {
    int choice;
    while (1) {
        printf("\nTemperature Conversion Program\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Choose an option (1/2/3): ");
        scanf("%d", &choice); // Read an integer value

        switch (choice) {
            case 1:
                celsius_to_fahrenheit();
                break;
            case 2:
                fahrenheit_to_celsius();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }
}
