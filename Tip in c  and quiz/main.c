#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 5
#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4

// Structure to store a quiz question
struct Question {
    char questionText[200];
    char options[MAX_OPTIONS][100];
    int correctOption; // Index of the correct option (0-3)
};

// Structure to store book details
struct Book {
    char title[100];
    char author[100];
    int year;
    struct Question quiz[MAX_QUESTIONS];
    int questionCount;
};

// Function prototypes
void addBook(struct Book books[], int *bookCount);
void viewBooks(struct Book books[], int bookCount);
void takeQuiz(struct Book books[], int bookCount);

int main() {
    struct Book books[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    while (1) {
        printf("\nBook Management with Quiz\n");
        printf("1. Add a Book with Quiz\n");
        printf("2. View Books\n");
        printf("3. Take a Quiz\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                viewBooks(books, bookCount);
                break;
            case 3:
                takeQuiz(books, bookCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to add a book with quiz questions
void addBook(struct Book books[], int *bookCount) {
    if (*bookCount >= MAX_BOOKS) {
        printf("Book storage is full!\n");
        return;
    }

    struct Book newBook;

    printf("Enter the book title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0'; // Remove newline character

    printf("Enter the author name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0'; // Remove newline character

    printf("Enter the year of publication: ");
    scanf("%d", &newBook.year);
    getchar(); // Consume newline character

    printf("Enter the number of quiz questions (max %d): ", MAX_QUESTIONS);
    scanf("%d", &newBook.questionCount);
    getchar(); // Consume newline character

    if (newBook.questionCount > MAX_QUESTIONS) {
        printf("Too many questions! Limiting to %d.\n", MAX_QUESTIONS);
        newBook.questionCount = MAX_QUESTIONS;
    }

    for (int i = 0; i < newBook.questionCount; i++) {
        printf("\nQuestion %d:\n", i + 1);
        printf("Enter the question text: ");
        fgets(newBook.quiz[i].questionText, sizeof(newBook.quiz[i].questionText), stdin);
        newBook.quiz[i].questionText[strcspn(newBook.quiz[i].questionText, "\n")] = '\0';

        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Enter option %d: ", j + 1);
            fgets(newBook.quiz[i].options[j], sizeof(newBook.quiz[i].options[j]), stdin);
            newBook.quiz[i].options[j][strcspn(newBook.quiz[i].options[j], "\n")] = '\0';
        }

        printf("Enter the correct option (1-4): ");
        scanf("%d", &newBook.quiz[i].correctOption);
        newBook.quiz[i].correctOption--; // Convert to 0-based index
        getchar(); // Consume newline character
    }

    books[*bookCount] = newBook;
    (*bookCount)++;
    printf("Book added successfully with quiz!\n");
}

// Function to display books
void viewBooks(struct Book books[], int bookCount) {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book %d:\n", i + 1);
        printf("  Title: %s\n", books[i].title);
        printf("  Author: %s\n", books[i].author);
        printf("  Year: %d\n", books[i].year);
    }
}

// Function to take a quiz for a book
void takeQuiz(struct Book books[], int bookCount) {
    if (bookCount == 0) {
        printf("No books available to take a quiz.\n");
        return;
    }

    int bookChoice;
    printf("Select a book to take the quiz:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. %s\n", i + 1, books[i].title);
    }
    printf("Enter your choice: ");
    scanf("%d", &bookChoice);
    getchar(); // Consume newline character

    if (bookChoice < 1 || bookChoice > bookCount) {
        printf("Invalid choice.\n");
        return;
    }

    struct Book selectedBook = books[bookChoice - 1];
    int score = 0;

    printf("\nQuiz for Book: %s\n", selectedBook.title);
    for (int i = 0; i < selectedBook.questionCount; i++) {
        printf("\nQuestion %d: %s\n", i + 1, selectedBook.quiz[i].questionText);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, selectedBook.quiz[i].options[j]);
        }
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);

        if (answer - 1 == selectedBook.quiz[i].correctOption) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %d. %s\n",
                   selectedBook.quiz[i].correctOption + 1,
                   selectedBook.quiz[i].options[selectedBook.quiz[i].correctOption]);
        }
    }

    printf("\nYour score: %d/%d\n", score, selectedBook.questionCount);
}
