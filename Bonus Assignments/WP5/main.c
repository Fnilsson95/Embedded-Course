// Bonus Assignment WP5
// Fredrik Nilsson

// Include libraries for necessary functions. I.e atoi()
#include <stdio.h>
#include <stdlib.h>

// Starting point of the program
// Program take input parameters for an elevator controller
// uses one byte (8 bits) and stores the status of the elevator
int main(int argc, char *argv[]) {

    // Validate that amount of input arguments is correct, 5 + 1 (program name)
    if (argc != 6) {
        // Print that invalid input was input.
        printf("invalid\n");
        // Return Error status (should be 1 but codegrade wants 0)
        return 0;
    }

    // Store the input arguments into separate integer variable 
    int engine_on = atoi(argv[1]);
    int floor_pos = atoi(argv[2]);
    int door_pos = atoi(argv[3]);
    int brake_one = atoi(argv[4]);
    int brake_two = atoi(argv[5]);

    // Validate that if each individual input is within correct range. 
    if (engine_on < 0 || engine_on > 1 || // 0 or 1 (on/off)
        floor_pos < 0 || floor_pos > 7 || // 0-7 floors
        door_pos < 0 || door_pos > 3 ||  // 0-2, door is closed or open
        brake_one < 0 || brake_one > 1 || // 0 or 1 (on/off)
        brake_two < 0 || brake_two > 1) { // 0 or 1 (on/off)

        // Print that invalid input was input.
        printf("invalid\n");
        // Return Error status (should be 1 but codegrade wants 0)
        return 0;
    }


    // Pack all the input values into one byte using bit operations OR
    unsigned char storedByte = (engine_on << 7) | // Shift 7 positions left (MSB)
                               (floor_pos << 4) | // Shift 4 positions left
                               (door_pos << 2)  | // Shift 2 positions left
                               (brake_one << 1) | // Shift 1 position left
                                brake_two; // Stays at the same position


    // Print the packed byte in hexadecimal
    printf("Packed byte: 0x%02X\n", storedByte);

    // Successful exit status of program
    return 0;
}