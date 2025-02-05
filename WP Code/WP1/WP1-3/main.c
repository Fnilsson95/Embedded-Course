// (C) Fredrik Nilsson, Emma Olmås, Erik Lidbom
// Work package 1
// WP1 - Exercise 3 - Guess the number game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER_OF_GUESSES 10 // The amount of guesses per round
#define UPPER_BOUND 100
#define LOWER_BOUND 1


/* This function provides a random number. */
int generateRandomNumber(){
    srand(time(NULL)); //Sets the seed with the current time to ensure that the generated numbers is not deterministic
    int random_number = (rand() % UPPER_BOUND) + 1; // Generates the random number
    return random_number;
}


int main(void){
    
    int game_running = 1; // Sets the variable to a truthy value to run the game

    while(game_running == 1){ // While loop that runs as long as game_running is a truthy value
        int correct_answer = generateRandomNumber(); // Generate a random number for the current round
        int guess_count = 0; // Initialize the guess count and set it to 0

        for(int i = 0; i < MAX_NUMBER_OF_GUESSES; i++){ //For loop that runs MAX_GUESSES times to allow the user to make right amount of guesses
            int guess; //Initialize guess
            printf("%d. Enter a number between 1 and 100:\n", i + 1); //Prints current guess prompt
            int validInput = scanf("%d", &guess); // Retrieves the guess from the user and also stores the result status from scanf into a variable
           
            if(guess < LOWER_BOUND || guess > UPPER_BOUND || !validInput){ //Checks if guess is out of range or if it was an invalid input
                i--; // Decrement counter
                while (getchar() != '\n'); //Clears the buffer
                printf("Invalid input!\n"); // Falsy input prompt
                continue; //Continues to the next iteration
            }
           
            guess_count++; // Increases the guess count

            if(guess == correct_answer){ //Check if the guess was correct
                printf("\nYou have guessed %d times and your guess is correct!\n", guess_count); // Correct guess prompt
                guess_count = 0; //Sets the guess count back to 0
                break; //Breaks the for loop to continue with the rest of the while loop
            } else if(guess < correct_answer){
                puts("Your guess is too low. Guess again");
            } else{
                puts("Your guess is too high. Guess again");            
            }

        }

        if(guess_count == MAX_NUMBER_OF_GUESSES){ //Checks if the amount of guesses is equal to maximum guesses
            puts("\nYou have exceeded the maximum number of guesses"); // Out of guesses prompt
        }
        
        printf("Do you want to play again or quit?\nType 1 to play again\nType 0 to quit\n"); //Play again prompt
        int play_again = 0; // Initialize variable to check if the user wants to play again
        while(play_again != 0 && play_again != 1){ // While loop to ensure that the program doesnt start a new round when providing falsy input
            int userInput = scanf("%d", &play_again); //Retrieve user input and store the validity result into a variable
            if(!userInput || (play_again != 0 && play_again != 1)){ // Checks if the input is within range and if is correct type
                while (getchar() != '\n'); // If non-valid input it clears the buffer
                printf("Invalid input! Please enter 1 to play again or 0 to quit.\n"); // Falsy input prompt
            }
        }

        game_running = play_again; //Sets game variable to either true or false
    }
    return 0;
}
