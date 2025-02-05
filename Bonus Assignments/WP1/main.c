// Created by Fredrik Nilsson on 2025-01-28.
// Bonus Assignment WP1

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Program that counts the number of 0s and 1s in
// a binary represenetation of a decimal number
// Main function, entry point of the system
int main (int argc, char *argv[]) {

  // Validation for the amount of arguments passed via command line
  if (argc != 2) {
    printf("Error: No number provided. Please provide a number as a command line argument.\n");
    return 0;
  }

  // Convert the string input to unsigned long with base 10
  // end is a pointer to a char that will store where the conversion stopped
  char *end;
  unsigned long number = strtoul(argv[1], &end, 10);

  // Validation for the correct input
  // end == argv[1] --> no successful convertion from string to unsigned long
  // != '0' --> only partial convertion (I.e input of "9983a")
  if (*end != '\0' || end == argv[1]) {
    printf("Error: Invalid number.\n");
    return 0;
    }

  // Validation of the input size.
  // Can't be greater than max value of an unsigned long
  if (number > (unsigned long)LONG_MAX) {
      printf("Error: Number input is greater than LONG MAX.\n");
      return 1;
    }


  printf("Number: %ld\n", number);

  // Initialize variable for bit counting
  int bits_needed = 0;

  // Calculate the minimum amount of bits required
  if (number == 0) {
    bits_needed = 8;
  } else {
    unsigned long temp = number;
    while (temp > 0) {
      temp >>= 1;    // Shift right by 1 to count bits
      bits_needed++;
    }

    // Asserting the amount of bits to the bits_needed variable
    // Rounding up to the next amount of bits if exceeding smaller bit value
    if (bits_needed <= 8) {
      bits_needed = 8;
    } else if (bits_needed <= 16) {
      bits_needed = 16;
    } else if (bits_needed <= 32) {
      bits_needed = 32;
    } else {
      bits_needed = 64;
    }
  }


  // Declaring and initializing counter variables
  int ones = 0;
  int zeros = 0;
  int found_first_one = 0;

  // Print the binary prefix
  printf("Binary: 0b");

  // Loop over each bit from (bits_needed - 1) down to 0
  // Starting from highest bit to lowest
  for (int i = bits_needed - 1; i >= 0; i--) {
    // Shift number to the right by i bits.
    int bit = (number >> i) & 1;

    // If the bit is 1, we've encountered our first '1'
    if (bit == 1) {
      found_first_one = 1;
      ones++;
    }

    // Only start counting if we have found the first one.
    if (found_first_one) {
      // Ternary statement for deciding which number
      putchar(bit ? '1' : '0');
    } else if (i == 0) {
      // If we never found a 1 and are at the last bit (i==0),
      // the number must be 0, so we print one '0'.
      putchar('0');
    }

    // Only count zeros if we have found a one.
    if (bit == 0 && found_first_one) {
      zeros++;
    }
  }
  // Done printing the binary representation
  printf("\n");

  // Print the count of zeros and ones
  printf("Number of 0s: %d\n", zeros);
  printf("Number of 1s: %d\n", ones);

  return 0;
  }