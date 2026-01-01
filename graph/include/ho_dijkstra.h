#ifndef HO_DIJKSTRA_H
#define HO_DIJKSTRA_H

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
 * 堆优化的迪杰斯特拉算法 - 使用邻接表存储，时间复杂度更低
 *
 * @param start     源点（起点）编号
 * @param isVisited 标记节点是否已确定最短路径
 * @param graph     图的邻接表，graph[i]存储从节点i出发的所有边
 * @param minDist   保存源点到各节点的最短距离
 */

void ho_dijkstra(int start,
                 std::vector<bool>& isVisited,
                 std::vector<std::list<Edge>>& graph,
                 std::vector<int>& minDist);


#endif
