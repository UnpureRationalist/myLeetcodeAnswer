#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adjList(numCourses);
    vector<int> indegree(numCourses, 0);
    for (const auto elem : prerequisites) {
      int pre = elem[1];
      int cur = elem[0];
      adjList[pre].push_back(cur);
      indegree[cur]++;
    }
    queue<int> q;
    int count = 0;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        q.emplace(i);
      }
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      ++count;
      for (const auto &target : adjList[cur]) {
        indegree[target]--;
        if (indegree[target] == 0) {
          q.emplace(target);
        }
      }
    }
    return count == numCourses;
  }
};
