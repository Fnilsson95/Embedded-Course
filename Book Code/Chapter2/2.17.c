#include <stdio.h>

// Write a program that prints the number 1 to 4 on the same line.
// Write the program using the following methods:
// a) Using one printf statement with no conversion specifiers
// b) Using one printf statement with four conversion specifiers
// c) Using four printf statements

int main() {

  // Declare and initialize variables
  int one = 1;
  int two = 2;
  int three = 3;
  int four = 4;

  // A)

  printf("Number 1, Number 2, Number 3, Number 4\n");
  printf("Number 1: %d - Number 2: %d - Number 3: %d - Number 4: %d\n", one, two, three, four);
  printf("Number 1: %d\n", one);
  printf("Number 2: %d\n", two);
  printf("Number 3: %d\n", three);
  printf("Number 4: %d\n", four);




  return 0;
}