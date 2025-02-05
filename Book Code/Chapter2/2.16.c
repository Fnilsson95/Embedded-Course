#include <stdio.h>
// Write a program that asks the user to enter two numbers,
// obtain the two numbers from the user and prints the sum, product, difference and remainder of the two numbers
int main () {


  int numberOne; // Declare first number to store user input
  int numberTwo; // Declare second number to store user input

  // Prompt and read user input for first number
  scanf("%d", &numberOne);
  printf("The first number is: %d\n", numberOne);

  // Prompt and read user input for second number
  scanf("%d", &numberTwo);
  printf("The Second number is: %d\n", numberTwo);

  printf("The sum of the two numbers are: %d\n\n", numberOne + numberTwo); // Print the sum
  printf("The product of the two numbers are: %d\n\n", numberOne * numberTwo); // Print the product
  printf("The difference of the two numbers are: %d\n\n", numberOne - numberTwo); // Print the difference
  printf("The remainder of the two numbers are: %d\n", numberOne % numberTwo); // Print the remainder

  return 0;
}












