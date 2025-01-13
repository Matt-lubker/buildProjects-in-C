
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Maximum string lengths (including null terminator) for quiz questions and answers
#define MAX_QUESTION 256
#define MAX_ANSWER 128

// Total number of questions in the quiz
#define TOTAL_QUESTIONS 5

// Define a struct for quiz questions
typedef struct {
    char question[MAX_QUESTION];
    char answerA[MAX_ANSWER];
    char answerB[MAX_ANSWER];
    char answerC[MAX_ANSWER];
    char answerD[MAX_ANSWER];
    char correct_answer;
} quiz_question;

int main(void) {
    // Array to store the quiz questions
    quiz_question quiz[TOTAL_QUESTIONS];

    // Initialize quiz questions
    strcpy(quiz[0].question, "What does the ++ operator do?");
    strcpy(quiz[0].answerA, "Add two to a number");
    strcpy(quiz[0].answerB, "Add one to a number");
    strcpy(quiz[0].answerC, "Subtract one from a number");
    strcpy(quiz[0].answerD, "Subtract two from a number");
    quiz[0].correct_answer = 'B';

    strcpy(quiz[1].question, "C is a successor of which language?");
    strcpy(quiz[1].answerA, "B");
    strcpy(quiz[1].answerB, "C++");
    strcpy(quiz[1].answerC, "Python");
    strcpy(quiz[1].answerD, "Java");
    quiz[1].correct_answer = 'A';

    strcpy(quiz[2].question, "When is a do-while loop condition checked?");
    strcpy(quiz[2].answerA, "Before the loop body executes");
    strcpy(quiz[2].answerB, "Never");
    strcpy(quiz[2].answerC, "While the loop body executes");
    strcpy(quiz[2].answerD, "After the loop body executes");
    quiz[2].correct_answer = 'D';

    strcpy(quiz[3].question, "What does a pointer variable store?");
    strcpy(quiz[3].answerA, "A floating-point number");
    strcpy(quiz[3].answerB, "A string");
    strcpy(quiz[3].answerC, "A memory address");
    strcpy(quiz[3].answerD, "An array");
    quiz[3].correct_answer = 'C';

    strcpy(quiz[4].question, "How can we check if x does not equal y in C?");
    strcpy(quiz[4].answerA, "x <> y");
    strcpy(quiz[4].answerB, "x != y");
    strcpy(quiz[4].answerC, "x === y");
    strcpy(quiz[4].answerD, "x DNE y");
    quiz[4].correct_answer = 'B';

    // Variable to store the total number of correct answers
    double total_correct = 0;

    // Variable to store the user's answer
    char answer;

    // Iterate through the questions
    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        printf("Question %d: %s\n\n", i + 1, quiz[i].question);
        printf("A) %s\n", quiz[i].answerA);
        printf("B) %s\n", quiz[i].answerB);
        printf("C) %s\n", quiz[i].answerC);
        printf("D) %s\n", quiz[i].answerD);
        printf("\nEnter Answer (A, B, C, or D): ");

        scanf(" %c", &answer);
        if (toupper(answer) == quiz[i].correct_answer) {
            total_correct++;
            printf("\nCorrect Answer!\n");
        } else {
            printf("\nIncorrect Answer!");
            printf("\nThe correct answer was %c.\n", quiz[i].correct_answer);
        }
        printf("\n\n");
    }

    // Display the result
    printf("%d/%d questions answered correctly", (int)total_correct, TOTAL_QUESTIONS);
    printf(" (%.2f%%)\n", (total_correct / TOTAL_QUESTIONS) * 100);

    return 0;
}
*/
/*
#include <stdio.h>

#define MAX_QUESTION 256
#define MAX_ANSWER 128

typedef struct 
{
    char question[MAX_QUESTION];
    char answerA[MAX_ANSWER];
    char answerB[MAX_ANSWER];
    char answerC[MAX_ANSWER];
    char answerD[MAX_ANSWER];
    char correct_answer;
} quiz_question;

int main(void)
{
    quiz_question quiz[TOTAL_QUESTIONS];

    strcpy(quiz[0].question,"What dos the ++ operator do?");
    strcpy(quiz[0].answerA,"Add two");
    strcpy(quiz[0].answerB,"");
    strcpy(quiz[0].answerC,"");
    strcpy(quiz[0].answerD,"");
    quiz[0].correct_answer = 'B';

    double total_corret = 0;
    char answer;

    for (int i 0; 1 < TOTAL_QUESTIONS; i++)
    {
        printf("Question %d: % \n\n", (i+1+), quiz[i].question);
        printf("A) %s\n", quiz[i].answerA);
        printf("B) %s\n", quiz[i].answerB);
        printf("C) %s\n", quiz[i].answerC);
        printf("D) %s\n", quiz[i].answerD);
        printf("\nEnter Answer (A, B,C or D): ");


        scanf("% c", &answer);

        if (toupper(answer) == quiz[i].correct_answer)
        {
            total_corret++;
            printf("\n\nCorrect Answer!");

        }
        else
        {
            printf("\n\nIncorrect Answer!");
            printf("\n\nThe correct answer was %C.",
                quiz[i].correct_answer);
        
        }

            printf("\n\n\n");

        }

        printf("%d%d question answered correctly",(int) total_corret. 
        TOTAL_QUESTIONS);

        printf("(%.2f%%)",
        ((total_corret / TOTAL_QUESTIONS)* 100))



    }

    return 0;
}
*/





































