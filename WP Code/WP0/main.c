// (C) Fredrik Nilsson, Emma Olmås, Erik Lidbom, group: 34 (2025)
// Work package 0
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)
#include <stdio.h>
#include <string.h>




// int argc - The number of commandline arguments
// char *argv - An array of strings representing the arguments
int main(int argc, char *argv[]) {

    // If-statement to check amount of arguments
    // If less or more than 2, returns error and additional -h parameter information
    if (argc != 2) {
        printf("Error: Invalid number of arguments found.\n");
        printf("Use the -h parameter for information regarding program usage.\n");
        return -1;
    }

    // If-statement with -h (help) parameter
    // Check if the first argument is "-h"
    if (strcmp(argv[1], "-h") == 0) {
        printf("Usage: %s <your_name>\n", argv[0]);
        printf("Description: This program prints a personalized greeting.\n");
        printf("Example: %s John\n", argv[0]);
        return 0;
    }

    // Print the personalized Hello World greeting
    // Print the argument with index 1 (second argument)
    // First argument will be program name, second argument will be the name argument
    // For example argv[0] = exercise2 and argv[1] = name argument
    printf("Hello World! – I’m %s!\n", argv[1]);
    return 0;
}