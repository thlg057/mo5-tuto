/*
 * TUTORIAL 1: Name Greeting Program
 * Thomson MO5 - Interactive name input and greeting
 * 
 * This program demonstrates:
 * - Screen clearing
 * - String output
 * - User input with echo
 * - String concatenation for personalized output
 */

#include "mo5_defs.h"
#include "mo5_stdio.h"
#include "mo5_string.h"

/* ========================================
 * CONSTANTS
 * ======================================== */

#define MAX_NAME_LENGTH 30

/* ========================================
 * MAIN PROGRAM
 * ======================================== */

void mo5_clear_buffer(char* buffer, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

void mo5_wait_key(char key)
{
    char ch;

    // Wait for the specific key - ignore all invalid characters
    do {
        ch = getchar();
    } while (ch != key);
}

int main(void)
{
    char name[MAX_NAME_LENGTH + 1];  // +1 for null terminator

    // Infinite loop to greet multiple people
    while (1) {
        // Clear screen for clean display
        clrscr();
        //mo5_clear_buffer(name, MAX_NAME_LENGTH + 1);
        memset(name, 0, MAX_NAME_LENGTH + 1);
        // Display welcome prompt
        fputs("What is your first name?\n");

        // Read user input
        int size = fgets(name, MAX_NAME_LENGTH);
        fputs("\n");

        // Display personalized greeting
        fputs("Hello "); fputs(name); fputs("!\n");

        // Wait for 'Y' key before next iteration
        fputs("\n");
        fputs("Press Y to continue...");
        mo5_wait_key('Y');
    }

    return 0;
}

