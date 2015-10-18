// 寫超爛的 還要在補幾種寫法 待修改
#include <iostream>
#include <algorithm>
using namespace std;
#define Limit 8
#define Amount 5

struct item{
  int weight;
  int price;
};
typedef struct item item;

// 很容易看出來是不選{2,1}
item choose[Amount] = {{1,2},{3,4},{2,1},{1,3},{2,6}};
int limit = 8, weight = 0;

int slove(int limit, int weight, int now)
{
  if (now == Amount)
    return weight;

  if (limit-choose[now].weight < 0)
    return slove(limit, weight, now+1);
  else
    return max(slove(limit, weight, now+1), slove(limit-choose[now].weight, weight+choose[now].price, now+1));
}

int main(void)
{

  cout << slove(limit, weight, 0) << endl;

  return 0;
}
