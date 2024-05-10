/**
 * @file kruskal.cpp
 * @author your name (you@domain.com)
 * @brief 无向图最小生成树问题，Kruskal 算法求解。
 * 核心思想：采用边贪心策略
 *  在初始状态隐去图中的所有边，这样图中每个顶点都自成一个连通块。然后执行下面步骤：
 * 算法步骤：
 *  1. 对所有边按边权从小到大排序
 *  2.
 * 按边权从小达到测试所有边，如果当前测试边连接的两个顶点不在同一个连通块，则把这条测试边加入最小生成树；否则，舍弃这条边
 *  3. 执行步骤 2，直到最小生成树中的边数等于顶点数减 1 或者测试完所有边时结束。
 * @version 0.1
 * @date 2024-05-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <bits/stdc++.h>
using namespace std;

// 需要借助并查集，实现查询节点是否属于不同连通块和合并操作
// 这里的实现代码节点编号为 [1, n]，由于图中采用 [0, n - 1] 编号，因此调用该函数时要传参 i + 1
class UnionFindSet {
 public:
  explicit UnionFindSet(int n) {
    parents.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      parents[i] = i;
    }
  }

  void Union(int a, int b) {
    int pa = Find(a);
    int pb = Find(b);
    if (pa != pb) {
      parents[pa] = pb;
    }
  }

  int Find(int x) {
    if (parents[x] != x) {
      parents[x] = Find(parents[x]);
    }
    return parents[x];
  }

 private:
  vector<int> parents;  // parents[i] 表示 i 的父节点是 parents[i]，只能存储大于等于 0 的有限范围数字
};

struct Edge {
  int u;     // 起点
  int v;     // 终点
  int cost;  // 边权

  bool operator<(const Edge &rop) const { return this->cost < rop.cost; }
};

// 适用于边少的情况，即稀疏图
int kruskal(int n, vector<Edge> &edges) {
  sort(edges.begin(), edges.end());
  int sum = 0;
  int numEdges = 0;
  int m = edges.size();
  UnionFindSet ufs(n);  // 初始化并查集
  for (int i = 0; i < m; ++i) {
    int faU = ufs.Find(edges[i].u + 1);
    int faV = ufs.Find(edges[i].v + 1);
    if (faU != faV) {
      // 合并
      ufs.Union(faU, faV);
      sum += edges[i].cost;
      numEdges++;
      if (numEdges == n - 1) {
        break;  // 连通
      }
    }
  }
  if (numEdges != n - 1) {
    return -1;
  }
  return sum;
}

int main() {
  int n = 5;
  vector<Edge> edges;
  kruskal(5, edges);
  return 0;
}
