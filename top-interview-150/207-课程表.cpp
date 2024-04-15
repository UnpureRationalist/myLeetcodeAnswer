#include "header.h"

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adjList(numCourses);
    vector<int> in_degree(numCourses);

    for (auto &e : prerequisites) {
      adjList[e[1]].push_back(e[0]);
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
      for (auto &neighbor_id : adjList[course_id]) {
        if (--in_degree[neighbor_id] == 0) {
          q.push(neighbor_id);
        }
      }
    }
    return cnt == numCourses;
  }
};
