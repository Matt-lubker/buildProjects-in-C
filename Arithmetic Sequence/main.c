#include <stdio.h>


void printArithmeticSequence(int a1, int d, int n) {
    printf("Arithmetic Sequence: ");
    for (int i = 0; i < n; i++) {  
        printf("%d ", a1 + i * d);  
    }
    printf("\n");
}

int main() {
    int a1, d, n;

    
    printf("Enter the first term (a1): ");
    scanf("%d", &a1);

    printf("Enter the common difference (d): ");
    scanf("%d", &d);  

    printf("Enter the number of terms (n): ");
    scanf("%d", &n); 
    
    printArithmeticSequence(a1, d, n); 

    return 0;
}
