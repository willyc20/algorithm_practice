// https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
// 參考wiki百科
//
// 實作重點在於這一段話
// 1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
// 2. Any live cell with two or three live neighbours lives on to the next generation.
// 3. Any live cell with more than three live neighbours dies, as if by overcrowding.
// 4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
// 簡單來說每回合有四種狀態變化
// 孤單死掉、持平活著、太擠死掉、持平復活
//
// 本次思路為使用兩個矩陣
// 輪流當作下一次的狀態
#include <stdio.h>
#define LIVE 1
#define DEAD 0
#define SIZE 6
#define SWAP(a, b) (a = a+b, b = a-b, a = a-b)

int check_neighbours(int array[2][SIZE][SIZE], int now, int rpos, int cpos, int type)
{
  int i, j;
  int count = 0;
  int rtemp, ctemp;
  for (i = -1; i < 2; i++) {
    for (j = -1; j < 2; j++) {
      rtemp = rpos + i;
      ctemp = cpos + j;
      if (!((rtemp < 0 || rtemp >= SIZE) ||
           (ctemp < 0 || ctemp >= SIZE) ||
           (rtemp == rpos && ctemp == cpos)))
        if (array[now][rtemp][ctemp] == type)
          count++;
    }
  }
  return count;
}

void print(int array[2][SIZE][SIZE], int now)
{
  int i, j;
  for (i = 0; i < SIZE; i++) {
    for (j = 0; j < SIZE; j++) {
      printf("%d", array[now][i][j]);
    }
    printf("\n");
  }

}

int main(void)
{
  int array[2][SIZE][SIZE] = {0};
  int round = 1;
  int now = 0, next = 1;
  int i, j;

  // 給定初始細胞
  array[now][1][1] = LIVE;
  array[now][1][2] = LIVE;
  array[now][2][1] = LIVE;
  array[now][3][4] = LIVE;
  array[now][4][3] = LIVE;
  array[now][4][4] = LIVE;

  while (round <= 20) {
    printf("%dround\n", round++);
    print(array, now);
    for (i = 0; i < SIZE; i++) {
      for (j = 0; j < SIZE; j++) {
        if (array[now][i][j] == LIVE) {
          switch (check_neighbours(array, now, i, j, LIVE)) {
            // 持平活著
            case 2: case 3:
              array[next][i][j] = LIVE;
              break;
            default:
            // 孤單死掉           
            // 太擠死掉
              array[next][i][j] = DEAD;
              break;
          }
        }
        else {
          // 持平復活
          if (check_neighbours(array, now, i, j, LIVE) == 3)
            array[next][i][j] = LIVE;
        }
      }
    }

    SWAP(now, next);
  }

  return 0;
}

// 雖說原理很簡單
// 用C寫還是debug了一陣子
// 功力還是不足
//
// 觀察一下
// 有限空間應該只會趨向 全空 填滿 規律變化三種可能
// 無限空間就不知道了
// 網路找了一下沒有找到比較明確的證明
// 故純屬推測
