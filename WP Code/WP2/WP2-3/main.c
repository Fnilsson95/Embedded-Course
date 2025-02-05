// (C) Fredrik Nilsson, Emma Olmås, Erik Lidbom
// Work package 2
// WP2 - Exercise 3 - Binary Files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Write a program to manage a database of PERSONS.
 * The file should be stored as a BINARY file (wb+, ab+, rb+)
 * 1. Create a new and delete the old file (wb+, if already exists, discard old changes)
 * 2. Add a new person to the file
 * 3. Search for a person in the file
 * 4. Print out all in the file
 * 5. Exit the program
 *
 *
 *
 * Error handling
 * 1. Checking if the file exists
 * 2. If the list is empty
 * */

// FILE *file = fopen("persons.dat", "wb+"); // Open in binary mode (overwrite)
// Creates file in directory you are in if no file path specified
// In case below, creates file "persons.dat" in file path in WP2 folder

// Baseline code is inspired from the book "C How to program 5th edition - page 449-452

#define MAX_OPTION 5
#define MIN_OPTION 1


// typedefs of PERSON type
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declarations -- Prototypes
PERSON input_record(void);
// 1. Creates a file and writes the first record
void write_new_file(PERSON *inrecord);
// 2. appends a new person to the file
void printfile(void);
// 3. Prints out the person if in list
void search_by_firstname(char *name);
// 4. Prints out all persons in the file
void append_file(PERSON *inrecord);

// Entry point to main program
// Program manages a database of persons where it:
// Creates/Reads/Modifies a file of Persons
int main () {

    // Declare input request variable to control user request for program
    int inputRequest;
    // Declare a PERSON struct
    PERSON ppost;

    // While-loop that runs program and exits when user inputs 5
    while (1) {
        // Display all the user options
        printf("Enter request\n"
            " 1 - Create a new and delete old file (Overwrite old)\n"
            " 2 - Add a new person to the file(Append)\n"
            " 3 - Search for a person in the file(Read)\n"
            " 4 - Print out all in file(Read)\n"
            " 5 - Exit the program\n");

        // Validation of input request, must be an integer and within valid range (1-5
        if (scanf("%d", &inputRequest) != 1 || inputRequest < MIN_OPTION || inputRequest > MAX_OPTION) {

            printf("Wrong input. Please provide an option between 1-5\n");
            // Remove any possible trailing characters
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        // Switch-statement that controls the menu option for user
        switch (inputRequest) {

            case 1:
                printf("Create a new and delete the old file.\n");
                write_new_file(&ppost);
                break;

            case 2:
                printf("Add a new person to the file.\n");
                append_file(&ppost);
                break;

            case 3:
                // User input for which name to search for in the file
                printf("Search for a person in the file\n");

                char name[20];
                printf("Enter the name to search:\n");
                //%19s to include one character for \0
                scanf("%19s", name);
                search_by_firstname(name);
                break;

            case 4:
                printf("Print out all in the file\n");
                printfile();
                break;

            case 5:
                printf("Exiting the program.\n");
                // Successful exit status of program
                return 0;

            } // End of Switch-statement
    } // End of While-loop
} // End of Main function


// 1. Creates a file and writes the first record
void write_new_file(PERSON *inrecord) {

    // Create (Overwrite if any old file - wb+) file with both writing and reading for a binary file
    FILE *file = fopen("persons.dat", "wb+");
    // Validation if file is not found --> NULL
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        return; // Exit the function
    }

    // Enter an initial dummy record into newly created file
    PERSON dummyRecord = {"Fredrik", "Nilsson", "199507251234"};
    // Write the dummy record to the file, 1 item of size PERSON
    // Binary files does not know when it ends, therefore we need to specifiy what size, and how many of that size
    fwrite(&dummyRecord, sizeof(PERSON), 1, file);

    // Close the file
    // And tell the operating system that we no longer write to that file,
    // and you can transfer it to the physical place,
    // and forget about the pointer that was initialized.
    fclose(file);
    printf("File created successfully.\n");
}

// 2. appends a new person to the file
void append_file(PERSON *inrecord) {

    // Append a new person to an existing file or create a file for binary use. (ab+)
    FILE *file = fopen ("persons.dat", "ab+");
    // Validation if file is not found --> NULL
    if (file == NULL) {
        printf("Error: File not found.\n");
        return; // Exit the function
    }

    // User input
    // Append user input to PERSON inrecord
    printf("Enter first name: \n");
    scanf("%19s", inrecord->firstname);
    printf("Enter last name: \n");
    scanf("%19s", inrecord->famname);
    printf("Enter personal number (yyyymmddnnnc): \n");
    scanf("%12s", inrecord->pers_number);

    // Write the input from inrecord to file, 1 element of size PERSON
    fwrite(inrecord, sizeof(PERSON), 1, file);

    // Close the file
    fclose(file);
    printf("Successfully added Person %s\n", inrecord->firstname);
}

// 3. Prints out the person if in list
void search_by_firstname(char *name) {

    // Open file for reading in binary mode (rb+)
    FILE *file = fopen ("persons.dat", "rb");
    // Validation if file is not found --> NULL
    if (file == NULL) {
        printf("Error: File not found.\n");
        return; // Exit the function
    }

    // Declare a PERSON struct
    PERSON person;
    // Declare and initialize local variables
    int found = 0;
    int nameChoice;

    // Prompt user to search by either first name or family name
    printf("Search by:\n1 - First name\n2 - Family name\n");
    // Validation that input is an integer and valid option (1 or 2)
    if (scanf("%d", &nameChoice) != 1 || (nameChoice != 1 && nameChoice != 2)) {
        printf("Invalid input.\n");
        fclose(file);
        return;
    }

    // fread returns 1 if one person read successfully, 0 if end of file
    // and while runs while true (1)
    while (fread(&person, sizeof(PERSON), 1, file)) {
        // If-statement to control if user want to search by first name or last name
        if ((nameChoice == 1 && strcmp(person.firstname, name) == 0) ||
            (nameChoice == 2 && strcmp(person.famname, name) == 0)) {
            printf("Found: First name: %s - Family name: %s - Personal number: %s\n",
                   person.firstname, person.famname, person.pers_number);
            // Uses found variable to check if found or to return not found
            found = 1;
            }
    }

    // Close the file
    fclose(file);

    // If no person with that name was found
    if (!found) {
        printf("No records found with that name\n");
    }
}

// 4. Prints out all persons in the file
void printfile(void) {

    // Open file for reading in binary mode (rb+)
    FILE *file = fopen ("persons.dat", "rb");
    // Validation if file is not found --> NULL
    if (file == NULL) {
        printf("Error: File not found.\n");
        return; // Exit the function
    }

    // Declare PERSON struct and initialize count variable
    PERSON person;
    int count = 0;

    printf("List of persons in the file:\n");

    // fread returns 1 if one person read successfully, 0 if end of file
    // and while runs while true (1)
    while (fread(&person, sizeof(PERSON), 1, file)) {
        printf("First name: %s - Family name: %s - Personal number: %s \n",
                person.firstname, person.famname, person.pers_number);
        // Uses count to check if file is empty or not
        count++;
    }

    // Close the file
    fclose(file);

    // If file is empty
    if (count == 0) {
        printf("The file is empty.\n");
    }
}