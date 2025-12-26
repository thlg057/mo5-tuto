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

#include <cmoc.h>
#include "mo5_stdio.h"
#include "mo5_ctype.h"

void display_char_code(char ch)
{
    static char message[25];
    int code = (int)ch;
    char buffer[10];
    memset(buffer, 0, 10);
    itoa(code, buffer, 0);

    strcpy(message, "Code: ");
    strcat(message, buffer);
    if (isprint(ch)) {
        strcat(message, " (");
        int len = strlen(message);
        message[len] = ch;
        strcat(message, ")");
    }

    puts(message);
}

/* ========================================
 * MAIN PROGRAM
 * ======================================== */

int main(void)
{
    char ch;
    
    // Clear screen and show title
    clrscr();
    puts("CHARACTER CODE EXPLORER");
    puts("=======================");
    puts("");
    puts("Press any key to see its code");
    puts("(Screen will scroll)");
    puts("");

    while (1) {
        fputs("> ");

        do {
            ch = mo5_getchar();
        } while (ch == 0);

        display_char_code(ch);
    }
    
    return 0;
}

