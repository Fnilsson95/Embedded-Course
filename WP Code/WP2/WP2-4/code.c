// (C) Fredrik Nilsson, Emma Olmås, Erik Lidbom
// Work package 2
// WP2 - Exercise 4 - Bitpacking

#include <stdio.h>
#include <stdlib.h>

// Starting point of the program
// Program takes 5 integer values as an argument, and packs them into a single byte.
int main (int argc, char *argv[]) {

	// Validation of amount of input arguments (has to be 5 + program name)
	if (argc != 6) {
		printf("Error, invalid amount of arguments. Provide 5 arguments.\n");
		// Exit status with error
		return 1;
	}

	// Convert input arguments from string to integers
    int engine_on = atoi(argv[1]);
    int gear_pos = atoi(argv[2]);
    int key_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]);

	// Validate correct ranges of the input
    if (engine_on < 0 || engine_on > 1 || // 0 or 1 (on/off)
        gear_pos < 0 || gear_pos > 4 || // 0 to 4
        key_pos < 0 || key_pos > 2 || // 0 to 2
        brake1 < 0 || brake1 > 1 || // 0 or 1 (on/off)
        brake2 < 0 || brake2 > 1) { // 0 or 1 (on/off)
      printf("Error, invalid input values.\n");
	  // Exit status with error
      return 1;
    }

    // Pack all the integer values into a single byte, packedByte
    // We are shifting the bit values depending on the variable and position
    // I.e engine_on is shifted 7 positions to the left and goes to bit 7
    // Using bitwise OR, which compares the total value with next value.
    unsigned char packedByte = (engine_on << 7)
                               | (gear_pos << 4)
                               | (key_pos << 2)
                               | (brake1 << 1)
                               | brake2;


    // Print the byte in hexadecimal in uppercase (%X)
    printf("Packed Byte: %02X\n", packedByte);

  return 0;
}