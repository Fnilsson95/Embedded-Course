#include <stdio.h> 
#include <ctype.h>

#define MAX_COORDINATES 99
#define MIN_COORDINATES 0


// Instructions from user, provided as a string, read one by one --> array of chars
// When all instructions are done, it prints out the position of the robot. 
// Then asks for a new starting position and the string of characters
// Program repeats until encounting a end character --> While loop 

// Define enumerations of directions in a clockwise rotation. 
enum DIRECTION {
    N, // North - 0
    O, // East - 1
    S, // South - 2
    W // West - 3
};

// Define the typedef struct of ROBOT
typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT; 

// Function prototypes
void move(ROBOT *robot);
void turn(ROBOT *robot);

int main () {

    // Declare a variable named "robot" of type ROBOT
    ROBOT robot;

    // Initialize directionNames array to translate enum values into actual strings.
    const char *directionNames[] = {"North", "East", "South", "West"};

    // Set the initial starting direction of the robot
    robot.dir = N;

    // Initialize where we store the character values, string
    // Initialize a end of character char
    // Initialize a while loop.

    // Initialize with pointer and malloc after
    char inputInstructions[100];
    char playCharacter = 'p';


    while (playCharacter != 'q') {

        // Prompt user for input coordinates
        printf("Enter the starting position of the robot (Positions for x and y 0-99)\n");
        scanf("%d %d", &robot.xpos, &robot.ypos);
    
        // Validate input coordinates to be within correct range. 
        if (robot.xpos > MAX_COORDINATES || robot.xpos < MIN_COORDINATES || robot.ypos > MAX_COORDINATES || robot.ypos < MIN_COORDINATES) {
            printf("Error, coordinates out of bounds. Please input between 0-99\n");
            continue;
        }

        printf("Enter the move instructions for robot (m = move, t = turn and q = quit)\n");
        scanf("%s", inputInstructions);

        // Validate that only characters have been input
        // isalpha
        int valid = 1;
        for (int i = 0; inputInstructions[i] != '\0'; i++) {
            if(!isalpha(inputInstructions[i])) {
                valid = 0;
                break;
            }
        }

        if(!valid) {
            printf("Error. Only input letters. (m, t or q)\n");
            continue;
        }
    
        // Check if the instruction is to quit playing
        if (inputInstructions[0] == 'q') {
            playCharacter = 'q';
            printf("Exiting game\n");
            break;
        }

        // Since all character input ends with a null terminator '\0',
        // We can run the for-loop until inputInstructions is not equal to '\0'.
        // If we hit a null terminator, we know the string instructions is empty and no more letter to check.
        // We can also validate for letters that are not equal to t or m, but easier to do it inside for-loop. 
        for (int i = 0; inputInstructions[i] != '\0'; i++) {
            if (inputInstructions[i] == 't') {
                turn(&robot);
            } else if (inputInstructions[i] == 'm') {
                move(&robot);
            }
        }

     
        printf("The final position of the robot is x position: %d, and y position: %d\n", robot.xpos, robot.ypos);
        printf("The final direction of the robot is: %s\n", directionNames[robot.dir]);

    }

    return 0;
}

// Robot takes one step in the current direction
void move(ROBOT *robot) {
// Access the robots positions x position and y position. 
// We need to validate that they are within range. If they are, we do xpos++, xpos--, ypos++ or ypos--
// Means that if we face north, and get 2x 'm' --> ypos++ and ypos ++. 
// If we face O, east, and get 2x 'm' --> xpos++ and xpos++''
// If we face S, south, and get 2x 'm' --> ypos-- and ypos--
// If we face W, west, and get 2x 'm' --> xpos-- and xpos--

switch(robot->dir) {

    case N:
        if (robot->ypos < MAX_COORDINATES) {
        robot->ypos++;
        }
        break;

    case O:
        if (robot->xpos < MAX_COORDINATES) {
            robot->xpos++;
        }
        break;

    case S:
        if(robot->ypos > MIN_COORDINATES) {
            robot->ypos--;
        }
        break;

    case W:
        if (robot->xpos > MIN_COORDINATES) {
            robot->xpos--;
        }
        break;
    }
    
}

// Robot turns 90 degrees clockwise
void turn(ROBOT *robot) {
// It starts as N, and then turns clockwise one step per 't' character
// So we need to access the robots dir, then do (dir + 1) % 4, to get the new direction.
robot->dir = (robot->dir + 1) % 4;
}