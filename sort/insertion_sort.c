#include <stdio.h>
#include "sort_tool.h"
#define N 100

int main(void)
{
  int data[N];
  int i, j;
  int temp;
  random_data(data, N);

  for (i = 0; i < N; i++) {
    temp = data[0];
    for (j = 0; j < i; j++) {
      if (data[temp] < data[j])
        data[j + 1] = data[j];
      else
        break;
    }
    data[j + 1] = data[temp]; 
  }

  print_data(data, N);

  return 0;
}
