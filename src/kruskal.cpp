#include <algorithm>
#include "kruskal.h"
#include "union-find.h"

void kruskal(int n, int& res, std::vector<Edge>& edges)
{
  std::sort(edges.begin(),edges.end(),[](const Edge& a, const Edge& b){
      return a.val < b.val;
  });

  UnionFind uf(n);
  for(const auto& edge : edges){
    if(!uf.isSame(edge.u, edge.v)){
      uf.join(edge.u, edge.v);
      res += edge.val;
    }
  }
}


