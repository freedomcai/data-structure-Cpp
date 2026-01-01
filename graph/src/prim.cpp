#include <climits>
#include "prim.h"

void prim(int n, 
          std::vector<bool>& isInTree, 
          std::vector<std::vector<int>>& grid, 
          std::vector<int>& minDistance, 
          std::vector<int>& parent)
{
  for(int i = 1;i < n;i++){
    int minVal = INT_MAX;
    int cur = 1;
    int j;
    // 非生成树距离生成树的最近节点
    for(j = 1;j <= n;j++){
      if(isInTree[j] == false && minDistance[j] < minVal){
         minVal = minDistance[j];
         cur = j;
      }
    }

    // 加入生成树
    isInTree[cur] = true;

    // 更新所有非生成树节点到生成树的距离（最小）
    for(j = 1;j <= n;j++){
      // 非生成树 && cur连接 && 权值更小
      if(isInTree[j] == false && grid[cur][j] < minDistance[j]){
          minDistance[j] = grid[cur][j];
          parent[j] = cur;
      }
    }
  }
}
