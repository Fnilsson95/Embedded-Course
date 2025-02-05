//
// Created by Fredrik Nilsson on 2025-02-05.
//


/* Exercise Description:
Write a program that prints 100 asterisks, one at a time. After every 10th asterisk, your program should print a newline character.
 */

#include <stdio.h>


// Starting point of program
// Program writes 100 asterix in a row, but every 10th asterix also prints a new line character.
int main () {

  int count = 0;

  for (int i = 0; i < 100; i++) {

    printf("*");
    count++;
    if (count % 10 == 0) {
      printf("\n");
      }
    } // End of for-loop
  // Successful exit status of program
  return 0;
}