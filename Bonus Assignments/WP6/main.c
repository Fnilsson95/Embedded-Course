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
// - Do the function with dynamic memory allocation instead of shifting the array
// - Malloc to keep the input size for the arrays dynamic


#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 5
#define MAX_LENGTH 300

void compareStrings(char arr[MAX_STRINGS][MAX_LENGTH], int *size, char removedString[MAX_LENGTH]);

int main() {

    // Initize array for input strings with defined amount of strings and length.
    // char --> indicates array stores characters
    // MAX_STRINGS --> Defines the number of strings we want to store
    // MAX_LENGTH --> Defines the maximum length of each string
    // Creates a 5-row, 100-column character array
    // 5 spots in memory with MAX 100 chars per row
    char inputString[MAX_STRINGS][MAX_LENGTH];
    int size = MAX_STRINGS;
    char removedString[MAX_LENGTH];

    
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
        // size_t is an unsigned integer type used to represent the size of the object in memory
        // Since it is unsigned, it can't store negative numbers and when dealing with sizes,
        // it makes sense --> string length can't be -5 for instance
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


    // Print the initially stored strings
    printf("\nStored Strings:\n");
    // for-loop to print all the indexes
    for (int i = 0; i < MAX_STRINGS; i++) {
        printf("%s\n", inputString[i]);
    }

    // Invoke compareStrings function to compare and remove shortest string
    compareStrings(inputString, &size, removedString);

    
    // Print the shortest string that was removed
    printf("Shortest string removed: %s\n", removedString);

    // Print the strings remaining
    printf("Array after removal:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\n", inputString[i]);
    }

    // Successful exit status of program
    return 0;
}

// Function to compare all input strings, and remove shortest one
void compareStrings(char arr[MAX_STRINGS][MAX_LENGTH], int *size, char removedString[MAX_LENGTH]) {

    // Validate that there are actual strings available
    if (*size == 0) {
        return;
    }

    // Initialize variable to track index of shortest string
    int shortestIndex = 0;
    // Initialize shortest lenght to the first element
    size_t shortestLength = strlen(arr[0]);

    // for-loop to compare all the strings, starting from i = 1,
    // meaning we compare shortestLength which is already put to index 0
    for (int i = 1; i < *size; i++) {
        // Initialize currentLength to second element (i = 1)
        size_t currentLength = strlen(arr[i]);
        // If currentLength is shorter that shortestLength,
        // we assign shortestLength to currentLength
        if (currentLength < shortestLength) {
            shortestLength = currentLength;
            // Set shortestIndex to i (to track the shortest index)
            shortestIndex = i;
        }
    }
    
    // Copy the shortest string into another array
    strcpy(removedString, arr[shortestIndex]);

    // Shift and remove the shortest string
    // i = index of shortest string, and we shift all elements after it
    for (int i = shortestIndex; i < *size - 1; i++) {
        strcpy(arr[i], arr[i + 1]);
    }
    

    // Decrement the size of the array. 
    (*size)--;

}

