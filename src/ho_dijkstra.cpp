#include <climits>
#include <queue>  // priority_queue 在这个头文件中
#include "ho_dijkstra.h"

void ho_dijkstra(int start,
                 std::vector<bool>& isVisited,
                 std::vector<std::list<Edge>>& graph,
                 std::vector<int>& minDist)
{
  auto cmp = [](const std::pair<int, int>& left, 
    const std::pair<int, int>&right) {
        return left.second > right.second; 
  }; // 最小堆
  
  // pair<int, int> 第一个int:节点编号 第二个int:该节点到源点的距离
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> que(cmp);

  que.push(std::pair<int, int>(start, 0));
  minDist[start] = 0;

  while(!que.empty()){
    // 离源点最近且未访问过的节点
    std::pair<int, int> tmp = que.top();que.pop();
    int cur = tmp.first;

    // 标记该点访问过
    isVisited[cur] = true;
    // 更新未访问节点到源点的距离
    for(Edge edge : graph[cur]){
      if(!isVisited[edge.to] && minDist[cur] + edge.val < minDist[edge.to]){
        minDist[edge.to] = minDist[cur] + edge.val;
        que.push(std::pair<int, int>(edge.to, minDist[edge.to]));
      }
    }
  }
}
