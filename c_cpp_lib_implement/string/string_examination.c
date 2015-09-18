#include "string.h"

/* return the length of a given string */
size_t strlen(const char *str)
{
  size_t len;
  for (len = 0; str[len] != '\0'; len++);
  return len;
}

/* compares two strings */
int strcmp(const char *lhs, const char *rhs)
{
  while (*lhs != '\0' && *rhs != '\0') {
    if (*lhs > *rhs)
      return 1;
    if (*lhs < *rhs)
      return -1;
    lhs++;
    rhs++;
  }
  if (*lhs != '\0')
    return 1;
  if (*rhs != '\0')
    return -1;
  return 0;
}

/* compares a certain amount of characters of two strings */
int strncmp(const char *lhs, const char *rhs, size_t count)
{
  int i;
  for (i = 0; i < count; i++) {
    if (*lhs > *rhs)
      return 1;
    if (*lhs < *rhs)
      return -1;
    lhs++;
    rhs++; 
  }
  if (*lhs != '\0')
    return 1;
  if (*rhs != '\0')
    return -1;
  return 0;
}

/* finds the first occurrence of a character */
char *strchr(const char *str, int ch);
/* finds the last occurrence of a character */
char *strrchr(const char *str, int ch);
