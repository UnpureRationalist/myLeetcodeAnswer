/**
 * @file prim.cpp
 * @author your name (you@domain.com)
 * @brief 无向图最小生成树问题，Prim 算法求解。
 *
 * 核心思想：
 * 对图 G(V, E) 设置集合 S，存放已被访问顶点。然后每次从集合 V - S 中选择与集合 S 的最短距离最小的一个顶点，记作
 * u，访问并加入集合 S。之后，令 u 为中介点，优化所有从 u 能到达的顶点 v 与集合 s 之间的最短距离。这样执行 n 次（n
 * 为顶点个数），直到集合 S 包含所有顶点。
 * @version 0.1
 * @date 2024-05-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// 时间复杂度：O(V^2) 适用于图的顶点数较少而边较多的情况，即稠密图
int prim(int n, const vector<vector<int>> &matrix) {
  vector<char> visited(n, 0);
  vector<int> dis(n, INF);  // 初始化为 INF
  // 选择节点 0 作为已访问集合 S 的首个元素
  dis[0] = 0;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    // 找到未访问节点中距离最小的
    int min_dis = INF;
    int u = -1;
    for (int j = 0; j < n; ++j) {
      if (!visited[j] && dis[j] < min_dis) {
        min_dis = dis[j];
        u = j;
      }
    }
    if (u == -1) {
      return -1;  // 不连通
    }
    visited[u] = 1;  // 加入集合 S
    sum += dis[u];   // 累加边权
    // 更新 S 到 V - S 最短距离
    for (int v = 0; v < n; ++v) {
      if (!visited[v] && matrix[u][v] != INF && matrix[u][v] < dis[v]) {
        dis[v] = matrix[u][v];  // 此处与 dijkstra 不同，因为 dis[v] 表示的是集合 S 到 v 的边权
      }
    }
  }
  return sum;
}

int main() {
  int n = 5;
  vector<vector<int>> matrix;
  prim(n, matrix);
  return 0;
}
