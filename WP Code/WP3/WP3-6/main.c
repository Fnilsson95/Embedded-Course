// (C) Emma Olmås, Fredrik Nilsson, Erik Lidbom, group: 34 (2025)
// Work package 3
// Exercise 6 - Arrays and Files
// Submission code: 

// Include libraries for extra functionalities - getchar(), isalpha(), strlen(), strcpy()
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define Macro for MAX number of characters
// 20 + 1 for Null Terminator
#define MAX 21

// Function prototype
void copyString(char *outputString, const char *inputString);

// Starting point of program
// Program reads an input string from the user (20 characters) and copies it to another string
// Program can also read from a txt file (Example: main.c < myfile.txt)
int main () {

    // Initialize character arrays of size MAX
    char inputString[MAX];
    char copiedString[MAX];
    char copiedStringWithOwnFunction[MAX];

    // Prompt user to input a string (Max 20 characters)
    printf("Enter a string with max 20 characters:\n");
    scanf("%20s", inputString);

    // Remove any possible trailing new line characters
    int c; 
    while ((c = getchar()) != '\n' && c != EOF);

    // Validate that only letters have been input 
    for (int i = 0; i < strlen(inputString); i++) {
        if(!isalpha(inputString[i])) {
            printf("Invalid input. Only letters should be input\n");
            break;
        }
    }



    

    // Using predefined function to copy string from one to another - (destination, source)
    strcpy(copiedString, inputString);

    // Using own function to manually copy string from one to another - (destination, source )
    copyString(copiedStringWithOwnFunction, inputString);

    // Print the strings copied with different functions
    printf("%s\n", copiedString);
    printf("The copied string with my own function is: %s\n", copiedStringWithOwnFunction);


    // Successful exit status of program
    return 0;
}

// Function to manually copy a string from another string, using pointer arithmetics
// Parameters: Two pointers to character arrays
void copyString(char *outputString, const char *inputString) {

    // While-loop to check if current character is NOT '\0' null terminator - End of the string
    while(*inputString != '\0') {
        // The value stored at the inputString pointers position is copied
        // to the outputString pointers current position
        *outputString = *inputString;
        // Increment both pointers positions to next character
        outputString++;
        inputString++;
    }
    // When we reach '\0' of inputString, we add the null terminator to the outputString manually
    *outputString = '\0';
}