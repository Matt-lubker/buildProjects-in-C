#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    double balance = 0, amount = 0;
    int choice = 0;

    while (true) {
        printf("1) Deposit\n");
        printf("2) Withdraw\n");
        printf("3) Print balance\n");
        printf("4) Print balance and Quit\n");
        printf("5) Quit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Amount: ");
                scanf("%lf", &amount);
                balance += amount;
                break;

            case 2:
                printf("Enter Amount: ");
                scanf("%lf", &amount);
                balance -= amount;
                break;

            case 3:
                printf("Balance: %.2f\n", balance);
                break;

            case 4:
                printf("Balance: %.2f\n", balance);
                exit(0);

            case 5:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
