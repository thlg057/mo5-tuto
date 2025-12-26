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

#define MO5_CLEAR_SCREEN 12
#define FALSE 0
#define TRUE  1

static void mo5_clear_screen(void)
{
    putchar(MO5_CLEAR_SCREEN);
}

static char mo5_getchar(void)
{
    asm {
        swi
        fcb $0A
    }
}

static int mo5_isprint(char c) {
    return (c >= 32 && c <= 126);
}

int main(void)
{    
    mo5_clear_screen();
    printf("CHARACTER CODE EXPLORER\r\n");
    printf("=======================\r\n");
    printf("\r\n");
    printf("Press any key to see its code\r\n");
    printf("(Screen will scroll)\r\n");
    printf("\r\n");

    // Infinite loop - read and display character codes
    while (1) {
        char ch;
        printf("> ");

        // Read a character - wait for a real keypress (ignore 0)
        do {
            ch = mo5_getchar();
        } while (ch == 0);

        unsigned int code = (unsigned char)ch;
        if (mo5_isprint(ch)) {
            printf("Code: %u ('%c')\r\n", code, ch);
            continue;
        }
        
        printf("Code: %u\r\n", code);
    }
    
    return 0;
}
