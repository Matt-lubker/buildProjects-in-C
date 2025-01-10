#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <conio.h>

int main()
{
    setlocale(LC_ALL, ""); // Set locale for language supports

    printf("Hello world!\n");
    printf("Program: Choose an option\n");

    float num1, num2, result;
    char op;

    do {
        num1 = num2 = result = 0; // Reset variables

        // Display menu
        printf("\nChoose an operation:\n");
        printf(" (+) Add\n");
        printf(" (-) Subtract\n");
        printf(" (*) Multiply\n");
        printf(" (/) Divide\n");
        printf(" (0) Exit\n");

        printf("Enter the operation or type 0 to exit: ");
        op = getche(); // Get the user's choice
        printf("\n");

        if (op != '0') // Check if the user wants to exit
        {
            printf("Enter the first number: ");
            scanf("%f", &num1);
            setbuf(stdin, NULL); // Clear input buffer

            printf("Enter the second number: ");
            scanf("%f", &num2);
            setbuf(stdin, NULL); // Clear input buffer

            // Perform operations based on the choice
            if (op == '+') {
                result = num1 + num2;
                printf("The result of the addition is: %.2f\n", result);
            } else if (op == '-') {
                result = num1 - num2;
                printf("The result of the subtraction is: %.2f\n", result);
            } else if (op == '*') {
                result = num1 * num2;
                printf("The result of the multiplication is: %.2f\n", result);
            } else if (op == '/') {
                if (num2 != 0) { // Check for division by zero
                    result = num1 / num2;
                    printf("The result of the division is: %.2f\n", result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
            } else {
                printf("Invalid operation. Please try again.\n");
            }
        }

    } while (op != '0'); // Loop until the user chooses to exit

    printf("\nProgram terminated. Goodbye!\n");
    return 0;
}
