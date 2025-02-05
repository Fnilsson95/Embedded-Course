// (C) Fredrik Nilsson, Emma Olmås, Erik Lidbom
// Work package 1
// WP1 - Exercise 1 - If-statements

// Include functions for input and output (Standard Input Output)
// Include functions for handling strings (i.e strcmp)
#include <stdio.h>
#include <string.h>

// Define constants representing the maximum number of sentences
// and maximum number of characters (including the null terminator \0, hence 31)
#define MAX_SENTENCES 5
#define MAX_CHARACTERS 31

// Starting point of the program.
int main(void) {
    // Initialize a 2D array that stores up to 5 sentences,
    // with each 31 characters each, including the null terminator \0
    char sentences[MAX_SENTENCES][MAX_CHARACTERS];
    // Declare variables used for for-loops
    int i, j;
    
    // Initial for-loop that asks for a new sentence each time it increments
    for (i = 0; i < MAX_SENTENCES; i++) {
        // Prompt the user
        printf("Enter sentence number %d (Max 30 characters): ", i + 1);
        // Reads input from stdin (Standard Input) into the sentences[] array.
        fgets(sentences[i], MAX_CHARACTERS, stdin);

        // Check the length of the input that was read
        // If the last character is equal to \n we replace it with \0
        // and removes any following new line characters.
        size_t len = strlen(sentences[i]);
        if (len > 0 && sentences[i][len - 1] == '\n') {
            sentences[i][len - 1] = '\0';
        }

        // Nested for-loop to check if a sentence is unique
        // strcmp (String compare) and compare sentence with index i and index j,
        // If sentences == 0, they are not unique and decrements i to repeat first for loop.
        for (j = 0; j < i; j++) {
            if (strcmp(sentences[i], sentences[j]) == 0) {
                printf("Duplicate found.\n");
                i--;
                break;
            }
        }
    }

    // Declare and initialize variable to start while condition to true
    int input_result = 1;
    // While loop that runs while inputResult is between 1-5
    while (input_result >= 1 && input_result <= 5) {
        // Prompt the user
        printf("Let's play a game! Enter a number between 1 and 5 \n");

        // Use scanf to read an integer into inputResult variable
        // Check if successfully read exactly one number == 1
        // Check if the number is between 1 and 5
        if (scanf("%d", &input_result) == 1 && input_result >= 1 && input_result <= 5) {
            // If conditions are valid, print the corresponding sentence.
            printf("%s\n", sentences[input_result - 1]);
        } else {
            // If conditions are false, break the program.
            break;
        }
    }
    // Successful exit status
    return 0;
}
