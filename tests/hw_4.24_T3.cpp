#include <bits/stdc++.h>
using namespace std;

struct ServiceGroup {
  int id{0};
  int num_nodes{0};
  int access_nodes{0};
  int h{0};
  int max_idx{0};

  bool operator<(const ServiceGroup &rop) const {
    if (this->h != rop.h) {
      return this->h > rop.h;
    }
    return this->max_idx > rop.max_idx;
  }

  void show() const {
    cout << "id: " << id << " num_nodes: " << num_nodes << " access: " << access_nodes << " h: " << h
         << " max_idx: " << max_idx << endl;
  }
};

bool isCircle(int start, int cur, const vector<int> &edges, vector<char> &visited, vector<int> &path) {
  if (visited[cur]) {
    return false;
  }

  visited[cur] = 1;
  path.push_back(cur);

  int next_idx = edges[cur];
  if (next_idx == start) {
    return true;
  }
  return isCircle(start, next_idx, edges, visited, path);
}

int accessNodes(const vector<int> &circle_lst, int n, const vector<unordered_set<int>> &revEdges) {
  vector<char> visited(n, 0);
  for (auto &id : circle_lst) {
    visited[id] = 1;
  }
  unordered_set<int> accessible_lst;
  queue<int> father_lst;
  // init from circle_lst
  for (auto &id : circle_lst) {
    for (auto &from_id : revEdges[id]) {
      if (!visited[from_id]) {
        visited[from_id] = 1;
        father_lst.push(from_id);
        accessible_lst.insert(from_id);
      }
    }
  }
  // search
  while (!father_lst.empty()) {
    int id = father_lst.front();
    father_lst.pop();
    for (auto &from_id : revEdges[id]) {
      if (!visited[from_id]) {
        father_lst.push(from_id);
        visited[from_id] = true;
        accessible_lst.insert(from_id);
      }
    }
  }
  return accessible_lst.size();
}

ServiceGroup list2Info(int id, const vector<int> &circle_lst, int n, const vector<unordered_set<int>> &edges) {
  ServiceGroup result;
  result.id = id;
  result.max_idx = *max_element(circle_lst.begin(), circle_lst.end());
  result.num_nodes = circle_lst.size();
  // 获取所有能够访问到 circle_lst 集群 的节点数量
  result.access_nodes = accessNodes(circle_lst, n, edges);
  result.h = result.num_nodes - result.access_nodes;
  return result;
}

vector<unordered_set<int>> reverseEdgesFunc(const vector<int> &edges, int n) {
  // 返回 reverseEdges, reverseEdges[i] 表示有哪些边能到达 i
  vector<unordered_set<int>> reverseEdges(n);
  for (int i = 0; i < edges.size(); ++i) {
    reverseEdges[edges[i]].insert(i);
  }
  return reverseEdges;
}

// edges[i]表示存在一条从微服务i到微服务 edges[i]的接口调用
void solve(int n, const vector<int> &edges) {
  // 1. 找到所有的环（微服务群组）
  vector<vector<int>> circles;
  vector<char> visited(n, 0);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      vector<int> path;
      bool inCircle = isCircle(i, i, edges, visited, path);
      if (inCircle) {
        circles.emplace_back(path);
      } else {
        for (auto &id : path) {
          visited[id] = 0;
        }
      }
    }
  }

//   for (auto &circle_lst : circles) {
//     cout << "circle: ";
//     for (auto &id : circle_lst) {
//       cout << id << " ";
//     }
//     cout << endl;
//   }

  int num_of_circles = circles.size();
  vector<ServiceGroup> services(num_of_circles);

  vector<unordered_set<int>> reverseEdges = reverseEdgesFunc(edges, n);

  for (int i = 0; i < num_of_circles; ++i) {
    services[i] = list2Info(i, circles[i], n, reverseEdges);
  }
  sort(services.begin(), services.end());
//   for (auto &serv : services) {
//     serv.show();
//   }
  auto &circle_lst = circles[services[0].id];
  for (int i = 0; i < circle_lst.size(); ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << circle_lst[i];
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> edges;
  int temp;
  while (cin >> temp) {
    edges.emplace_back(temp);
  }
  // 验证 edges 是否满足 edges[i] != i
//   for (int i = 0; i < edges.size(); ++i) {
//     if (i == edges[i]) {
//       std::cout << "error in idx: " << i << endl;
//     }
//   }
  solve(n, edges);
  return 0;
}
