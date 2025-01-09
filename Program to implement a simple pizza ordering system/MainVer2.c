// Program to implement a simple pizza ordering system
#include <stdio.h>

int main(void) {
    // Variable declarations
    int code, qty;
    float price = 0.0, amt = 0.0, totalAmt = 0.0, cash, change;
    char addAnother;

    do {
        // Display the menu
        printf("===============================\n");
        printf("====**==LOL PIZZA MENU==**====\n");
        printf("===============================\n");
        printf("[1] Hawaiian    lol\t\t $3.00\n");
        printf("[2] Cheese      lol\t\t $2.50\n");
        printf("[3] All-veggie  lol\t\t $4.50\n");
        printf("[4] All-meat    lol\t\t $5.50\n");
        printf("[5] All-in      lol\t\t $2.50\n\n\n");

        // Prompt user for their choice
        printf("\nEnter Code: ");
        scanf("%d", &code);
        printf("\nEnter Quantity: ");
        scanf("%d", &qty);

        // Determine price based on code
        switch (code) {
            case 1:
                price = 3.00;
                break;
            case 2:
                price = 2.50;
                break;
            case 3:
                price = 4.50;
                break;
            case 4:
                price = 5.50;
                break;
            case 5:
                price = 2.50;
                break;
            default:
                // Handle invalid code
                printf("Invalid code. Please try again.\n");
                continue;
        }

        // Calculate amount and update total
        amt = price * qty;
        printf("\nAmount: \t\t $%.2f\n", amt);

        totalAmt += amt;
        printf("Total Amount: \t $%.2f\n", totalAmt);

        // Check if the user wants to order more
        printf("\nAdd another order (Y/n): ");
        scanf(" %c", &addAnother);

    } while (addAnother == 'Y' || addAnother == 'y');

    do {
        // Prompt for payment
        printf("\nCash tendered: ");
        scanf("%f", &cash);
        if (cash < totalAmt) {
            // Notify insufficient funds
            printf("Insufficient cash. Please provide enough to cover the total amount.\n");
        }
    } while (cash < totalAmt);

    // Calculate and display change
    change = cash - totalAmt;
    printf("\nChange: \t\t $%.2f\n", change);
    printf("\nThank you!\n");

    return 0;
}
