// Bonus Assignment WP6
// Fredrik Nilsson

/* Exercise Description

Write a program that reads 5 strings from the console,
stores them in an array and finds the shortest string

Function:
Program should contain a function that takes the array as parameter,
finds the shortest string, remove it and return the array that is 
shorter by one element.


The program should write the string that has been removed to the console
Also print the elements of the array before and after removal


- Define variables and macros where possible
1. Prompt user
2. Read and store user input (Either specific size or store via Malloc for dynamic allocation?)
3. Validation --> 5 strings (Certain size, only letters?)
4. Create function
5. strcpr(array[i] and array[j] ? or array[i] and array[i+1] or pointers?)

6. Do it normally first, make it work, then do pointers and malloc if possible
*/



// TODO
// 1. Make seperate functions about functionality later
// - strlen function
// - clear buffer function
// - read strings function


#include <stdio.h>

#define MAX_STRINGS 5
#define MAX_LENGTH 100

void compareStrings();

int main() {

    // Initize array for input strings with defined amount of strings and length.
    // char --> indicates array stores characters
    // MAX_STRINGS --> Defines the number of strings we want to store
    // MAX_LENGTH --> Defines the maximum length of each string
    // Creates a 5-row, 100-column character array
    // 5 spots in memory with MAX 100 chars per row
    char inputString[MAX_STRINGS][MAX_LENGTH];

    
    printf("Enter %d strings:\n", MAX_STRINGS);
    for(int i = 0; i < MAX_STRINGS; i++) {
        printf("String %d: ", i +1);

        // fgets() reads input from the user (stdin) and includes spaces.
        // fgets(char *str, int size, FILE *stream);
        // char *str --> A pointer to a character array (where input will be stored)
        // size --> Maximum number of characters to read (including null terminator)
        // FILE *stream --> Pointer to the input stream, in this case stdin as the stream)

        // fgets keeps \n characters and spaces, so if we press enter, fgets stores \n
        // So we also need to remove any trailing new line characters
        // It prevents buffer overflow by limit the input size, but also includes \n
        fgets(inputString[i], MAX_LENGTH, stdin);

        // Check if the input was too long and no newline character stored
        size_t len = strlen(inputString[i]);
        if (len > 0 && inputString[i][len - 1] == '\n') {
            // Remove trailing newline and replace with null terminator
            inputString[i][len -1] = '\0';
        } else {
            // Clear buffer if input was too long
            int c; 
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } // End of for-loop


    printf("\nStored Strings:\n");
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("%s\n", inputString[i]);
    }

    return 0;
}


void compareStrings() {}

