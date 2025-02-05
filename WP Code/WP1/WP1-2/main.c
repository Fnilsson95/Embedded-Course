// (C) Fredrik Nilsson, Emma Olmås, Erik Lidbom
// Work package 1
// WP1 - Exercise 2 - Encryption

// Include libraries for Standard Input and Output functions
// and atoi function from stdlib - ASCII to Integer function
#include <stdio.h>
#include <stdlib.h>

567834


// Define constants used to remove magic numbers
#define LETTERS_IN_ALPHABET 26
#define AMOUNT_OF_ARGUMENT 2
#define DIGITS_IN_NUMBERS 10

// Starting point of the system with two parameters
// Accepts the following command line arguments:
// argc - Number of arguments provided
// argv[] - An array of arguments where argv[1] should contain the name provided
// The Main function provides an encryption program that shifts character in the ASCII table .
int main(int argc, char *argv[]) {

    // Check that the exact number of arguments are entered:
    // Name of executable file, and shift value
    if (argc != AMOUNT_OF_ARGUMENT) {
        puts("Wrong amount of arguments (Must be 2)");
        puts("To run the program correctly print the following: \n");
        puts("I.e ./main 13");
        // Return 1 as exit status - failed program
        return 1;
    }

    // Declare and initialize values to shift in the ascii table
    // Use atoi (ASCII to Integer function in order to convert string to int
    // Command-line argument always passed as strings (char* arrays)
    int shiftValue = atoi(argv[1]);

    // Declare variable to store characters read
    int character;

    // While-loop that runs until EOF is input (Control + D)
    // getchar() reads one character at a time from stdin
    // and returns the ASCII value of the character read
    while ((character = getchar()) != EOF) {

        // If and else if statements that returns based on the value read,
        // uppercase letter, lowercase letter or number
        // and returns an encrypted value of the input
        if (character >= 'A' && character <= 'Z') {
            character = ((character - 'A') + shiftValue) % LETTERS_IN_ALPHABET + 'A';
        } else if ( character >= 'a' && character <= 'z') {
            character = ((character - 'a') + shiftValue) % LETTERS_IN_ALPHABET + 'a';
        } else if (character >= '0' && character <= '9') {
            character = ((character - '0') + shiftValue) % DIGITS_IN_NUMBERS + '0';
        }
        // Prints the encrypted characters
        putchar(character);
    }
    return 0;
}