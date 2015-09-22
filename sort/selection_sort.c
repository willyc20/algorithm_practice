#include "sort_tool.h"
#define N 100

int main(void)
{
  int data[N];
  int i, j;
  int temp;
  random_data(data, N);

  for (i = 0; i < N; i++) {
    temp = i;  
    for (j = 0; j < N - i; j++) {
      if (data[temp] > data[j])
        temp = j;
    }
    swap(&data[temp], &data[N - 1 - i]);
  }

  print_data(data, N);

  return 0;
}
