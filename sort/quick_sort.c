#include "sort_tool.h"
#define N 100

// 直接參考： http://openhome.cc/Gossip/AlgorithmGossip/QuickSort2.htm
// 他寫的太簡潔又好懂了
// 
// 中間的交換特性很奇怪 仔細觀察一下發現真的是對的
// 軸只是一個當標準的值 
// 很多quicksort的講解都會強調最後才把軸放進去
// 其實並不一定要這樣 照樣會小的在左邊 大的在右邊
void quick_sort1(int data[], int left, int right)
{
  if (left < right) {
    int s = data[(left+right)/2];
    int i = left - 1;
    int j = right + 1;

    while (1) {
      while (data[++i] < s);
      while (data[--j] > s);
      if (i >= j)
        break;
      swap(data+i, data+j);
    }

    quick_sort1(data, left, i - 1);
    quick_sort1(data, j + 1, right);
  }
}

int main(void)
{
  int data[N];
  random_data(data, N);

  quick_sort1(data, 0, N);

  print_data(data, N);
  
  return 0;
}
