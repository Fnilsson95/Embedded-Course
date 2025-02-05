// Fredrik Nilsson
// Bonus Assignment WP3

#include <stdio.h>

// Define Constants
#define MAX_VALUE 99 // Max Value for integer input
#define MAX_MATRIX_SIZE 4
#define MIN_MATRIX_SIZE 1

// Starting point of program
// The program prompts user for matrix input size (I.e 2x3 or 4x4)
// and inputs values into each index in the matrices
// and then print the sums of the matrices
int main() {

  // Declaration and initialization of matrices,
  // row/column variables and i/j as loop variables
  int matrixOne[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
  int matrixTwo[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
  int sum[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
  int rows, columns;
  int i, j;

  // Initialize pointers
  int *ptrOne = &matrixOne[0][0];
  int *ptrTwo = &matrixTwo[0][0];
  int *ptrSum = &sum[0][0];


  //printf("Enter the number rows (1-4):\n");

  // Validation for input of an integer and correct row size
  if (scanf("%d", &rows) != 1 || rows < MIN_MATRIX_SIZE || rows > MAX_MATRIX_SIZE) {
    printf("Invalid Row input. Max value is: %d\n", MAX_MATRIX_SIZE);

    // Clear any possible trailing new line characters or End of File.
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    return 1;
  }

  //printf("Enter the number of columns (1-4):\n");

  // Validation for input of an integer and correct column size
  if (scanf("%d", &columns) != 1 || columns < MIN_MATRIX_SIZE || columns > MAX_MATRIX_SIZE) {
    printf("Invalid Row input. Max value is: %d\n", MAX_MATRIX_SIZE);

    // Clear any possible trailing new line characters or End of File.
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    return 1;
  }


  //printf("Enter the numbers of matrix number ONE\n");

  // Nested for-loop to enter all numbers in matrix one
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      // Validation that it is correct type of input, and value within range.
      if (scanf("%d", ptrOne) != 1 || *ptrOne > MAX_VALUE) {
        printf("Invalid input for matrix one. Please enter a number. (Max value is: %d).\n", MAX_VALUE);
        return 0;
      }
      // Increment pointer
      ptrOne++;
    }
  }

  //printf("Enter the numbers of matrix number TWO\n");

  // Nested for-loop to enter all numbers in matrix two
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      // Validation that it is correct type of input, and value within range.
      if (scanf("%d", ptrTwo) != 1 || *ptrTwo > MAX_VALUE) {
        printf("Invalid input for matrix tw0. Please enter a number. (Max value is: %d).\n", MAX_VALUE);
        return 0;
      }
      // Increment pointer
      ptrTwo++;
    }
  }

  // Reset pointer to point to the correct address (after being incremented previously)
  // Otherwise pointer points to unallocated memory and "unknown" memory --> I.e [2][0]...[2][1]

  ptrOne = &matrixOne[0][0];
  ptrTwo = &matrixTwo[0][0];

  // Nester for-loop to add the sums together from matrix one and matrix two
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      // Dereferencing of pointers
      *ptrSum++ = *ptrOne++ + *ptrTwo++;
      }
    }

  // Reset pointer to point to the correct address (after being incremented previously)
  // Otherwise pointer points to unallocated memory and "unknown" memory --> I.e [2][0]...[2][1]
  ptrSum = &sum[0][0];

  printf("The sum is:\n");
  // Nester for-loop to print the sums.
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      // Print the value of the dereferenced pointer and then increment it by 1 each loop
      printf("%d ", *ptrSum++);
      // If-statement to format the printing.
      // When last column --> print \n
      if (j == columns - 1) {
        printf("\n");
        }
      }
    }

  // Successful exit status of program
  return 0;
}