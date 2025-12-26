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
#include "mo5_stdio.h"

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
    fputs("Code: ");
    mo5_print_number(code);
    
    // If printable, display the character in parentheses
    if (mo5_is_printable(ch)) {
        fputs(" (");
        mo5_putchar(ch);
        fputs(")");
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
    puts("CHARACTER CODE EXPLORER");
    puts("=======================");
    mo5_print_newline();
    puts("Press any key to see its code");
    puts("(Screen will scroll)");
    mo5_print_newline();
    display_char_code('\n');
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

