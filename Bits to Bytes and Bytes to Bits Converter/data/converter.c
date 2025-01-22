#include <stdio.h>

// Function to convert bits to bytes
void bitsToBytes() {
    int bits;
    printf("Enter the number of bits: ");
    scanf("%d", &bits);

    if (bits < 0) {
        printf("Number of bits cannot be negative.\n");
        return;
    }

    double bytes = bits / 8.0;  // 1 byte = 8 bits
    printf("%d bits = %.2f bytes\n", bits, bytes);
}

// Function to convert bytes to bits
void bytesToBits() {
    int bytes;
    printf("Enter the number of bytes: ");
    scanf("%d", &bytes);

    if (bytes < 0) {
        printf("Number of bytes cannot be negative.\n");
        return;
    }

    int bits = bytes * 8;  // 1 byte = 8 bits
    printf("%d bytes = %d bits\n", bytes, bits);
}

int main() {
    int choice;

    do {
        printf("\nConversion Menu:\n");
        printf("1. Convert bits to bytes\n");
        printf("2. Convert bytes to bits\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bitsToBytes();
                break;
            case 2:
                bytesToBits();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
