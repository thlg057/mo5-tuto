#ifndef MO5_STRING_H
#define MO5_STRING_H

/**
 * @typedef size_t
 * @brief Type used to represent the size of a string or memory block.
 */
typedef unsigned int size_t;

/**
 * @brief Computes the length of a null-terminated string.
 * @param s String whose length is to be calculated.
 * @return The number of characters before the '\0' terminator.
 */
size_t strlen(const char* s);

/**
 * @brief Copies a source string into a destination string.
 * @param dst Destination string.
 * @param src Source string.
 * @return Pointer to the destination string.
 */
char* strcpy(char* dst, const char* src);

/**
 * @brief Compares two strings.
 * @param s1 First string.
 * @param s2 Second string.
 * @return <0 if s1 < s2, 0 if s1 == s2, >0 if s1 > s2.
 */
int strcmp(const char* s1, const char* s2);

/**
 * @brief Concatenates a source string at the end of a destination string.
 * @param dst Destination string (must be large enough to hold both strings).
 * @param src Source string.
 * @return Pointer to the destination string.
 */
char* strcat(char* dst, const char* src);

/**
 * @brief Fills a memory area with a given byte value.
 * @param s Pointer to the memory area to fill.
 * @param c Value to write into each byte.
 * @param n Number of bytes to fill.
 */
void memset(void* s, int c, size_t n);

/**
 * @brief Copies n bytes from a source memory area to a destination memory area.
 * @param dst Destination memory area.
 * @param src Source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to the destination memory area.
 */
void* memcpy(void* dst, const void* src, size_t n);

/**
 * @brief Compares n bytes of two memory areas.
 * @param s1 First memory area.
 * @param s2 Second memory area.
 * @param n Number of bytes to compare.
 * @return <0 if s1 < s2, 0 if s1 == s2, >0 if s1 > s2.
 */
int memcmp(const void* s1, const void* s2, size_t n);

/**
 * @brief Converts all characters in a string to uppercase.
 * @param s String to convert.
 * @return Pointer to the converted string.
 */
char* strupr(char* s);

/**
 * @brief Converts all characters in a string to lowercase.
 * @param s String to convert.
 * @return Pointer to the converted string.
 */
char* strlwr(char* s);

/**
 * @brief Converts an integer to a null-terminated string.
 * @param value Integer value to convert.
 * @param buffer Destination buffer.
 * @return Pointer to the buffer.
 */
char* itoa(int value, char *buffer);

#endif