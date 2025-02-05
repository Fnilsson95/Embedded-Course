//
// Created by Fredrik Nilsson on 2025-02-05.
//

/* Bonus Assignment Description WP4:
Write a program in C to print all permutations of a given string using POINTERS.
The string should be provided as an argument to your program. The limit of the number
of character in the input is 10. The program should store all the permutation in a large array.

Input example: permuter.exe abcd
Output example:
All the permutations of the string abcd are: abcd acbd acdb adcb adbc... etc
 */

// A permutation is an arrangement of a set of objects in a specific order.
// The order of the objects matters in permutations. (ABC != ABC)

/* Ask yourself:
1. What is the problem asking me to do?
2. Are there any special conditions?
3. What happens in edge cases( empty input, large number etc)?

1. Read the problem carefully
2. Identity inputs and expected outputs
3. Find constraints
4. Decomposition

Example: Find the largest number in a list.
BREAK IT DOWN:
1. Initilize max_value to the first element
2. Loop through the list and compare each number to max_value
3. If a number is larger, update max_value
4. At the end of the loop, return max_value
 */

#include <stdio.h>
#include <string.h>


#define MAX_LENGTH 10
//factorial of 10, 10! --> Maximum number of permutations for 10 characters
#define FACTORIAL_10 3628800




void swap (char *x, char *y);
void permute(char *string, int left, int right);

int main (int argc, char* argv[]) {

  // Validate amount of arguments
  if (argc != 2) {
    printf("Invalid amount of arguments. Please provide only a string of 1-10 characters.\n");
       return 0;
    }

  // Store the input string
  char *input = argv[1];
  // Store the length of the input string
  int length = strlen(argv[1]);

  // Validate if the length is within valid range (1-10)
  if (length < 1 || length > MAX_LENGTH) {
    printf("Invalid input string. Must be between 1 and 10 characters.\n");
    return 0;
  }






  // Successful exit status of program.
  return 0;
}

// Function to swap values at two pointers
void swap (char *x, char *y) {

  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void permute(char *string, int left, int right)



/* Comments for myself:

isalpha() is a function from ctype.h library that checks if it is an alphabetical
character or not. So when we check !isalpha(), we check if something is not a alphabetical
character.
But since we didn't need to check for only alphabetical characters, we can use strlen from <string.h> instead
strlen(argv[1]) gets the length of the string from index 1.

 */