//  實作c語言標準函式庫string.h中多數功能
//  參考文件：http://en.cppreference.com/w/c/string/byte
#ifndef __STRING_H__
#define __STRING_H__
#include <stddef.h>



// Character classification
/* checks if a character is alphanumeric */
int isalnum(int ch);
/* checks if a character is alphabetic */
int isalpha(int ch);
/* checks if a character is lowercase */
int islower(int ch);
/* checks if a character is an uppercase character */
int isupper(int ch);
/* checks if a character is a digit */
int isdigit(int ch);
/* checks if a character is a hexadecimal character */
int isxdigit(int ch);
/* checks if a character is a control character */
int iscntrl(int ch);
/* checks if a character is a graphical character */
//int isgraph(int ch);
/* checks if a character is a space character */
int isspace(int ch);
/* checks if a character is a blank character */
int isblank(int ch);
/* checks if a character is a printing character */
//int isprint(int ch);
/* checks if a character is a punctuation character */
//int ispunct(int ch);

// Character manipulation



// Conversions to numeric formats



// String manipulation



// String examination

/* return the length of a given string */
size_t strlen(const char *str);
/* compares two strings */
int strcmp(const char *lhs, const char *rhs);
/* compares a certain amount of characters of two strings */
int strncmp(const char *lhs, const char *rhs, size_t count);
/* compares two strings in accordance to the current locale */
//int strcoll(const char *lhs, const char *rhs);
/* finds the first occurrence of a character */
char *strchr(const char *str, int ch);
/* finds the last occurrence of a character */
char *strrchr(const char *str, int ch);

// Character array manipulation



// Miscellaneous

#endif
