#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>

class UnionFind {
private:
  std::vector<int> father;

public:
  UnionFind(int n);

  int find(int u);
  void join(int u, int v);
  bool isSame(int u, int v);

  void reset(int n);
};


#endif


