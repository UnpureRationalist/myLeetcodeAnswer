/**
 * @file SPFA.cpp
 * @author your name (you@domain.com)
 * @brief BF 算法的优化版本，称为 SPFA（Shortest Path Faster Algorithm），它的期望时间复杂度是 O(kE)，其中 E
 * 是图的边数，k 是一个常数，在很多情况下 k 不超过 2。
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

// SPFA 算法，返回是否存在从 s 可到达的负环 和 从 s 到所有顶点的最短路径结果。
// 注意：如果负环从源点不可达，则需要添加一个辅助顶点 C，并添加一条从源点 s 到 C 的有向边以及 V - 1 条从 C
// 到达除源点外各顶点的有向边，这样才能判断负环是否存在。
pair<bool, std::vector<int>> SPFA(int s, int n, const vector<vector<Node>> adjList) {
  vector<int> distance(n, 1e9);
  distance[s] = 0;
  vector<char> inq(n, 0);      // 判断某个顶点是否在队列中
  vector<int> inqTimes(n, 0);  // 记录某个顶点的入队次数
  queue<int> q;
  q.push(s);
  inq[s] = 1;       // 标记入队
  inqTimes[s]++;    // 入队次数 + 1
  distance[s] = 0;  // 距离初始化
  while (!q.empty()) {
    int from = q.front();
    q.pop();
    inq[from] = 0;  // 出队
    for (const auto &[target, dis] : adjList[from]) {
      if (distance[from] + dis < distance[target]) {
        distance[target] = distance[from] + dis;
        if (!inq[target]) {  // 必须不在队列中
          q.push(target);
          inq[target] = 1;     // 标记入队
          inqTimes[target]++;  // 增加入队次数
          if (inqTimes[target] >= n) {
            return {false, distance};  // 存在可达负环
          }
        }
      }
    }
  }
  return {true, distance};  // 无可达负环
}

int main() {
  int n = 5;
  int s = 0;
  vector<vector<Node>> adjList;

  SPFA(s, n, adjList);

  return 0;
}
