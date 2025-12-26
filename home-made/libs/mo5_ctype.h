#ifndef CTYPE_H
#define CTYPE_H

#include "mo5_defs.h"

/**
 * @brief Checks if the character is a decimal digit ('0' to '9').
 * @param c Character to test.
 * @return Boolean value: TRUE if c is a digit, FALSE otherwise.
 */
Boolean isdigit(char c);

/**
 * @brief Checks if the character is an alphabetic letter ('A'-'Z' or 'a'-'z').
 * @param c Character to test.
 * @return Boolean value: TRUE if c is alphabetic, FALSE otherwise.
 */
Boolean isalpha(char c);

/**
 * @brief Checks if the character is alphanumeric (letter or digit).
 * @param c Character to test.
 * @return Boolean value: TRUE if c is alphanumeric, FALSE otherwise.
 */
Boolean isalnum(char c);

/**
 * @brief Checks if the character is a lowercase letter ('a' to 'z').
 * @param c Character to test.
 * @return Boolean value: TRUE if c is lowercase, FALSE otherwise.
 */
Boolean islower(char c);

/**
 * @brief Checks if the character is an uppercase letter ('A' to 'Z').
 * @param c Character to test.
 * @return Boolean value: TRUE if c is uppercase, FALSE otherwise.
 */
Boolean isupper(char c);

/**
 * @brief Checks if the character is a whitespace character (space, tab, newline, etc.).
 * @param c Character to test.
 * @return Boolean value: TRUE if c is whitespace, FALSE otherwise.
 */
Boolean isspace(char c);

/**
 * @brief Checks if the character is printable (excluding control characters).
 * @param c Character to test.
 * @return Boolean value: TRUE if c is printable, FALSE otherwise.
 */
Boolean isprint(char c);

/**
 * @brief Checks if the character is a punctuation character.
 * @param c Character to test.
 * @return Boolean value: TRUE if c is punctuation, FALSE otherwise.
 */
Boolean ispunct(char c);

/* Case conversion functions */

/**
 * @brief Converts an uppercase letter to lowercase.
 * @param c Character to convert.
 * @return Lowercase equivalent if c is uppercase, otherwise returns c unchanged.
 */
char tolower(char c);

/**
 * @brief Converts a lowercase letter to uppercase.
 * @param c Character to convert.
 * @return Uppercase equivalent if c is lowercase, otherwise returns c unchanged.
 */
char toupper(char c);

#endif