//
// Created by Fredrik Nilsson on 2025-02-05.
//


/* Exercise Description:
Develop a c program that will determine if a department store customer has exceeded the credit limit on a charge account.
For each customer, the following facts are available:
a) Account number
b) Balance at the beginning of the month
c) Total of all items charged by this customer this month
d) Total of all credits applied to this customer's account this month
e) Allowed credit limit

The program should input each of these facts, calculate the new balance (= beginning balance + charges - credits),
determine if the new balance exceeds the customer's credit limit.
For those customers whose credit limit is exceeded, the program should display the customer's account number, credit limit,
new balance and message "Credit limit exceeded."
 */

#include <stdio.h>

// Define constants
#define MIN_ACCOUNT 1
#define MAX_ACCOUNT 100
#define MINIMUM 0
#define MAX_CHARGES 5000
#define MAX_LIMIT 10000
#define MAX_START_BALANCE 100000

// Starting point of the program
// Program works as a simple "banking" system,
// controlling if the user has exceeded their credit limit or not
int main () {

// Initialize variables
int accountNumber = 0;
double beginningBalance = 0;
double totalCharges = 0;
double credits = 0;
double creditLimit = 0;


    // While-loop to run until user inputs -1 to end
    while (accountNumber != -1) {


      printf("Enter account number (-1 to end): \n");
      scanf("%d", &accountNumber);

      // If user enters -1, break
      if (accountNumber == -1) {
        break;
      }

      // Validation for accountNumber being within valid range
      if (accountNumber < MIN_ACCOUNT || accountNumber > MAX_ACCOUNT) {
        printf("Invalid input. Please provide an integer between 1 and 100\n");
        continue; // Restart while-loop
      }


      printf("Enter the beginning balance: \n");
      // Validate that input is correct type and within correct ranges
      if (scanf("%lf", &beginningBalance) != 1 || beginningBalance < MINIMUM || beginningBalance > MAX_START_BALANCE) {
        printf("Invalid input. please provide an integer between %d and %d\n", MINIMUM, MAX_START_BALANCE);
        continue; // Restart while-loop
      }

      printf("Enter the total charges: \n");
      // Validate that input is correct type and within correct ranges
      if (scanf("%lf", &totalCharges) != 1 || totalCharges < MINIMUM || totalCharges > MAX_CHARGES) {
        printf("Invalid charge amount. Values are at most between %d and %d\n", MINIMUM, MAX_CHARGES);
        continue; // Restart while-loop
      }


      printf("Enter the total credits: \n");
      // Validate that input is correct type and within correct ranges
      if (scanf("%lf", &credits) != 1 || credits < MINIMUM) {
        printf("Invalid input. Must be minimum %d\n", MINIMUM);
        continue; // Restart while-loop
      }

      printf("Enter credit limit: \n");
      // Validate that input is correct type and within correct ranges
      if (scanf("%lf", &creditLimit) != 1 || creditLimit < MINIMUM || creditLimit > MAX_LIMIT) {
        printf("Invalit limit amount. Please provide input between %d and %d", MINIMUM, MAX_LIMIT);
        continue; // Restart while-loop
      }

      // Calculate balance from user input
      double balance = beginningBalance + totalCharges - credits;

      // Print user submission
      printf("Account:\t%d\n", accountNumber);
      printf("Credit Limit: %.2lf\n", creditLimit);
      printf("Balance:\t%.2lf\n", balance);

      // If balance is exceeding creditLimit
      if (balance > creditLimit) {
        printf("Credit Limit Exceeded.\n");
      }
    }
  // Successful exit status of program
  return 0;
}