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

#define _CMOC_HAVE_FALSE_TRUE_

#include <cmoc.h>    
#include <coco.h>      
#include "mo5_stdio.h"
#include "mo5_ctype.h"

#define GRID_WIDTH  20
#define GRID_HEIGHT 8
#define FUEL_COST   5
#define REWARD_UP   10
#define REWARD_MOVE 2

#define CRLF "\r\n"

static int rocket_x = 10;
static int rocket_y = 5;
static int fuel     = 100;
static int score    = 0;

void engine_sound() {
    // On écrit dans les adresses que ta doc vient de nous révéler
    *(unsigned char*)0x2044 = 1;  // TEMPO
    *(unsigned char*)0x2046 = 5;  // DUREE
    // On appelle un SWI spécifique ou on envoie le caractère 7
    putchar(7); 
}

void render(void)
{
    int i, j;

    clrscr();
    putchar(0x0B);
    printf("=== ROCKET SYSTEM ===%s", CRLF);

    printf("FUEL:%d  SCORE:%d%s", fuel, score, CRLF);
    printf("----------------------------%s", CRLF);

    for (i = 0; i < GRID_HEIGHT; ++i)
    {
        putchar('|');
        for (j = 0; j < GRID_WIDTH; ++j)
        {
            if (i == rocket_y && j == rocket_x)
            {
                putchar('A'); /* La Fusée */
                continue;
            }
            
            if (i == 0 && (j == 5 || j == 15))
            {
                putchar('*'); /* Étoiles */
                continue;
            }
            
            if (i == GRID_HEIGHT - 1)
            {
                putchar('='); /* Sol */
                continue;
            }
            
            putchar(' ');
        }

        printf("|%s", CRLF);
    }
    
    printf("%s[ZSQD] Bouger  [E] Quitter%s> ", CRLF, CRLF);
}

char get_action(void)
{
    char c;
    while (TRUE)
    {
        c = getchar();
        if (c == 0) continue;

        c = toupper(c);
        if (strchr("ZSQDE", c))
        {
            putchar(c);
            return c;
        }
    }
}

void wait_key(char key)
{
    char ch;

    do {
        ch = getchar();
    } while (ch != key);
}

int main(void)
{
    char input;
    Boolean running = TRUE;

    clrscr();
    printf("COMMANDE DE VOL MO5%s", CRLF);
    printf("Preparez-vous au decollage...%s", CRLF);
    getchar();

    while (running)
    {
        render();
        input = get_action();

        switch (input)
        {
            case 'Z':
                if (rocket_y > 0 && fuel > 0) {
                    rocket_y--;
                    fuel -= FUEL_COST;
                    score += REWARD_UP;
                    engine_sound();
                }
                break;
            case 'S':
                if (rocket_y < GRID_HEIGHT - 2) {
                    rocket_y++;
                    fuel -= FUEL_COST;
                    score += REWARD_MOVE;
                }
                break;
            case 'Q':
                if (rocket_x > 0) rocket_x--;
                fuel -= FUEL_COST;
                break;
            case 'D':
                if (rocket_x < GRID_WIDTH - 1) rocket_x++;
                fuel -= FUEL_COST;
                break;
            case 'E':
                running = FALSE;
                break;
        }

        if (fuel <= 0 && rocket_y < GRID_HEIGHT - 2)
        {
            disableInterrupts();
            while (running)
            {
                rocket_y++;
                if (rocket_y >= GRID_HEIGHT - 2)
                {
                    running = FALSE;
                }

                render();
                delay(30);
            }
            
            enableInterrupts();
        } 
    }

    /* Game Over */
    clrscr();
    printf("!!! MISSION TERMINEE !!!%s", CRLF);
    printf("Resultat final : %d%s", score, CRLF);
    printf("%sAppuyez sur Y pour continuer.%s", CRLF, CRLF);
    wait_key('Y');

    return 0;
}