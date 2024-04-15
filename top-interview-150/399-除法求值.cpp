#include "header.h"

class Solution {
 private:
  struct EdgeStatus {
    double value;
    string target;
  };

  unordered_set<string> vertexs;
  unordered_map<string, vector<EdgeStatus>> adjList;

  void addVertex(string vertex) { vertexs.emplace(std::move(vertex)); }

  void addEdge(vector<string> &equation, double value) {
    adjList[equation[0]].emplace_back(value, equation[1]);
    if (value != 0.0) {
      adjList[equation[1]].emplace_back(1 / value, equation[0]);
    }
  }

  void buildGraph(vector<vector<string>> &equations, vector<double> &values) {
    int n = equations.size();
    for (int i = 0; i < n; ++i) {
      vector<string> &equation = equations[i];
      for (auto &vertex : equation) {
        addVertex(vertex);
      }
      addEdge(equation, values[i]);
    }
  }

  pair<bool, double> dfs(string &start, string &end, unordered_set<string> &visited, double ans) {
    if (start == end) {
      return {true, ans};
    }
    for (auto &edge : adjList[start]) {
      if (visited.find(edge.target) == visited.end()) {
        visited.insert(edge.target);
        auto [found, result] = dfs(edge.target, end, visited, ans * edge.value);
        if (found) {
          return {true, result};
        }
      }
    }
    return {false, -1.0};
  }

  double calculate(vector<string> &query) {
    auto &start = query[0];
    auto &end = query[1];
    if (vertexs.find(start) == vertexs.end() || vertexs.find(end) == vertexs.end()) {
      return -1.0;
    }
    if (start == end) {
      return 1.0;
    }
    unordered_set<string> visited;
    visited.insert(start);
    auto [found, ans] = dfs(start, end, visited, 1.0);
    return found ? ans : -1.0;
  }

 public:
  vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values,
                              vector<vector<string>> &queries) {
    buildGraph(equations, values);
    vector<double> ans;
    ans.reserve(queries.size());
    for (auto &query : queries) {
      ans.emplace_back(calculate(query));
    }
    return ans;
  }
};
