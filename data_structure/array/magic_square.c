// http://home.gamer.com.tw/creationDetail.php?sn=2401207
// 上面參考資料內已經包含了所有介紹跟延伸資料
// 故此不再詳述
//
// 觀察後可發現將1放入第1列的中間
// 之後一直延右上走即可
// 簡單來說 把這個方陣想像成一張世界地圖
// 世界地圖實際上是一個園球
// 在世界地圖上一直往右上角走繞地球有什麼特點呢？
// 就是邊界條件！ 這也是解決此題的關鍵點在
//
// 說起來簡單 但請不要參考任何程式碼實作看看
// 會發現邊界條件很容易讓腦袋打結
#include <stdio.h>
#define SIZE 5 //限定奇數

int main(void)
{
  int magic_square[SIZE][SIZE] = {0};
  int i, j, k;
  int temp1, temp2;

  // 表示起點
  j = 0;
  k = SIZE / 2;

  for (i = 1; i <= SIZE * SIZE; i++) {
    magic_square[j][k] = i;
    temp1 = j;
    temp2 = k;
    j--;
    k++;

    // 判斷右上邊界
    if (j < 0)
      j = SIZE - 1;
    if (k > SIZE - 1)
      k = 0;

    // 一圈繞完 換下一圈
    if (magic_square[j][k] != 0) {
      // 因回去原先位置還要判斷左下邊界
      // 固直接返回
      j = temp1;
      k = temp2;
      j++;
      if (j < 0)
        j = SIZE - 1;
    }     
  }

  // print result
  for (i = 0; i < SIZE; i++) {    
    for (j = 0; j < SIZE; j++) {
      printf("%d", magic_square[i][j]);
      if (j != SIZE - 1)
        printf(" ");
    }
    printf("\n");
  }
}
