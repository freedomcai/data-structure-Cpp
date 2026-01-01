#include <queue>

#include "qo_bellman_ford.h"

void qo_bellman_ford(int start,
                     int n,
                     bool& flag,
                     std::vector<std::list<Edge>>& grid,
                     std::vector<int>& minDist)
{
  // 加入优化，已经在队里里的元素不用重添加
  std::vector<bool> isInQueue(n + 1, false); 
  std::queue<int> que;

  que.push(start);
  isInQueue[start] = true;

  std::vector<int> count(n+1, 0); // 记录节点加入队列几次
  count[start]++;


  // 对所有边松弛 n-1 次
  while(!que.empty()){
    int cur = que.front();que.pop();
    isInQueue[cur] = false;
     
    for(Edge& edge : grid[cur]){
      int from = cur;
      int to = edge.to;
      int price = edge.val;
      // 松弛
      if(minDist[to] > minDist[from] + price){
        minDist[to] = minDist[from] + price;
        if(!isInQueue[to]){
          que.push(to);
          isInQueue[to] = true;
          count[to]++; 
          if (count[to] == n) {
            // 如果加入队列次数超过 n-1次 就说明该图与负权回路
            flag = true;
            while (!que.empty()) que.pop();
            break;
          }
        }
      }
    }
  }
}
