// Fredrik Nilsson (29/1-25 -- 30/1/25)
// Bonus Assignment WP2

#include <stdio.h>
#include <unistd.h>

// Declare Enums for days
enum days {
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

// Declare Enums for weeks
enum weeks {
    WEEK_ONE, WEEK_TWO, WEEK_THREE, WEEK_FOUR, WEEK_FIVE
};

// Helper function to print a day based on enum
void printDay(enum days day) {
    switch (day) {

        case MONDAY:
          printf("Monday");
          break;

        case TUESDAY:
          printf("Tuesday");
          break;

        case WEDNESDAY:
          printf("Wednesday");
          break;

        case THURSDAY:
          printf("Thursday");
          break;

        case FRIDAY:
          printf("Friday");
          break;

        case SATURDAY:
          printf("Saturday");
          break;

        case SUNDAY:
          printf("Sunday");
          break;

        default:
          printf("Uknown day!");
          break;
    }
}
// Helper function to print a week based on enum
void printWeek(enum weeks week) {
    switch (week) {

        case WEEK_ONE:
          printf("Week 1");
          break;

        case WEEK_TWO:
          printf("Week 2");
          break;

        case WEEK_THREE:
          printf("Week 3");
          break;

        case WEEK_FOUR:
          printf("Week 4");
          break;

        case WEEK_FIVE:
          printf("Week 5");
          break;

        default:
          printf("Unknown week!");
          break;
    }
}

// Calender program using enums to simulate a weekly calender based on input
// Starting point of the program
int main(void) {

    // Declaring variable to store user input
    int weekInput;
    int dayInput;

    // Declaring variables of type enum days and enum weeks
    enum days currentDay;
    enum weeks currentWeek;

    // Prompt the user for a starting week
    printf("Provide starting week (Between 1-5): ");
    // Validation of the input, must be correct input type
    if (scanf("%d", &weekInput) != 1) {
        printf("invalid week\n");
        return 0;
    }
    // Remove any possible trailing characters in buffer
    while (getchar() != '\n');

    // Valitation of the weekly input, must be between 1-5
    if (weekInput < 1 || weekInput > 5) {
        printf("invalid week\n");
        return 0;
    }

    // Initialize variable with the users input
    currentWeek = (enum weeks)(weekInput - 1);

    // Prompt user to input starting day
    printf("Provide starting day (Between 1-7): ");
    // Validation of the day input, must be correct input type
    if (scanf("%d", &dayInput) != 1) {
        printf("invalid day\n");
        return 0;
    }

    // Remove any possible trailing characters in buffer
    while (getchar() != '\n') {

    // Valitation of the day input, must be between 1-7
    if (dayInput < 1 || dayInput > 7) {
        printf("invalid day\n");
        return 0;
    }
    // Initialize variable with the users input
    currentDay = (enum days)(dayInput - 1);

    // While loop to print the weekly calender, incrementing the days and week
    // depending on the starting week and day
    while (1) {

        // Invoke helper functions and additional printf statements
        printWeek(currentWeek);
        printf(", ");
        printDay(currentDay);
        printf("\n");

        // Increment the current day
        currentDay = (enum days)(currentDay + 1);

        // If-statement to check if we go around sunday and start a new week
        if (currentDay > SUNDAY) {
            currentDay = MONDAY;
            currentWeek = (enum weeks)(currentWeek + 1);

            // Validation if we go beyond week five.
            if (currentWeek > WEEK_FIVE) {
                break;
            }
        }
        // Pauses one second before continuing running
        sleep(1);
    }
    // Successful exit status of the program
    return 0;
    }
}