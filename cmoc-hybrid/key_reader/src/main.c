/*
 * MIT License
 *
 * Copyright (c) 2025 Thierry Le Got
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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

