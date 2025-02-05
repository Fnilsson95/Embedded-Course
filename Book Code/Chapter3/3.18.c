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


int main () {


int accountNumber = 0;
double beginningBalance = 0;
double totalCharges = 0;
double credits = 0;
double creditLimit = 0;


    while (accountNumber != -1) {

      printf("Enter account number (-1 to end): \n");
      scanf("%d", &accountNumber);

      if (accountNumber == -1) {
        break;
      }

      printf("Enter the beginning balance: \n");
      scanf("%lf", &beginningBalance);

      printf("Enter the total charges: \n");
      scanf("%lf", &totalCharges);

      printf("Enter the total credits: \n");
      scanf("%lf", &credits);

      printf("Enter credit limit: \n");
      scanf("%lf", &creditLimit);

      printf("Account:\t%d\n", accountNumber);
      printf("Credit Limit: %.2lf\n", creditLimit);

      double balance = beginningBalance + totalCharges - credits;

      printf("Balance:\t%.2lf\n", balance);

      if (balance > creditLimit) {
        printf("Credit Limit Exceeded.\n");
      }
    }
  return 0;
}