#include <stdio.h>


/* Exercise Description:

Write a program that prints the following patterns separately, one below the other. 
All asterix (*) should be printed by a single printf statement form printf("*")
*/



int main () {

    int i, j;

// A)

    // Outer loop for rows
    for (i = 1; i <= 10; i++) {
        // Inner loop for printing asterix
        for(j = 1; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }



// B) 

    printf("\n");

    for (i = 10; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}