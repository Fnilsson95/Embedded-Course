// Fredrik Nilsson
// Bonus Assignment WP3

#include <stdio.h>

// Define Constants
#define MAX_VALUE 99 // Max Value for integer input
#define MAX_MATRIX_SIZE 4

int main() {

  // Declaration and initialization of matrices,
  // row/column variables and i/j as loop variables
  int matrixOne[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
  int matrixTwo[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
  int sum[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
  int rows, columns;
  int i, j;

  // ptrSum is a pointer to an integer that stores the address of the first element in the sum matrix
  // It stores the memory address of sum[0][0], meaning it points to the first element of the matrix
  // ptrSum can be used to access the sum matrix using pointer arithmetic instead of array indexing
  // Address   Value
  // 1000      5   <-- sum[0][0] (ptrSum points here)
  // 1004      6   <-- sum[0][1]
  // 1008      7   <-- sum[1][0]
  // 1012      8   <-- sum[1][1]
  // printf("%d", *ptrSum) --> prints Value 5
  // printf("%d", *ptrSum + 2) --> prints Value 7

  int *ptrOne = &matrixOne[0][0];
  int *ptrTwo = &matrixTwo[0][0];
  int *ptrSum = &sum[0][0];


  //printf("Enter the number rows (1-4):\n");
  if (scanf("%d", &rows) != 1 || rows < 1 || rows > MAX_MATRIX_SIZE) {

    printf("Invalid Row input");
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    return 0;
  }

  //printf("Enter the number of columns (1-4):\n");
  if (scanf("%d", &columns) != 1 || columns < 1 || columns > MAX_MATRIX_SIZE) {

    printf("Invalid Column input");
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    return 0;
  }


  //printf("Enter the numbers of matrix number ONE\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      //printf("Enter element at spot: %d %d:\n", (i + 1), (j + 1));
      // if (scanf("%d", &matrixOne[i][j]) != 1 || matrixOne[i][j] < MIN_VALUE || matrixOne[i][j] > MAX_VALUE) {
      // Firstly, we don't dereference the pointer, simply because we want to get the address, not the actual value.
      // Secondly, we do dereference the pointer to actually compare the VALUE and not the address.
      // Therefore first is (ptrOne) and second one is *(ptrOne)
      if (scanf("%d", ptrOne) != 1 || *ptrOne > MAX_VALUE) {
        printf("Invalid input for matrix one. Please enter a number between %d and %d.\n", MIN_VALUE, MAX_VALUE);
        return 0;
      }
      ptrOne++;
    }
  }

  //printf("Enter the numbers of matrix number TWO\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      //printf("Enter the elements at spot: %d %d:\n", (i + 1), (j + 1));
      //if (scanf("%d", &matrixTwo[i][j]) != 1 || matrixTwo[i][j] < MIN_VALUE || matrixTwo[i][j] > MAX_VALUE) {
      if (scanf("%d", ptrTwo) != 1 || *ptrTwo > MAX_VALUE) {
        printf("Invalid input for matrix two. Please enter a number between %d and %d\n", MIN_VALUE, MAX_VALUE);
        return 0;
      }
      ptrTwo++;
    }
  }

  // Reset pointer to correct initial address (after being incremented previously)
  // Otherwise pointer points to unallocated memory and "unknown" memory --> [2][0]...
  ptrOne = &matrixOne[0][0];
  ptrTwo = &matrixTwo[0][0];

  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      // Dereferencing
      *(ptrSum++) = *(ptrOne++) + *(ptrTwo++);
      }
    }

  // Reset pointer to correct initial address (after being incremented previously)
  // Otherwise pointer points to unallocated memory and "unknown" memory --> [2][0]...
  ptrSum = &sum[0][0];

  printf("The sum is:\n");
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      printf("%d ", *(ptrSum++));
      if (j == columns - 1) {
        printf("\n");
        }
      }
    }
  return 0;
}