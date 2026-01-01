#include <climits>
#include "dijkstra.h"

void dijkstra(int start,
              int end,
              std::vector<bool>& isVisited,
              std::vector<std::vector<int>>& graph,
              std::vector<int>& minDist)
{
  minDist[start] = 0;
  for(int i = 1;i <= end;i++){
    int minval = INT_MAX;
    int cur = 0;
    int j;
    // 离原点最近且未访问过的节点
    for(j = 1;j <= end;j++){
      if(!isVisited[j] && minDist[j] < minval){
        minval = minDist[j];
        cur = j;
      }
    }

    // 标记该点访问过
    isVisited[cur] = true;

    // 更新未访问节点到源点的距离
    for(j = 1;j <= end;j++){
      // 未访问过 && 与cur连接 && j到源点距离可以更小（更新最小值）
      if(!isVisited[j] && graph[cur][j] != INT_MAX && 
      minDist[cur] + graph[cur][j] < minDist[j]){
        minDist[j] = minDist[cur] + graph[cur][j];
      }
    }
  }

}
