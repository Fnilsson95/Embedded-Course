#include <stdio.h>
#include <string.h> // Provides strlen() and strcpy() functions
#include <stdlib.h> // Provides malloc() and free() functions 

// Define the maximum input length
#define MAX_LENGTH 10
//factorial of 10, 10! --> Maximum number of permutations for 10 characters
#define FACTORIAL_10 3628800


// Initalize variable to keep track of how many permutations stored
int permutationIndex = 0;
// Declare a pointer to an array of pointers
char **permutations;

// Declare function prototypes
void swap (char *x, char *y);
void permute(char *string, int left, int right);

// Starting point of the program
// Program generates and stores all permutations of a given input string
int main (int argc, char* argv[]) {

  // Validate amount of arguments
  if (argc != 2) {
    printf("Invalid amount of arguments. Please provide only a string of 1-10 characters.\n");
       return 0;
    }

  // Store the input string
  // input is a pointer to the first element of the string provided
  char *input = argv[1];
  // Store the length of the input string
  int length = strlen(input);

  // Validate if the length is within valid range (1-10)
  if (length < 1 || length > MAX_LENGTH) {
    printf("Invalid input string. Must be between 1 and 10 characters.\n");
    return 0;
  }

  // Compute the number of permutations for dynamic memory allocation
  // Assigned to 1 as an initial value (Min amount of permutations). 
  int totalPermutations = 1;
  for (int i = 2; i <= length; i++) {
    totalPermutations = totalPermutations * i;
  }

  // Allocate memory dynamically depending on size of totalPermutations
  permutations = malloc(totalPermutations * sizeof(*permutations));
  if (permutations == NULL) {
    printf("Memory allocation failed.\n");
    return 0;
  }

  // Invoke permute function which will generate and store all permutations
  permute(input, 0, length -1);

  // Print all the permutations found
  printf("All permutations of the string %s are: ", input);
  // Loops trhough al permutations and prints them
  for (int i = 0; i < permutationIndex; i++) {
    printf("%s", permutations[i]);
  }
  printf("\n");


  // Free allocated memory
  for (int i = 0; i < permutationIndex; i++) {
    // Free each allocated string
    free(permutations[i]);
  } 

  // Free the array of pointers allocated
  free(permutations);
  // Successful exit status of program.
  return 0;
}

// Function to swap values of two characters using pointers
void swap (char *x, char *y) {

  // Initialize temp variable to hold one value while swapping
  char temp;
  // Save original value of x in temp
  temp = *x;
  // Overwrite x with value of y
  *x = *y;
  // Set y to original value of x
  *y = temp;
}

// Function to generate all permutations of the input string
// using recursion and swap function
// Pointer to the input string, starting index of substring and last index of substring
void permute(char *string, int left, int right) {

  // If left == right, string is permuted
  // I.e "abc", when left = 2 and right = 2, "abc" is completed
  if (left == right) {

    // Allocate memory for new permutation
    // strlen(string) + 1 to include null terminator
    permutations[permutationIndex] = malloc((strlen(string) + 1) * sizeof(char));

    // Validate if memory allocation failed - i.e insufficient memory
    if(permutations[permutationIndex] == NULL) {
      printf("Memory allocation failed.\n");
      return 0;
    }

    // Copy and store the current permutation
    strcpy(permutations[permutationIndex], string);
    // Increment how many permutations found
    permutationIndex++;
  } else {
    // Recursive case for generation permutations
    // Loops through each character from left to right
    // Swaps characters, recursively calls permute() and swaps again
    for (int i = left; i <= right; i++) {
      swap((string + left), (string + i));
      permute(string, left + 1, right);
      swap((string + left), (string + i));
    }
  }
}