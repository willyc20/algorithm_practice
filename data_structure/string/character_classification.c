#include "string.h"

/* checks if a character is alphanumeric */
int isalnum(int ch)
{
  if ((ch >= 'A' && ch <= 'Z') ||
      (ch >= 'a' && ch <= 'z') ||
      (ch >= '0' && ch <= '9'))
    return 1;
  else
    return 0;
}

/* checks if a character is alphabetic */
int isalpha(int ch)
{
  if ((ch >= 'A' && ch <= 'Z') ||
      (ch >= 'a' && ch <= 'z'))
    return 1;
  else
    return 0;
}

/* checks if a character is lowercase */
int islower(int ch)
{
  if (ch >= 'a' && ch <= 'z')
    return 1;
  else
    return 0;
}

/* checks if a character is an uppercase character */
int isupper(int ch)
{
  if (ch >= 'A' && ch <= 'Z')
    return 1;
  else
    return 0;
}

/* checks if a character is a digit */
int isdigit(int ch)
{
  if (ch >= '0' && ch <= '9')
    return 1;
  else
    return 0;
}

/* checks if a character is a hexadecimal character */
int isxdigit(int ch)
{
  if ((ch >= 'A' && ch <= 'F') ||
      (ch >= 'a' && ch <= 'f') ||
      (ch >= '0' && ch <= '9'))
    return 1;
  else
    return 0;
}

/* checks if a character is a control character */
int iscntrl(int ch)
{
  if ((ch > 0x00 && ch < 0x1F) ||
      ch == 0x7F)
    return 1;
  else
    return 0;
}

/* checks if a character is a graphical character */
/*
int isgraph(int ch)
{

}
*/

/* checks if a character is a space character */
int isspace(int ch)
{
  if (ch == 0x20 || // space
      ch == 0x0c || // form feed
      ch == 0x0a || // line feed
      ch == 0x0d || // carriage return
      ch == 0x09 || // horizontal tab 
      ch == 0x0b)   // vertical tab
    return 1;
  else
    return 0;
}

/* checks if a character is a blank character */
int isblank(int ch)
{
  if (ch == 0x20 || // space
      ch == 0x09)   // horizontal tab 
    return 1;
  else
    return 0;
}

/* checks if a character is a printing character */
/*
int isprint(int ch)
{
  
}
*/

/* checks if a character is a punctuation character */
/*
int ispunct(int ch)
{
}
*/

