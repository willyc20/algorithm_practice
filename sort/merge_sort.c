// merge sort的核心思維就是把已經排好序的兩個序列合在一起
// 然後一樣能排序未排序的序列 
// 因為可以把每一個值都當做一個已經排序的序列orz
// 跟quick sort一樣都是divide and conquer的思路
// 不過一個從分到合 一個從合到分
#include "sort_tool.h"
#define N 100

void merge_sort(int data[], int n)
{
}


int main(void)
{
  int data[N];
  random_data(data, N);

  merge_sort(data, N);

  print_data(data, N);
  
  return 0;
}
