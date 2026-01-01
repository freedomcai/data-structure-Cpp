#include <iostream>
#include <climits>

#include "qo_bellman_ford.h"

int main()
{
  int n, m;
  int s, t, val;
  std::cin >> n >> m;
  std::vector<std::list<Edge>> grid(n+1);
  while(m--){
    std::cin >> s >> t >> val;
    grid[s].push_back(Edge{t, val});
  }

  int start = 1, end = n;
  std::vector<int> minDist(n+1, INT_MAX);
  minDist[start] = 0;
  bool flag = false;
    
  qo_bellman_ford(start, n, flag, grid, minDist);

  if (flag) std::cout << "circle" << std::endl;
  else if(minDist[end] == INT_MAX) std::cout << "unconnected" << std::endl;
  else std::cout << minDist[end] << std::endl;
}
