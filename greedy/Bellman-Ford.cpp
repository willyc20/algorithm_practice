// 先上wiki:https://zh.wikipedia.org/wiki/%E8%B4%9D%E5%B0%94%E6%9B%BC-%E7%A6%8F%E7%89%B9%E7%AE%97%E6%B3%95
// 
// 看很多都寫啥鬆弛操作之類的，搞一堆術語我覺得加深理解難度，
// 其實這方法的概念很簡單，兩點間最多就經過所有點減一數量的邊，
// 所以把初始的最短權重路徑比較|V|-1次，就會是解答。
#include <iostream>
using namespace std;
#define INFINITY 9999999 // 假定一個夠大的數是無窮大
#define V_LEN 4

int d[V_LEN];
int previous[V_LEN];

void Bellman(int G[V_LEN][V_LEN], int s)
{
  for (int i = 0; i < V_LEN; i++)
    d[i] = INFINITY;
  d[s] = 0;

  for (int i = 0; i < V_LEN; i++) {
    for (int j = 0; j < V_LEN; j++) {
      if (d[i] + G[i][j] < d[j]) {
        d[j] = d[i] + G[i][j];
        previous[j] = i;
      }
    }
  }

  // 如果最佳路徑權重是負的，那代表可以一直繞下去變無限小
  for (int i = 0; i < V_LEN; i++)
    if (d[i] < 0)
      d[i] = -INFINITY;
}

int main(void)
{
  // wiki裡的樣例圖 這裡v1從0開始
  // V={v1,v2,v3,v4} E={(v1,v2),(v1,v3),(v2,v4),(v4,v3)} 
  // weight(v1,v2)=-1 weight(v1,v3)=3 weight(v2,v4)=3 weight(v4,v3)=-1
  int graph[V_LEN][V_LEN] = {{INFINITY, -1      ,        3, INFINITY},
                             {      -1, INFINITY, INFINITY, INFINITY},
                             {       3, INFINITY, INFINITY,       -1},
                             {INFINITY, INFINITY,       -1, INFINITY}};
  int s = 0;
  Bellman(graph, s);

  for (int i = 0; i < V_LEN; i++) {
    if (d[i] == -INFINITY)
      cout << s << "到" << i << "點為負環" << endl;
    else
      cout << s << "到" << i << "點的距離為" << d[i] << endl;

    cout << i << "的上一點為" << previous[i] << endl;
    cout << endl;
  }

  return 0;
}
// 蠻沒效率的實作
// 單純表達Bellman的重點
