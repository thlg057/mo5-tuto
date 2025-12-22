/*
 * TUTORIAL 2: Character Code Explorer
 * Thomson MO5 - Display character codes
 * 
 * This program demonstrates:
 * - Reading single characters
 * - Displaying numeric values
 * - Distinguishing printable vs non-printable characters
 * - Scrolling display (no screen clear)
 */

#include "mo5_lib.h"

/* ========================================
 * HELPER FUNCTIONS
 * ======================================== */

/**
 * Display a character code and the character if printable
 */
void display_char_code(char ch)
{
    int code = (int)ch;
    
    // Display the code
    mo5_print_string("Code: ");
    mo5_print_number(code);
    
    // If printable, display the character in parentheses
    if (mo5_is_printable(ch)) {
        mo5_print_string(" (");
        mo5_putchar(ch);
        mo5_print_string(")");
    }
    
    mo5_print_newline();
}

/* ========================================
 * MAIN PROGRAM
 * ======================================== */

int main(void)
{
    char ch;
    
    // Clear screen and show title
    mo5_clear_screen();
    mo5_print_line("CHARACTER CODE EXPLORER");
    mo5_print_line("=======================");
    mo5_print_newline();
    mo5_print_line("Press any key to see its code");
    mo5_print_line("(Screen will scroll)");
    mo5_print_newline();
    
    // Infinite loop - read and display character codes
    while (1) {
        mo5_print_string("> ");

        // Read a character - wait for a real keypress (ignore 0)
        do {
            ch = mo5_getchar();
        } while (ch == 0);

        // Display its code (and character if printable)
        display_char_code(ch);
    }
    
    return 0;
}

