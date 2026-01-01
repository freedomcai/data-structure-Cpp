#include <iostream>
#include <climits>
#include <time.h>
#include "ho_dijkstra.h"

int main()
{
  int n, m;
  int s, t, val;
  std::cin >> n >> m;
  std::vector<std::list<Edge>> graph(n+1);
  while(m--){
    std::cin >> s >> t >> val;
    graph[s].push_back({t, val});
  }

  int start = 1, end = n;
  std::vector<bool> isVisited(end+1, false);
  std::vector<int> minDist(end+1, INT_MAX);
  
  clock_t st, en;
  double cpu_time_used;
  int i = 0;
  st = clock();
  for(;i<1000000;i++) ho_dijkstra(start, isVisited, graph, minDist);
  en = clock();
  cpu_time_used = ((double) (en - st)) / CLOCKS_PER_SEC;
  printf("函数ho_dijkstra(用时: %f 秒\n", cpu_time_used);

  if(minDist[end] == INT_MAX) std::cout << -1 << std::endl;
  else std::cout << minDist[end] << std::endl;
}
