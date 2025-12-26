#include "mo5_ctype.h"

Boolean isdigit(char c) {
    return (c >= '0' && c <= '9') ? TRUE : FALSE;
}

Boolean isalpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? TRUE : FALSE;
}

Boolean isalnum(char c) {
    return isdigit(c) || isalpha(c);
}

Boolean islower(char c) {
    return (c >= 'a' && c <= 'z') ? TRUE : FALSE;
}

Boolean isupper(char c) {
    return (c >= 'A' && c <= 'Z') ? TRUE : FALSE;
}

Boolean isspace(char c) {
    return (c == ' '  || c == '\t' || c == '\r' ||
            c == '\n' || c == '\v' || c == '\f') ? TRUE : FALSE;
}

Boolean isprint(char c) {
    return (c >= 32 && c <= 126) ? TRUE : FALSE;
}

Boolean ispunct(char c) {
    return ((c >= 33 && c <= 47)  ||
            (c >= 58 && c <= 64)  ||
            (c >= 91 && c <= 96)  ||
            (c >= 123 && c <= 126)) ? TRUE : FALSE;
}

char tolower(char c) {
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

char toupper(char c) {
    return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}
