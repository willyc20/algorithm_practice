// fabonacci數列幾乎是每個學程式的人，在初學遞迴觀念的時候會碰到的。
// 雖然看起來很簡單，其實包含了很多有趣的東西。
// *:若出現undefined 'pow' 請加上-lm參數（表示連結至數學函式庫）
#include <stdio.h>
#include <math.h>

// 執行次數計算
int count1 = 0;
int count2 = 0;


// 最簡單的遞迴實作
// 其實複雜度高達O(2^(n/2))
// n = 40就能感覺到效能問題
int fabonacci1(int n)
{
  count1++;
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fabonacci1(n - 1) + fabonacci1(n - 2);
}

// 運用了dynamic programming的思路 
// 複雜度只用O(n)
// 在n = 40的時候跟fabonacci1的效率相比天差地遠
int save[100] = {0};
int fabonacci2(int n)
{
  count2++;
  if (n == 0) {
    save[0] = 0;
    return 0;
  }
  if (n == 1) {
    save[1] = 1;
    return 1;
  }
  if (save[n] != 0)
    return save[n];
  save[n] = fabonacci2(n - 1) + fabonacci2(n - 2);
  return save[n];
}

// 迭代解法
// 雖然也是O(n)
// 但可以比較出來遞迴解法是比較優雅的
// 當遇到問題可以拆解成同性質的小問題時
// 遞迴常常比迭代還要好表達
int fabonacci3(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  int i, result = 0, temp1 = 0, temp2 = 1;
  for (i = 2; i <= n; i++) {
    result = temp1 + temp2;
    temp1 = temp2;
    temp2 = result;
  }
  return result;
}

// 數學式解
// 當然一般程式員不會特別去背這種東西就是了
// 純記憶的東西還是交給google吧
// 之前直覺以為這樣是O(1)
// 我錯了是O(n)才對 n次方 恩
int fabonacci4(int n)
{
  double a = (1 + sqrt(5)) / 2;
  double b = (1 - sqrt(5)) / 2;
  double c = sqrt(5) / 5;
  return (int)(c * (pow(a, n) - pow(b, n)));
}

int main(void)
{
  printf("簡單遞迴解法\n");
  printf("result=%d\n", fabonacci1(40));
  printf("共呼叫%d次\n", count1);

  printf("動態規劃解法\n");
  printf("result=%d\n", fabonacci2(40));
  printf("共呼叫%d次\n", count2); 
  
  printf("迭代解法\n");
  printf("result=%d\n", fabonacci3(40));
  
  printf("數學式解法\n");
  printf("result=%d\n", fabonacci4(40));
  
  return 0;
}

// 一個看似簡單的fabonacci
// 卻能清楚的表達了recursive跟dynamic programming的思想
// 以及數學式的威力 真的是非常棒的東西
//
// 此外除去那個大家最常見的唬爛兔子範例
// 它跟自然界的很多現象真的息息相關
// 跟黃金比例也有關係喔
// 不過這是題外話 有興趣在自己google吧
