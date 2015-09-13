#include "sort_tool.h"

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void random_data(int *array, int n)
{
  int i;
  srand(time(NULL));
  for (i = 0; i < n; i++) {
    array[i] = rand() % 65535;
  }
}

void print_data(int *array, int n)
{
  int i;
  for (i = 0; i < n; i++) {
    printf("%d", array[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n");
}
