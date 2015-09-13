#include <stdio.h>
#include "sort_tool.h"
#define N 100

int main(void)
{
  int data[N];
  int i, j;
  random_data(data, N);

  for (i = 0; i < N - 1; i++) {
    for (j = 0; j < N - 1 - i; j++) {
      if (data[j] > data[j + 1])
        swap(&data[j], &data[j + 1]);
    }
  }

  print_data(data, N);

  return 0;
}
