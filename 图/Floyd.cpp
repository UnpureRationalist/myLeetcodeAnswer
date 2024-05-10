/**
 * @file Floyd.cpp
 * @author your name (you@domain.com)
 * @brief Floyd 算法，用于解决全源最短路径问题，即对于给定图 G(V, E)，求任意两个顶点之间的最短路径长度。时间复杂度为
 * O(V^3)。由于时间复杂度较高，仅适用于顶点数最多几百的情况（300^3 = 27000000，10^7级）。
 * 因为顶点不多，因此适合邻接矩阵存储图结构。
 * @version 0.1
 * @date 2024-05-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> Floyd(int n, const vector<vector<int>> &matrix) {
  vector<vector<int>> dis(n, vector<int>(n, INF));  // 初始化为 10^9
  // dis[i][i] = 0
  for (int i = 0; i < n; ++i) {
    dis[i][i] = 0;
  }
  // 最外层枚举中间节点 k
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dis[i][k] != INF && dis[k][j] != INF && dis[i][k] + dis[k][j] < dis[i][j]) {
          dis[i][j] = dis[i][k] + dis[k][j];
        }
      }
    }
  }
  return dis;
}

int main() {
  int n = 5;
  vector<vector<int>> matrix;

  Floyd(n, matrix);
  return 0;
}
