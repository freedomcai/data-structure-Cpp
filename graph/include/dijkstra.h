#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>

/**
 * 迪杰斯特拉(Dijkstra)算法 - 计算单源最短路径
 *
 * @param start     源点（起点）编号
 * @param end       目标点（终点）编号
 * @param isVisited 标记节点是否已确定最短路径
 * @param graph     图的邻接矩阵，graph[i][j]表示i到j的边权
 * @param minDist   保存源点到各节点的最短距离
 */

void dijkstra(int start,
              int end,
              std::vector<bool>& isVisited,
              std::vector<std::vector<int>>& graph,
              std::vector<int>& minDist);


#endif
