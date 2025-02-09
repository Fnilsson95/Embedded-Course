// (C) Fredrik Nilsson, Emma Olmås, Erik Lidbom
// Work package 2
// WP2 - Exercise 1 - Robot





/* Exercise Description:

Implement a control program for a robot. The program asks for the robot's starting position (x, y coordinates, ranging between 0-99)
and for a string of character 'm' and 't', where m stands for move one step in current direction and t for turn of directions as below

move (m): means that the robot takes one step in the current direction
turn (t): means that the robot turns 90 degrees clockwise

The start direction is always north for the robot

The program performs instructions from strings provided by the user, one by one. When all instruction have been executed the robot stops and the program
prints out the new position of the robot. The program then asks for new starting postion and the string of characters. The process repeats until 
program encounters a dedicated end of character (you can define it)

Implement the functions move() and turn() as two void functions and use a pointer parameter as argument so that the function
can update the robot position which is a varibable in the main function (calling function).


1. define coordinate ranges
2. define m and t variables
3. initialize robot (dir = N, xpos = user input, ypos = user input)
4. implement prototypes
5. implement while loop and end-of-character variable


Move():
1. Moves one step in the current direction
2. Check boundaries (0-99) to avoid going out of bounds
3. Uses Switch-case to determine movement logic

Turn():
1. Uses (robot->dir + 1) % to cycle through direction
 - N(0) -> O(1) -> S (2) -> W(3) -> Back to N(0)


Handling user input:
1. Reads starting position(x, y)
2. Reads command string (m for move, t for turn)
3. Repeats the process until end-of-turn character, i.e 'Q'

*/

#include <stdio.h>

// Define an enumeration named DIRECTION to represent the four directions.
enum DIRECTION {
    N, // North (0)
    O, // East (1)
    S, // South (2)
    W  // West (3)
}; 

// Define a new data structure named ROBOT using struct and typedef
typedef struct {
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

// Function prototype
// Moves the robot forward in current direction
 void move(ROBOT *robot);
 // Turns the robot 90 degrees clockwise
 void turn(ROBOT *robot);

#define MAX_POSITION 99
#define MIN_POSITION 0

// Starting point of program
int main () {


    ROBOT robot;
    // Array to store the input instructions
    char movingInstructions[100];
    // Initialize character to quit program
    char exit_char = 'q';



    while (1) {

        printf("Enter starting position (x and y): \n");
        scanf("%d %d", &robot.xpos, &robot.ypos);


        if (robot.xpos < MIN_POSITION || 
            robot.xpos > MAX_POSITION || 
            robot.ypos < MIN_POSITION || 
            robot.ypos > MAX_POSITION
            ) {
            printf("Invalid position! Please enter values between 0-99.\n");
            continue; // Continue will skip the rest of the iteration and restard the while loop
        } 

        robot.dir = N;


        printf("Enter command string (m = move, t = turn and q = quit: \n");
        scanf("%s", movingInstructions);

        if (movingInstructions[0] == exit_char) {
            printf("Exiting program.\n");
            break;
        }

        for (int i = 0; movingInstructions[i] != '\0'; i++) {
            if(movingInstructions[i] == 'm') {
                move(&robot);
            } else if (movingInstructions[i] == 't') {
                turn(&robot);
            }
        }

        printf("Final Position: (%d, %d)\n", robot.xpos, robot.ypos);
        char *dir_names[] = {"North", "East", "South", "West"};
        printf("Final Direction: %s\n", dir_names[robot.dir]);
    }


    // Successful exit status of program
    return 0;
}


// Function to move the robot
void move(ROBOT *robot) {

    switch (robot->dir) {
        // Move north, up
        case N: 
            if (robot->ypos < MAX_POSITION) {
                robot->ypos++;
            }
            break;
        
        // Move east, right
        case O:
            if (robot->xpos < MAX_POSITION) {
                robot->ypos++;
            }
            break;

        // Move south, down
        case S: 
            if (robot->ypos > MIN_POSITION) {
                robot->ypos--;
            }
            break;

        // Move west, left
        case W: 
            if (robot->xpos > MIN_POSITION) {
                robot->xpos--;
            }
            break;
    }
}
// Function to turn the robot
void turn(ROBOT *robot) {

    // Goes through the directions.
    // N -> O -> S -> W -> N...
    robot->dir = (robot->dir + 1) % 4;
}



/* Comments for myself:

1. Why use Pointer (ROBOT *robot)?
  - Passing a pointer (ROBOT *robot) allows for direct modification of robot in main(), without returning anything
    Then you can use robot->xpos and modify xpos directly inside main()

2. Declaring ROBOT robot alone does not initialize values like enums
    - Uninitialized struct members contain garbage values  
    - Need to initialize like {robot.xpos = 0, robot.ypos = 0, robot.dir = N}; or robot.dir = N;

*/