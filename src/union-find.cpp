#include "union-find.h"

UnionFind::UnionFind(int n)
{
  father.resize(n); 
  for (int i = 0; i < n; i++)
  {
    father[i] = i;
  }
}

int UnionFind::find(int u)
{
  if (u == father[u]) return u;
  father[u] = find(father[u]);
  return father[u];
}

void UnionFind::join(int u, int v)
{
  u = find(u);
  v = find(v);
  if (u == v) return;
  father[v] = u;
}

bool UnionFind::isSame(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return true;
	else return false;
}

void UnionFind::reset(int n)
{
  father.resize(n); 
  for (int i = 0; i < n; i++)
  {
    father[i] = i;
  }
}
