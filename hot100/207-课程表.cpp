#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  unordered_map<int, vector<int>> mp;
  unordered_map<int, int> in_degrees;

  void buildGraph(const vector<vector<int>> &prerequisites) {
    for (const auto &courses : prerequisites) {
      auto &course_id = courses[0];
      auto &pre_req = courses[1];
      mp[pre_req].emplace_back(course_id);
      in_degrees[course_id]++;
    }
  }

 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    buildGraph(prerequisites);

    // init
    std::vector<pair<int, int>> q(numCourses, make_pair(0, 0));  // 队列每个元素表示 <入度, 节点 id>
    for (int i = 0; i < numCourses; ++i) {
      q[i].first = in_degrees[i];
      q[i].second = i;
    }

    for (int i = 0; i < numCourses; ++i) {
      make_heap(q.begin() + i, q.end(), std::greater<pair<int, int>>());
      int in_degree = q[i].first;
      int id = q[i].second;
      if (in_degree > 0) {
        return false;
      }
      // 删除以 id 为起点的边 重新计算各节点入度
      for (auto &end_id : mp[id]) {
        int idx =
            find_if(q.begin() + i, q.end(), [end_id](const pair<int, int> &elem) { return elem.second == end_id; }) -
            q.begin();
        if (idx != numCourses) {
          q[idx].first--;
        }
      }
    }
    return true;
  }
};

class Solution {
 private:
  vector<vector<int>> edges;
  vector<int> visited;
  bool valid = true;

 public:
  void dfs(int u) {
    visited[u] = 1;
    for (int v : edges[u]) {
      if (visited[v] == 0) {
        dfs(v);
        if (!valid) {
          return;
        }
      } else if (visited[v] == 1) {
        valid = false;
        return;
      }
    }
    visited[u] = 2;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    edges.resize(numCourses);
    visited.resize(numCourses);
    for (const auto &info : prerequisites) {
      edges[info[1]].push_back(info[0]);
    }
    for (int i = 0; i < numCourses && valid; ++i) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    return valid;
  }
};

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> edges(numCourses);
    vector<int> in_degree(numCourses);

    for (auto &e : prerequisites) {
      edges[e[1]].push_back(e[0]);
      in_degree[e[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (in_degree[i] == 0) {
        q.push(i);
      }
    }

    int cnt = 0;
    while (!q.empty()) {
      int course_id = q.front();
      q.pop();
      cnt++;
      for (auto &neighbor_id : edges[course_id]) {
        if (--in_degree[neighbor_id] == 0) {
          q.push(neighbor_id);
        }
      }
    }
    return cnt == numCourses;
  }
};
