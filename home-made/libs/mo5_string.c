#include "mo5_string.h"
#include "mo5_ctype.h"

size_t strlen(const char* s)
{
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

char* strcpy(char* dst, const char* src) {
    char* ret = dst;
    while ((*dst++ = *src++)) { } ; // copie chaque caractère, y compris le '\0'
    return ret;
}

int strcmp(const char* s1, const char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

char* strcat(char* dst, const char* src) {
    char* ret = dst;
    while (*dst) dst++;         // aller à la fin de dst
    while ((*dst++ = *src++)) {
        /* intentional assignment in condition */
    }
    return ret;
}

void memset(void* s, int c, size_t n) {
    unsigned char* p = (unsigned char* )s;
    while (n--) {
        *p++ = (unsigned char)c;
    }
}

void* memcpy(void* dst, const void* src, size_t n) {
    unsigned char* d = (unsigned char* )dst;
    const unsigned char* s = (const unsigned char* )src;
    while (n--) {
        *d++ = *s++;
    }
    return dst;
}

int memcmp(const void* s1, const void* s2, size_t n) {
    const unsigned char* p1 = (const unsigned char* )s1;
    const unsigned char* p2 = (const unsigned char* )s2;
    while (n--) {
        if (*p1 != *p2) return *p1 - *p2;
        p1++;
        p2++;
    }
    return 0;
}

char* strupr(char* s) {
    char* p = s;
    while (*p) {
        *p = toupper(*p);
        p++;
    }
    return s;
}

char* strlwr(char* s) {
    char* p = s;
    while (*p) {
        *p = tolower(*p);
        p++;
    }
    return s;
}

char *itoa(int value, char *buffer)
{
    char *p = buffer;
    int sign = value;
    char *start;

    if (value < 0) {
        value = -value;
    }

    // Génération des chiffres (ordre inversé)
    do {
        *p++ = (char)((value % 10) + '0');
        value /= 10;
    } while (value);

    if (sign < 0) {
        *p++ = '-';
    }

    // Le terminateur est placé ICI
    *p = '\0'; 

    /* Inversion de la chaîne */
    // On garde 'p' pointé sur le caractère juste AVANT le '\0'
    start = buffer;
    p--; 
    
    while (start < p) {
        char tmp = *start;
        *start++ = *p;
        *p-- = tmp;
    }

    return buffer;
}
