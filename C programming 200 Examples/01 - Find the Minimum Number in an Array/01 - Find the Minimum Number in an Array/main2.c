#include <stdio.h>

// Function to find the minimum value in an array
int find_min(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main(void) {
    // Define two arrays correctly
    int myarray1[] = {5, 9, 10, 11, 4, 3, 8, 6, 7};
    int myarray2[] = {2, 5, 9, 2, 5, 3, 0};

    // Find minimum values using the function
    int min1 = find_min(myarray1, 9);
    int min2 = find_min(myarray2, 7);

    // Print the minimum values
    printf("min1: %d\n", min1);
    printf("min2: %d\n", min2);

    return 0;
}