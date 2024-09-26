#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adjList(numCourses);
    vector<int> indegrees(numCourses, 0);
    for (const auto &elem : prerequisites) {
      const int &cur = elem[0];
      const int &pre = elem[1];
      adjList[pre].push_back(cur);
      indegrees[cur]++;
    }
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < numCourses; ++i) {
      if (indegrees[i] == 0) {
        ++cnt;
        q.emplace(i);
      }
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (const auto &next : adjList[cur]) {
        indegrees[next]--;
        if (indegrees[next] == 0) {
          ++cnt;
          q.emplace(next);
        }
      }
    }
    return cnt == numCourses;
  }
};
