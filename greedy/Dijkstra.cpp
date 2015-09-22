// https://zh.wikipedia.org/wiki/%E6%88%B4%E5%85%8B%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95
// 參考wiki虛擬碼
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define INFINITY 9999999 // 假定一個夠大的數是無窮大好了
#define V_LEN 6 // 點數目

int d[V_LEN];
int previous[V_LEN];

void Dijkstra(int G[V_LEN][V_LEN], int s)
{
  for (int i = 0; i < V_LEN; i++)
    d[i] = INFINITY;
  d[s] = 0;
  int V[V_LEN] = {0, 1, 2, 3, 4, 5};
  set<int> Q(V, V+V_LEN);
  
  int min = s;
  while (!Q.empty()) {
    int u = min;
    Q.erase(u);

    for (int i = 0; i < V_LEN; i++) {
      if (d[i] > d[u] + G[u][i]) {
        d[i] = d[u] + G[u][i];
        previous[i] = u;
      }
    }

    min = INFINITY;
    for (set<int>::iterator it = Q.begin(); it != Q.end(); it++) {
      if (min > d[*it])
        min = *it;
    }
  }
}

int main(void)
{
  // 測試圖為wiki裡的圖 不過這邊點從0開始
  int G[V_LEN][V_LEN] = {{       0,        7,        9, INFINITY, INFINITY,       14},
                         {       7,        0,       10,       15, INFINITY, INFINITY},
                         {       9,       10,        0,       11, INFINITY,        2},
                         {INFINITY,       15,       11,        0,        6, INFINITY},
                         {INFINITY, INFINITY, INFINITY,        6,        0,        9},
                         {      14, INFINITY,        2, INFINITY,        9, INFINITY}};

  Dijkstra(G, 0);

  cout << "0 到每點的距離為" << endl;
  for (int i = 0; i < V_LEN; i++)
    cout << i << ":" << d[i] << endl;

  cout << "每個點的上一個點" << endl;
  for (int i = 0; i < V_LEN; i++)
    cout << i << ":" << previous[i] << endl;
  
  return 0;
}

// 本來想用純C寫的
// 不過實在有點醜就算了
// 因為找min的方法頗懶所以變O(n^2)
// 以後研究一下再改寫
