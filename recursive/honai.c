#include <stdio.h>

void honai(int n, char a, char b, char c)
{
  if (n == 1)
    printf("%c => %c\n", a, c);
  else {
    honai(n-1, a, c, b);
    printf("%c => %c\n", a, c);
    honai(n-1, b, a, c);
  }
}

int main(void)
{
  honai(3, 'A', 'B', 'C');


  return 0;
}
