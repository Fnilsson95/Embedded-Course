#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
EXERCISE 2: LINKED LIST

1. Implement the function:
   REGTYPE* random_list(void);
   - Creates a doubly linked list with MAX (5) nodes.
   - Each node's 'number' field should be assigned a random value between 0 and 100.
   - Returns a pointer to the head of the list.

2. Implement the function:
   REGTYPE* add_first(REGTYPE* temp, int data);
   - Inserts a new node at the start of the linked list.
   - Assigns 'number' field with the given 'data' value.
   - Updates 'prev' and 'next' pointers properly.
   - Returns the new head of the list.

3. Modify 'main()' to:
   - Generate a random linked list using 'random_list()'.
   - Print all node values.
   - Add a new node at the beginning using 'add_first()'.
   - Print the updated list.
   - Free the allocated memory properly.
*/

// Define MAX amount of nodes
#define MAX 5

// Defines a doubly linked list node
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;

} REGTYPE;
// ##### Function declarations #####

// Create a random linked list with MAX nodes.
REGTYPE *random_list(void) {}

// Add a new node at the beginning of the list.
REGTYPE *add_first(REGTYPE *temp, int data);

// ###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); // Random seed
    head = random_list();
    act_post = head;
    while (act_post != NULL)
    {
        printf("\n Post nr %d : %d", nr++, act_post->number);
        act_post = act_post->next;
    }

    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }
    return 0;
}

// ==== End of main ======================================

/*
1. Create MAX nodes.
2. Assign random numbers to each node.
3. Properly link prev and next pointers.
4. Return the head of the list.
*/
REGTYPE *random_list(void)
{

    // Nod 1 --> pointing to what?
    // Nod 2 -->

    /*
    1. For-loop
    2. Initialize head and tail previous to for loop?
    3. If I = 0 --> Set nodes left pointer to head (NULL)
    4. If I = MAX - 1 --> Set nodes right pointer to tail (NULL)
    5. Input random value
    6. Set left pointer and right pointer
    7. Increment I and continue


    */
    // MAX NODES = 5 --> define MAX
    int nr = MAX, i = 0;

    REGTYPE *head, *prev, *curr;

    //prev= // new node

    for (i; i < nr; i++)
    {
        // number --> 1
        //  next ? == NULL
        //  prev? == NULL

        //iteration 2
        // prev.next == curr
        // curr.prev == prev

        prev = curr;
    }

    return (head);
}

//==========================================================

/*
1. Create a new node.
2. Assign data to the number field.
3. Set prev to NULL (since it’s the first node).
4. Link next to the current head.
5. Return the new head.
*/
REGTYPE *add_first(REGTYPE *temp, int data)
{
}