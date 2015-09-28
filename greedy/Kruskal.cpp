// wiki:https://zh.wikipedia.org/zh-tw/%E5%85%8B%E9%B2%81%E6%96%AF%E5%85%8B%E5%B0%94%E6%BC%94%E7%AE%97%E6%B3%95
// 找minimum spnning tree的演算法，另外還有Prim跟Boruvka，都大同小異
#include <iostream>
#include <set>
using namespace std;
#define INFINITY 9999999 // 假定一個夠大的數是無窮大
#define V_len 6

int result[V_len][V_len];

void Kruskal(int G[V_len][V_len])
{
  set<int> on_tree;
  for (int i = 0; i < V_len; i++) {
    for (int j = 0; j < V_len; j++) {
      result[i][j] = INFINITY;
    }
  }

  while (on_tree.size() != V_len) {
    int mini = 0, minj = 0;
    for (int i = 0; i < V_len; i++) {
      for (int j = 0; j < i; j++) {
        if (G[i][j] < G[mini][minj]) {
          mini = i;
          minj = j;
        }
      }
    }
    if (!(on_tree.find(mini) != on_tree.end() && 
          on_tree.find(minj) != on_tree.end())) {
      on_tree.insert(mini);
      on_tree.insert(minj);
      result[mini][minj] = result[minj][mini] = G[mini][minj];
    }
    G[mini][minj] = INFINITY;
  }
}

int main(void)
{
  // wiki沒給圖 隨便建一個
  int graph[V_len][V_len] = {{INFINITY,       6,      10,INFINITY,      12,INFINITY},
                             {       6,INFINITY,INFINITY,       5,       8,       4},
                             {      10,INFINITY,INFINITY,       9,      16,INFINITY},
                             {INFINITY,       5,       9,INFINITY,INFINITY,INFINITY},
                             {      12,       8,      16,INFINITY,INFINITY,INFINITY},
                             {INFINITY,       4,INFINITY,INFINITY,INFINITY,INFINITY}};

  Kruskal(graph);

  for (int i = 0; i < V_len; i++) {
    for (int j = 0; j < V_len; j++) {
      if (result[i][j] == INFINITY)
        cout << "X" << " ";
      else
        cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
// 寫的鳥爆了
// 有空改
