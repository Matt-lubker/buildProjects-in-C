#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
 {
    int table = 0;
    printf("\nA number to generate a multiplication\n\n\t>> ");
    scanf("%i", &table);

    for(int x = 1; x<=10; ++x){
        printf("%ix%i = %i\n", x, table, x * table);
    }

    return 0;
}

}