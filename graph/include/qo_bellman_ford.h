#ifndef QO_BELLMAN_FORD_H
#define QO_BELLMAN_FORD_H

#include <vector>
#include <list>

/**
 * 边结构体
 * to: 目标顶点
 * val: 边的权重/代价
 */

struct Edge{
    int to;
    int val;
};

/**
 * 队列优化的贝尔曼-福特算法（SPFA） - 更高效的最短路径算法
 *
 * @param start    源点（起点）编号
 * @param n        图中节点数量
 * @param flag     检测是否存在负权回路，true表示存在
 * @param grid     图的邻接表，grid[i]存储从节点i出发的所有边
 * @param minDist  保存源点到各节点的最短距离
 */

void qo_bellman_ford(int start,
                     int n,
                     bool& flag,
                     std::vector<std::list<Edge>>& grid,
                     std::vector<int>& minDist);

#endif
