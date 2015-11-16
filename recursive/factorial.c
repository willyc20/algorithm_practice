/* n! = 1*2*3*...*n
 */

#include <stdio.h>

int factorial(int n)
{
  if (n==0) return 1;
  return factorial(n-1) * n;
}

int main(void)
{
  int i;

  for (i = 1; i < 10; i++)
    printf("%d!=%d\n", i, factorial(i));

  return 0;
}
