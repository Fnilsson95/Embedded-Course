// (C) Emma Olmås, Fredrik Nilsson, Erik Lidbom, group: 34 (2025)
// Work package 3
// Exercise 5 - Pointers and Arrays
// Submission code: 

// Include libraries for functions printf(), srand(), rand(), sizeof()
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define macro for max value of array elements
#define MAX 10

// Starting point of the program
// Program creates an array with random integer numbers between 1-99, and prints different information about it
int main () {

    // Initialize array of integers with MAX elements
    int array[MAX];

    // Initialize a pointer to the first element of the array
    int *arrayPtr = array;

    // Seed the random number generator
    srand(time(0));

    // Add random numbers between 1-99 to all the elements on the array
    for (int i = 0; i < MAX; i++) {

        array[i] = rand() % 99 + 1;
    }



    // Print the whole array to verify the print statements below:
    for (int i = 0; i < MAX; i++) {
        printf("The integers of the array are the following: %d\n", array[i]);
    }


    // Print the address of the array
    printf("The address of the array (via pointer) is: %p\n", arrayPtr);
    printf("The address of the array is: %p\n", array);
    // Print first integer in the array
    printf("The first integer in the array is: %d\n", *arrayPtr);
    // Print the last integer in the array
    printf("The last integer in the array is: %d\n", *(arrayPtr + MAX - 1));
    // Print the size on an integer (in bytes)
    printf("The size of an integer (in bytes) is: %lu\n", sizeof(int));
    // Print the size of the whole array (in bytes)
    printf("The size of the whole array (in bytes) is: %lu\n", sizeof(array));


    // Print value of each element, and then the doubled value
    for (int i = 0; i < MAX; i++) {
        
        printf("Each integer value: %d - Each integer value doubled: %d\n", *(arrayPtr + i), *(arrayPtr + i) * 2);
    }

    // Successful exit status of program
    return 0;
}