// 很棒的gcd寫法
// 筆記一下
#include <stdio.h>

int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a % b);
}

int main(void)
{
  printf("%d\n", gcd(16, 28));

  return 0;
}
