/*
 * MO5_LIB.H - Thomson MO5 Library Header
 * Function declarations for MO5 system calls and utilities
 */

#ifndef MO5_LIB_H
#define MO5_LIB_H

/* ========================================
 * TYPES AND CONSTANTS
 * ======================================== */

typedef enum {
    FALSE = 0,
    TRUE = 1
} Boolean;

#define MO5_MAX_NAME_LENGTH     30
#define MO5_BUFFER_SIZE         32
#define MO5_CLEAR_SCREEN        12
#define MO5_BACKSPACE_CHAR      8
#define MO5_ENTER_CHAR          13
#define MO5_SPACE_CHAR          32
#define MO5_LINE_FEED           10

/* ========================================
 * FUNCTION DECLARATIONS
 * ======================================== */

// Basic system calls
void mo5_putchar(char c);
char mo5_getchar(void);

// Display functions
void mo5_clear_screen(void);
void mo5_print_newline(void);
void mo5_print_string(const char *str);
void mo5_print_line(const char *str);
void mo5_print_number(int num);

// Character validation
Boolean mo5_is_digit(char c);
Boolean mo5_is_printable(char c);

// String functions
int mo5_string_length(const char *str);
void mo5_clear_buffer(char *buffer, int size);

// Input functions
int mo5_input_string(char *buffer, int max_length);
void mo5_pause(void);
void mo5_wait_key(char key);

#endif /* MO5_LIB_H */

