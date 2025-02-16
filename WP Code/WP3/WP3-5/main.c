// Exercise 5 (6)

/* Exercise TODO List

1. Create an integer array with MAX elements
2. Fill the array with random numbers (1-99)
3. Print information about the array:
    - The memory address of the array (pointer)
    - The first and last elements of the array (pointer) 
    - The size of an integer in bytes (sizeof)
    - The size of the whole array in bytes (sizeof)
4. Use a pointer to print each value in the array (pointer++)
5. Use the pointer to print each value multiplied by 2 (pointer++ * 2?)
*/

/* 

1. Define MAX elements
2. for-loop and use srand rand % 99 + 1 to get numbers between 1-99

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10



int main () {

int array[MAX];

int *ptr = array;

srand(time(0));


for (int i = 0; i < MAX; i++) {
    array[i] = rand() % 99 + 1;
}

for (int i = 0; i < MAX; i++) {
    printf("The numbers of the array are: %d\n", array[i]);
}

printf("The memory address of the array: %p\n", &ptr);
printf("The FIRST element of the array: %d\n", *ptr);
printf("The LAST element of the array: %d\n", *(ptr + MAX - 1));
printf("The size of an integer in bytes: %lu\n", sizeof(int));
printf("The size of the whole array in bytes: %lu\n", sizeof(array));


for (int i = 0; i < MAX; i++) {
    printf("The numbers of the array are: %d\n", *(ptr + i));
}

// 5. Use the pointer to print each value multiplied by 2 (pointer++ * 2?)

for (int i = 0; i < MAX; i++) {

    printf("The numbers of the array are this when DOUBLED: %d\n", *(ptr + i) * 2);
}


    return 0;
}


/* Comments for myself:
Printing a memory address:
%d is used for printing integers (int), but &ptd is a pointer to pointer (int** (pointing to an array))
%d expects a normal integer, but we are giving it a memory address in this case
Use %p for printing pointers (memory addresses)

Printing sizeof:

%d expects a signed integer (int), but sizeof(int) returns size_t, which is an unsigned long. 
Depending on the system, but using %d can cause a mismatch
Therefore we should use %lu for (unsigned long)

*/