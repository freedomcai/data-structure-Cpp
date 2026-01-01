#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H

#include <vector>

/**
 * 贝尔曼-福特(Bellman-Ford)算法 - 计算单源最短路径，可处理负权边
 *
 * @param n        图中节点数量
 * @param flag     检测是否存在负权回路，true表示存在
 * @param grid     图的邻接矩阵，grid[i][j]表示i到j的边权
 * @param minDist  保存源点到各节点的最短距离
 */

void bellman_ford(int n,
                  bool& flag,
                  std::vector<std::vector<int>>& grid,
                  std::vector<int>& minDist);

#endif
