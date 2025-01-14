#include <stdio.h>
#include <limits.h>
#include <float.h>
//needs 
void displayIntegerTypes() {
    printf("\nInteger Types:\n");
    printf("---------------------------------------------------\n");
    printf("Type               | Size (bits) | Min Value          | Max Value\n");
    printf("---------------------------------------------------\n");
    printf("char               | %2zu         | %20d | %20d\n", sizeof(char) * 8, CHAR_MIN, CHAR_MAX);
    printf("unsigned char      | %2zu         | %20d | %20u\n", sizeof(unsigned char) * 8, 0, UCHAR_MAX);
    printf("short              | %2zu         | %20d | %20d\n", sizeof(short) * 8, SHRT_MIN, SHRT_MAX);
    printf("unsigned short     | %2zu         | %20d | %20u\n", sizeof(unsigned short) * 8, 0, USHRT_MAX);
    printf("int                | %2zu         | %20d | %20d\n", sizeof(int) * 8, INT_MIN, INT_MAX);
    printf("unsigned int       | %2zu         | %20d | %20u\n", sizeof(unsigned int) * 8, 0, UINT_MAX);
    printf("long               | %2zu         | %20ld | %20ld\n", sizeof(long) * 8, LONG_MIN, LONG_MAX);
    printf("unsigned long      | %2zu         | %20d | %20lu\n", sizeof(unsigned long) * 8, 0, ULONG_MAX);
    printf("long long          | %2zu         | %20lld | %20lld\n", sizeof(long long) * 8, LLONG_MIN, LLONG_MAX);
    printf("unsigned long long | %2zu         | %20d | %20llu\n", sizeof(unsigned long long) * 8, 0, ULLONG_MAX);
}

void displayFloatingPointTypes() {
    printf("\nFloating-Point Types:\n");
    printf("---------------------------------------------------\n");
    printf("Type               | Size (bits) | Min Value          | Max Value\n");
    printf("---------------------------------------------------\n");
    printf("float              | %2zu         | %-20e | %-20e\n", sizeof(float) * 8, FLT_MIN, FLT_MAX);
    printf("double             | %2zu         | %-20e | %-20e\n", sizeof(double) * 8, DBL_MIN, DBL_MAX);
    printf("long double        | %2zu         | %-20Le | %-20Le\n", sizeof(long double) * 8, LDBL_MIN, LDBL_MAX);
}

void displayExampleVariables() {
    printf("\nExample Variables:\n");
    printf("---------------------------------------------------\n");

    char myChar = 'A';
    int myInt = 42;
    float myFloat = 3.14f;
    double myDouble = 2.718281828459045;
    long myLong = 123456789L;

    printf("Variable           | Type               | Size (bits) | Value\n");
    printf("---------------------------------------------------\n");
    printf("myChar             | char               | %2zu         | '%c'\n", sizeof(myChar) * 8, myChar);
    printf("myInt              | int                | %2zu         | %d\n", sizeof(myInt) * 8, myInt);
    printf("myFloat            | float              | %2zu         | %.2f\n", sizeof(myFloat) * 8, myFloat);
    printf("myDouble           | double             | %2zu         | %.15f\n", sizeof(myDouble) * 8, myDouble);
    printf("myLong             | long               | %2zu         | %ld\n", sizeof(myLong) * 8, myLong);
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Display Integer Types (Sizes and Ranges)\n");
        printf("2. Display Floating-Point Types (Sizes and Ranges)\n");
        printf("3. Display Example Variables\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayIntegerTypes();
                break;
            case 2:
                displayFloatingPointTypes();
                break;
            case 3:
                displayExampleVariables();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
