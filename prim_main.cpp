#include <iostream>
#include <climits>
#include <vector>
#include "prim.h"

int main()
{
  int n, m;
  int s, t, val;
  int res = 0;
  std::cin >> n >> m;
  std::vector<std::vector<int>> grid(n+1, std::vector<int>(n+1, INT_MAX));
  while(m--)
  {
    std::cin >> s >> t >>val;
    grid[s][t] = val;
    grid[t][s] = val;
  }
  std::vector<bool> isInTree(n+1, false);
  std::vector<int> minDistance(n+1, INT_MAX);
  std::vector<int> parent(n+1, -1);
  
  prim(n, isInTree, grid, minDistance, parent);

  for(int j = 2;j <= n;j++){
    res += minDistance[j];
  }

  std::cout << res << std::endl;

  // 输出 最小生成树边的连接情况
  for (int i = 1; i <= n; i++) {
    std::cout << i << "->" << parent[i] << std::endl;
  }
}


