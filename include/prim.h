#ifndef PRIM_H
#define PRIM_H

#include <vector>

/**
 * 普里姆(Prim)算法实现 - 寻找最小生成树
 *
 * @param n           图中节点数量（节点编号从1到n）
 * @param isInTree    标记节点是否已在最小生成树中，vector<bool>类型
 * @param grid        图的邻接矩阵，grid[i][j]表示节点i到j的边权值
 * @param minDistance 记录各节点到当前生成树的最小距离
 * @param parent      记录各节点在最小生成树中的父节点（用于构建树结构）
 */

void prim(int n, 
          std::vector<bool>& isInTree, 
          std::vector<std::vector<int>>& grid, 
          std::vector<int>& minDistance, 
          std::vector<int>& parent);


#endif
