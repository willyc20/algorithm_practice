/*
 * ack(m, n) = n+1 if m = 0
 *           = ack(m-1, 1) if n = 0
 *           = A(m-1, A(m, n-1) otherwise
 */
#include <stdio.h>

int ackerman(int m, int n)
{
  if (m == 0)
    return n+1;
  if (n == 0)
    return ackerman(m-1, 1);
  return ackerman(m-1, ackerman(m, n-1));
}

int main(void)
{
  int i, j;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      printf("ackerman(%d, %d)=%d\n", i, j, ackerman(i, j));

  return 0;
}
