#include <stdio.h>

void main (void){
    int code, qty;
    float price, amt, totalAmt, cash, change;
    char addAnother;

    do {
        printf("===============================");
        printf("====**==LOL PIZZA MENU==**====");
        printf("===============================");
        printf("[1] Hawaiian lol \t\t $3.00\n");
        printf("[2] cheese lol \t\t $2.50\n");
        printf("[3] All-veggie lol \t\t $4.50\n");
        printf("[4] All-meat lol \t\t $5.50\n");
        printf("[5] All-in lol \t\t $2.50\n");

        printf("\nEnter Code:\t\n: ");
        scanf("%d", &code);
        printf("\nEnter quantity\t:\n");
        scanf("%d", &qty);

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
        
        }
        amt = price * qty;

        printf("\nAmount\t\t: %.2f". amt);

        totalAmt = totalAmt + amt;
        printf("\nTOtal Amout\t: %.2f", totalAmt);
    
        printf("\nAdd another order(Y/n)");
        addAnother = getch();
    }while(addAnother == 'y' || addAnother == 'y');
   
    do{
        printf("\nCash tendered:");
        scanf("%f", &cash);
    }while(cash < totalAmt);

    change = cash - total
    printf("\nChange\t\t: %.2f", change);
    printf("\n\nThank you!");

    return 0;
}