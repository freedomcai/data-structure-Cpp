#include <climits>
#include "bellman_ford.h"

void bellman_ford(int n,
                  bool& flag,
                  std::vector<std::vector<int>>& grid,
                  std::vector<int>& minDist)
{
  // 对所有边松弛 n 次
  for(int i = 1;i <= n;i++){
    for(std::vector<int> cur : grid){
      int from = cur[0];
      int to = cur[1];
      int price = cur[2];
      // 松弛
      if(i < n){
        if(minDist[from] != INT_MAX && 
          minDist[to] > minDist[from] + price){
              minDist[to] = minDist[from] + price;
        }
      } else {
        if(minDist[from] != INT_MAX && 
          minDist[to] > minDist[from] + price){
            flag = true;
        }
      }
    }
  }
}

