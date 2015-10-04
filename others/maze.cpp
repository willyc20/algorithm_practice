// 老鼠走迷宮
// 基本的遞迴問題
#include <iostream>
using namespace std;
#define SIZE 10

bool solution(int maze[SIZE][SIZE], int row, int col)
{
  // 可走
  if (maze[row][col] == 0) {
    maze[row][col] = 2;
    
    // 終點
    if (row == 8 && col == 8)
      return true;

    // 走不到
    if (!(solution(maze, row+1, col) ||
          solution(maze, row-1, col) ||
          solution(maze, row, col+1) ||
          solution(maze, row, col-1))) {
      maze[row][col] = 0;
      return false;
    }

    // 走的到
    return true;
  }

  // 牆壁
  return false;
}

int main(void)
{
  // 0=可走 1=不可走 2=正確路徑
  int maze[SIZE][SIZE] = {{1,1,1,1,1,1,1,1,1,1},
                          {1,0,1,0,1,0,0,0,0,1},
                          {1,0,0,0,1,0,1,1,1,1},
                          {1,0,1,0,0,0,0,1,0,1},
                          {1,0,1,0,1,1,1,1,0,1},
                          {1,0,1,0,0,1,1,1,0,1},
                          {1,1,1,1,0,0,0,0,0,1},
                          {1,0,0,1,0,1,1,1,0,1},
                          {1,1,0,0,0,0,0,1,0,1},
                          {1,1,1,1,1,1,1,1,1,1}};

  solution(maze, 1, 1);

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      cout << maze[i][j];
    }
    cout << endl;
  }

  return 0;
}
