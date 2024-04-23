#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int n, m, s;                   // 顶点数 边数 起点
vector<map<int, int>> matrix;  // 邻接表  注意： map 内 key->index  value->edgeWeight

struct Edge {
  int index = 0, weight = INT_MAX;  // 顶点编号、从起点到达该顶点最小路径长度

  Edge() {}

  Edge(int i, int w) : index(i), weight(w) {}

  bool operator<(const Edge &rop) const {
    return weight > rop.weight;  // 注意：STL 优先队列先弹出元素大的 此处需要将距离小的先弹出 故如此定义
  }
};

vector<int> dijkstra(int start)  // 从 start 开始，求到达所在连通子图各个顶点的最小距离
{
  vector<int> dis(n, INT_MAX);     // 保存最短路径长度 初始化为 INT_MAX
  vector<bool> visited(n, false);  // 标记节点是否访问过

  dis[start] = 0;
  priority_queue<Edge> q;  // 优先队列优化
  q.push(Edge(start, 0));  // 初始化队列、dis数组

  while (!q.empty()) {
    Edge vert = q.top();
    q.pop();
    int cur_idx = vert.index;
    if (visited[cur_idx]) continue;  // 若节点已访问 continue
    visited[cur_idx] = true;         // 标记已访问

    // 更新 dis 数组
    for (auto &elem : matrix[cur_idx]) {
      int target_idx = elem.first, weight = elem.second;
      if (!visited[target_idx] && dis[cur_idx] + weight < dis[target_idx]) {
        dis[target_idx] = dis[cur_idx] + matrix[cur_idx][target_idx];
        q.push(Edge(target_idx, dis[target_idx]));
      }
    }
  }
  return dis;
}

int main() {
  cin >> n >> m >> s;
  matrix.resize(n);

  int start, end, weight;  // 有向图 边的起点 重点 权重
  while (m--) {
    cin >> start >> end >> weight;
    if (start == end) continue;
    if (matrix[start - 1].find(end - 1) == matrix[start - 1].end())
      matrix[start - 1][end - 1] = weight;
    else
      matrix[start - 1][end - 1] = min(weight, matrix[start - 1][end - 1]);
  }
  vector<int> dis = dijkstra(s - 1);
  for (auto &e : dis) cout << e << " ";
  cout << endl;
  return 0;
}