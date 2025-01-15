#include <stdio.h>

void calculateAverage();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateAverage();
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}

void displayMenu() {
    printf("\n----- Grade Calculator  -----\n");
    printf("1. Calculate Average Grades\n");
    printf("2. Exit\n");
    printf(".............................\n\n");
}

void calculateAverage() {
    int numGrades, i;
    float grade, sum = 0, average;

    printf("\nEnter the number of grades: ");
    scanf("%d", &numGrades);

    if (numGrades <= 0) {
        printf("Invalid input. The number of grades must be greater than zero.\n");
        return;
    }

    for (i = 1; i <= numGrades; i++) {
        printf("Enter grade %d: ", i);
        scanf("%f", &grade);

        if (grade < 0 || grade > 100) {
            printf("Invalid grade. Please enter a grade between 0 and 100.\n");
            i--; // Retry the current grade
            continue;
        }

        sum += grade;
    }

    average = sum / numGrades;
    printf("The average grade is: %.2f\n", average);

    if (average >= 7.5) {
        printf("Status: Approved!\n");
    } else {
        printf("Status: Reproved.\n");
    }

    // Option to add an extra grade
    char addGrade;
    printf("\nWould you like to add another grade to update the average? (y/n): ");
    scanf(" %c", &addGrade);

    if (addGrade == 'y' || addGrade == 'Y') {
        printf("Enter the additional grade: ");
        scanf("%f", &grade);

        if (grade < 0 || grade > 100) {
            printf("Invalid grade. Please enter a grade between 0 and 100.\n");
        } else {
            sum += grade;
            numGrades++;
            average = sum / numGrades;
            printf("Updated average grade is: %.2f\n", average);

            if (average >= 7.5) {
                printf("Updated Status: Approved!\n");
            } else {
                printf("Updated Status: Reproved.\n");
            }
        }
    }
}
