// (C) Fredrik Nilsson, Emma Olmås, Erik Lidbom
// Work package 2
// WP2 - Exercise 4 - Bitpacking
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Starting point of the program
// The program takes the packed byte from code.c, and unpacks it into 5 separate fields.
int main(int argc, char *argv[]) {

  	// Validate that we get correct amount of input
    if (argc != 2) {
      	printf("Wrong amount of arguments input\n");
        return 1; // Exit with error
    }

   // The input argument containing the hexadecimal string, I.e. "AB"
    char *hexString = argv[1];

    // Input must be 2 hexadecimal characters
    if (strlen(hexString) != 2) {
        printf("Error: You must provide exactly 2 hexadecimal characters.\n");
        return 1; // Exit with error
    }

    // Convert each hex digit manually.
    // high and low variables to store the digits
    int high = 0;
    int low = 0;

    // Convert the first character (high)
    char c = hexString[0];
    if (c >= '0' && c <= '9') {
        high = c - '0';
    } else if (c >= 'A' && c <= 'F') {
        high = c - 'A' + 10;   // 'A' -> 10 -- 'F' -> 15
    } else if (c >= 'a' && c <= 'f') {
        high = c - 'a' + 10;   // 'a' -> 10 -- 'f' -> 15
    } else {
        printf("Error: Invalid hex digit '%c'\n", c);
        return 1;
    }

    // Convert the second character (low)
    c = hexString[1];
    if (c >= '0' && c <= '9') {
        low = c - '0';
    } else if (c >= 'A' && c <= 'F') {
        low = c - 'A' + 10;
    } else if (c >= 'a' && c <= 'f') {
        low = c - 'a' + 10;
    } else {
        printf("Error: Invalid hex digit '%c'\n", c);
        return 1;
    }

    // Combine them into one byte
    // The high is shifted left by 4 bits, then OR-operator with the low
    // 8-bit is 1 byte, and each character in hexadecimal represents 4 bits.
    // Put one in the upper 4 bits, and the other in the lower 4 bits.
    // I.e 1010 0000
    //     0000 1011
    //         |
    //     1010 1011
    unsigned char packedByte = (unsigned char)((high << 4) | low);


    // Unpack the byte using bitwise operation >>, shifting to the right.
    // and compare with the binary number representing amount of bits needed.
    // I.e for gear_pos we use 0x07 (00000111 in binary) and & to see which output.
    // 0x01 --> 00000001
    // 0x03 --> 00000011
    // 0x07 --> 00000111
    int engine_on = (packedByte >> 7) & 0x01;
    int gear_pos = (packedByte >> 4) & 0x07;
    int key_pos = (packedByte >> 2) & 0x03;
    int brake1 = (packedByte >> 1) & 0x01;
    int brake2 = packedByte & 0x01;

    // Print extracted values
    printf("Name       Value\n");
    printf("-------------------\n");
    printf("engine_on   %d\n", engine_on);
    printf("gear_pos    %d\n", gear_pos);
    printf("key_pos     %d\n", key_pos);
    printf("brake1      %d\n", brake1);
    printf("brake2      %d\n", brake2);

    // Successful exit status
    return 0;
}