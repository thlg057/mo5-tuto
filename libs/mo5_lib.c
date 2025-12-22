/*
 * MO5_LIB.C - Thomson MO5 Library Implementation
 * System calls and utility functions for Thomson MO5
 */

#include "mo5_lib.h"

/* ========================================
 * THOMSON MO5 SYSTEM CALLS
 * ======================================== */

/**
 * Output a single character to the screen
 * Uses MO5 system call $02
 */
void mo5_putchar(char c)
{
    asm {
        ldb c
        swi
        fcb $02
    }
}

/**
 * Read a single character from keyboard
 * Uses MO5 system call $0A
 */
char mo5_getchar(void)
{
    asm {
        swi
        fcb $0A
    }
}

/* ========================================
 * DISPLAY FUNCTIONS
 * ======================================== */

/**
 * Clear the screen
 */
void mo5_clear_screen(void)
{
    mo5_putchar(MO5_CLEAR_SCREEN);
}

/**
 * Print a newline (CR + LF)
 */
void mo5_print_newline(void)
{
    mo5_putchar(MO5_ENTER_CHAR);  // CR
    mo5_putchar(MO5_LINE_FEED);   // LF
}

/**
 * Print a null-terminated string
 */
void mo5_print_string(const char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        mo5_putchar(str[i]);
        i++;
    }
}

/**
 * Print a string followed by newline
 */
void mo5_print_line(const char *str)
{
    mo5_print_string(str);
    mo5_print_newline();
}

/**
 * Print an integer number
 */
void mo5_print_number(int num)
{
    char buffer[10];
    int i = 0;
    int sign = 0;
    
    if (num < 0) {
        sign = 1;
        num = -num;
    }
    
    if (num == 0) {
        mo5_putchar('0');
        return;
    }
    
    // Convert to string (reverse order)
    while (num > 0) {
        buffer[i] = (char)('0' + (num % 10));
        num /= 10;
        i++;
    }
    
    // Print sign if negative
    if (sign) {
        mo5_putchar('-');
    }
    
    // Print digits in correct order
    while (i > 0) {
        i--;
        mo5_putchar(buffer[i]);
    }
}

/* ========================================
 * CHARACTER VALIDATION
 * ======================================== */

/**
 * Check if character is a digit (0-9)
 */
Boolean mo5_is_digit(char c)
{
    return (c >= '0' && c <= '9') ? TRUE : FALSE;
}

/**
 * Check if character is printable (32-126)
 */
Boolean mo5_is_printable(char c)
{
    return (c >= MO5_SPACE_CHAR && c <= 126) ? TRUE : FALSE;
}

/* ========================================
 * STRING FUNCTIONS
 * ======================================== */

/**
 * Calculate string length
 */
int mo5_string_length(const char *str)
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

/**
 * Clear buffer (fill with zeros)
 */
void mo5_clear_buffer(char *buffer, int size)
{
    int i;
    for (i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

/* ========================================
 * INPUT FUNCTIONS
 * ======================================== */

/**
 * Read a string from keyboard with echo and backspace support
 * Returns the number of characters read
 */
int mo5_input_string(char *buffer, int max_length)
{
    int pos = 0;
    char ch;

    // Clear the buffer first
    mo5_clear_buffer(buffer, max_length + 1);

    while (1) {
        ch = mo5_getchar();

        // Enter key - finish input
        if (ch == MO5_ENTER_CHAR) {
            // Consume any following LINE FEED character
            // Some systems send CR+LF when ENTER is pressed
            break;
        }

        // Backspace - delete last character
        if (ch == MO5_BACKSPACE_CHAR) {
            if (pos > 0) {
                pos--;
                buffer[pos] = '\0';
                // Visual backspace: move back, print space, move back again
                mo5_putchar(MO5_BACKSPACE_CHAR);
                mo5_putchar(MO5_SPACE_CHAR);
                mo5_putchar(MO5_BACKSPACE_CHAR);
            }
            continue;  // Skip to next iteration
        }

        // Printable character - add to buffer
        if (mo5_is_printable(ch) && pos < max_length) {
            buffer[pos] = ch;
            pos++;
            mo5_putchar(ch);  // Echo character
        }
        // Ignore all other characters (including null and control characters)
    }

    buffer[pos] = '\0';
    return pos;
}

/**
 * Pause and wait for any key press
 */
void mo5_pause(void)
{
    char ch;
    mo5_print_string("Press any key...");
    // Wait for a valid printable key or Enter
    do {
        ch = mo5_getchar();
    } while (!mo5_is_printable(ch) && ch != MO5_ENTER_CHAR);
    mo5_print_newline();
}

/**
 * Wait for a specific key to be pressed
 * Ignores all other keys until the specified key is pressed
 */
void mo5_wait_key(char key)
{
    char ch;

    // Wait for the specific key - ignore all invalid characters
    do {
        ch = mo5_getchar();
    } while (ch != key);
}

