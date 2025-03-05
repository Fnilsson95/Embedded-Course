// Include required libraries (I.e stdlib for atoi() functio)
#include <stdio.h>
#include <stdlib.h>

// Define type Node which represents a single element (node) in a linked list
typedef struct Node {
    // Integer value
    int value;
    // Pointer of type Node, that points to the next node in the list
    struct Node *next;
} Node;

// Define type LinkedList which represents a linked list structure
typedef struct LinkedList {
    // Pointer to the first node (head) of the linked list
    Node *head;
} LinkedList;

// Define prototype of function to append nodes in linked list
void appendNode (LinkedList *list, int value);
void getFibonacciValue (LinkedList *list, int value);
void printList (LinkedList *list);
void freeList (LinkedList *list);

// Starting point of the program
// Program calculates and stores Fibonacci sequences of the input argument from user
int main (int argc, char *argv[]) {

    // Validate the amount of input arguments (Only 2 accepted)
    if (argc != 2) {
        // Print error message
        printf("Wrong amount of arguments\n");
        // Exit status of failure
        return 1;
    }

    // Convert command line argument to an integer
    int inputValue = atoi(argv[1]);

    // Initialize a linked list and set head initial head to NULL
    LinkedList list;
    list.head = NULL; 

    // Print stored value
    printf("Stored value in linked list: %d\n", inputValue);

    // Invoke function to get all fibonacci values
    getFibonacciValue(&list, inputValue);

    // Invoke function to print linked lsit with all values
    printList(&list);

    // Invoke function to free allocated memory of the linked list
    freeList(&list);

    // Successful exit status of program
    return 0;

} // End of main scope

// Function to append the next node in the linked list
void appendNode (LinkedList *list, int value) {

    // Allocate dynamic memory for new node
    Node *newNode = malloc(sizeof(*newNode));

    // Validate that memory allocation is valid
    if (newNode == NULL) {
        printf("Error: Could not allocate memory.\n");
        return;
    }

    // Assign value for new node
    newNode->value = value;
    newNode->next = NULL;

    // If the list is empty, new node becomes the first node (head)
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        // Traverse to the end and link the new node
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        // Set the next node to the new node
        current->next = newNode;
    }
} // End of Append function

// Function to generate Fibonacci value from input value
void getFibonacciValue (LinkedList *list, int value) {

    // Add the first fibonacci number, 0
    appendNode(list, 0);
    // If value is greater than 0, append second fibonacci number, 1
    if (value > 0) {
        appendNode(list, 1);
    }

    // Initialize pointers to track previous two numbers
    Node *prev = list->head;         // Points to (n-2)
    Node *current = prev->next;      // Points to (n-1)

    // Generate Fibonacci numbers and store them in the linked list
    for (int i = 2; i <= value; i++) {
        // Initialize variable to store the sum of previous two values
        int nextFib = prev->value + current->value;
        // Append the calculated number to the linked list
        appendNode(list, nextFib);

        // Increment pointers one step to next node
        prev = current;
        current = current->next;
    }
} // End of getFibonacciValue function

// Function to print the linked list
void printList (LinkedList *list) {

    // Print initial setup message
    printf("The Fibonacci Sequence: ");

    // Initialize a pointer of type node to the current value (initially set to head)
    Node *current = list->head;
    // While-loop to print all values while current is not equal to NULL (list empty)
    while (current != NULL) {
        // Print current value
        printf("%d ", current->value);
        // Set value of current to the value of the next node
        current = current->next;
    }
    // Print new line character after all values
    printf("\n");
} // End of printList function

// Function to free memory allocated for the linkedlist
void freeList (LinkedList *list) {

    // Initialize a pointer of type node to the current value (initially set to the head)
    Node *current = list->head;
    
    // While-loop that runs while current value is not equal to NULL (list empty)
    while (current != NULL) {
        // Initialize temporary variable to store current node
        Node *temp = current;
        // Increment to next node before freeing current node
        current = current->next;
        // Free temporary variable storing current node
        free(temp);
    }
} // End of freeList function