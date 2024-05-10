/**
 * @file bellman-ford.cpp
 * @author your name (you@domain.com)
 * @brief Dijkstra 算法只能解决无负边权图的单源最短路径问题。如果边的权重存在负数，就要用 Bellman-Ford 算法，简称 BF
 * 算法。
 *
 * BF 算法和 Dijkstra 类似，设置一个数组 d 用于存放从起点到各个顶点的最短距离。同时，BF 算法返回一个 bool
 * 值：如果存在从远点可达的负环，那么函数返回 false；否则函数返回 true，此时数组 d
 * 中存放的值就是从源点到达各顶点的最短距离。
 *
 * BF 算法时间复杂度为 O(VE)，其中 V 为顶点数，E 为边数。由于 BF
 * 算法需要遍历所有边，推荐使用邻接表存储图结构。如果使用邻接矩阵，时间复杂度会上升到 O(V^3)。
 * @version 0.1
 * @date 2024-05-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int target;
  int dis;
};

// BF 算法，返回是否存在负环 和 从 s 到所有顶点的最短路径结果
pair<bool, std::vector<int>> bellman(int s, int n, const vector<vector<Node>> adjList) {
  vector<int> distance(n, 1e9);
  distance[s] = 0;
  // 循环遍历边 n - 1 次，求解数组 distance
  for (int i = 0; i < n - 1; ++i) {
    for (int from = 0; from < n; ++from) {
      bool update = false;
      for (auto &[target, dis] : adjList[from]) {
        if (distance[from] + dis < distance[target]) {
          update = true;
          distance[target] = distance[from] + dis;
        }
      }
      if (!update) {
        break;  // 如果一轮循环中，边没有更新，说明已经达到了最短路径，可以提前退出
      }
    }
  }
  // 判断是否存在负环
  for (int from = 0; from < n; ++from) {
    for (auto &[target, dis] : adjList[from]) {
      if (distance[from] + dis < distance[target]) {
        return {false, distance};
      }
    }
  }
  return {true, distance};
}

int main() {
  int n = 5;
  int s = 0;
  vector<vector<Node>> adjList;

  bellman(s, n, adjList);

  return 0;
}
