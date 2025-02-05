#include <stdio.h>
#include <string.h>

// Define constant variables
#define NAME_MAX_LENGTH 50
#define NAME_MIN_LENGTH 3

// Entry point of the program
// Accepts the following command line arguments:
// argc - Number of arguments provided
// argv[] - An array of arguments where argv[1] should contain the name provided
// The Main function provides a personalized greeting asking about your day after providing your name.
int main (int argc, char *argv[]) {

  // Check if no name parameters were received
  // If argc = 1 --> only file name provided and no additional parameter
  if (argc == 1) {
    printf("No command line argument provided, please provide a name.\n"); // Printline statement for error
    return 0; // Returns 1 as exit status upon error
  }

  // Initialize variable for received input name
  // And calculates length with "strlen" function - String Length.
  int input_name_length = strlen(argv[1]);

  // If-statement which compares input name with defined constants
  // If input name consists of more than 50 characters
  if (input_name_length > NAME_MAX_LENGTH) {
    printf("Name too long, max 50 characters\n"); // Printline statement for error
    return 0; // Returns 1 as an exit status upon error
  }

  // If-statement which compares input name with defined constants
  // If input name consists of less than 3 characters
  if (input_name_length < NAME_MIN_LENGTH) {
    printf("Name too short, min 3 characters\n"); // Printline statement for error
    return 0; // Returns 1 as an exit status upon error
  }

  // Personalized greeting and asks regarding your day if successful parameter was received.
  printf("Hello %s, how is your day today?\n", argv[1]);
  return 0; // Returns 0 as an exit status upon success

}
