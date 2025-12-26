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
#define NAME_MAX_LENGTH 30

static void mo5_clear_screen(void)
{
    putchar(MO5_CLEAR_SCREEN);
}

static void ask_first_name(char *buffer, size_t size)
{
    char *input = NULL;

    printf("What is your first name?\r\n");
    input = readline();

    if (input != NULL) {
        strncpy(buffer, input, size - 1);
        buffer[size - 1] = '\0';
        return;
    }

    strcpy(buffer, "Unknown");
}

int main(void)
{
    char name[NAME_MAX_LENGTH + 1];

    for (;;) {
        mo5_clear_screen();
        ask_first_name(name, sizeof(name));
        printf("\r\n\r\n");
        printf("Hello %s!\r\n", name);
        printf("Press ENTER to continue...");
        readline();
    }

    return 0;
}
