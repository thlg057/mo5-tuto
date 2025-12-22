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

#include "mo5_lib.h"

/* ========================================
 * CONSTANTS
 * ======================================== */

#define MAX_NAME_LENGTH 30

/* ========================================
 * MAIN PROGRAM
 * ======================================== */

int main(void)
{
    char name[MAX_NAME_LENGTH + 1];  // +1 for null terminator

    // Infinite loop to greet multiple people
    while (1) {
        // Clear screen for clean display
        mo5_clear_screen();
        mo5_clear_buffer(name, MAX_NAME_LENGTH + 1);
        // Display welcome prompt
        mo5_print_line("What is your first name?");
        mo5_print_newline();

        // Read user input
        mo5_input_string(name, MAX_NAME_LENGTH);
        mo5_print_newline();
        mo5_print_newline();

        // Display personalized greeting
        mo5_print_string("Hello ");
        mo5_print_string(name);
        mo5_print_line("!");

        // Wait for 'Y' key before next iteration
        mo5_print_newline();
        mo5_print_string("Press Y to continue...");
        mo5_wait_key('Y');
        mo5_print_newline();
    }

    return 0;
}

