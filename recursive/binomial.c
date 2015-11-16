/* Cnm = n!/(m!(n-m)!)
 */
#include <stdio.h>

int binomial(int n, int m)
{
  if (m==0 || m==n)
    return 1;
  return binomial(n-1, m) + binomial(n-1, m-1);
}

int main(void)
{
  int i;

  for (i = 0; i <= 10; i++)
    printf("C(10, %d)=%d\n", i, binomial(10, i));

  return 0;
}
