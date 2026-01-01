#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>

/**
 * 边结构体
 * u: 起始顶点
 * v: 目标顶点
 * val: 边的权重/代价
 */

struct Edge{
    int u, v, val;
};

/**
 * Kruskal算法 - 寻找最小生成树
 *
 * @param n     图中顶点数量
 * @param res   引用参数，用于返回最小生成树的总权重
 * @param edges 边的集合，包含所有边的信息
 */

void kruskal(int n, int& res, std::vector<Edge>& edges);

#endif
