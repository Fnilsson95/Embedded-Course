//
// Created by Fredrik Nilsson on 2025-02-05.
//
/*

Develop a program that will input the miles driven and gallons used for each tankful
The program should calculate and display the miles per gallon obtained for each tankful.
After processing all input information, the program should calculate and print the combined miles per gallon obtained
for all tankfuls.
 */

#include <stdio.h>

int main () {

  // Declare and initialize variables
  double gallons = 0;
  int miles = 0;
  double milesPerGallonTotal = 0;
  double milesPerGallonPerTank;
  int fullTanks = 0;

  // While loop that breaks if input is -1
  while (gallons != -1) {

    // Prompt user for gallons input
    printf("Enter the gallons used (-1 to end): \n");
    scanf("%lf", &gallons);

    // Check if break-condition if met
    if (gallons == -1) {
        break;
    }

    // Prompt the user for miles input
    printf("Enter the miles driven: \n");
    scanf("%d", &miles);

    // Avoid division by zero
    if (gallons != 0.0) {
        milesPerGallonPerTank = miles/gallons;
        printf("The miles / gallon for this tank was: %lf\n", milesPerGallonPerTank);

        milesPerGallonTotal += milesPerGallonPerTank;
        fullTanks++;
    } else {
        printf("Gallons can't be zero. Please enter a valid number.\n");
    }
  }

    // Avoid division by zero (No tanks used)
    if (fullTanks > 0) {
        printf("The overall average miles/gallon was: %lf\n", (milesPerGallonTotal/fullTanks));
    } else {
        printf("No valid data entered.\n");
    }

  // Successful exit status of program
  return 0;
}
