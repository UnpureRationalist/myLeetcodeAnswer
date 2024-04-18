#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Problem {
  int general{0};
  int serious{0};
};

void search(Problem &result, const string &cur, unordered_set<string> visited,
            unordered_map<string, Problem> &node2info, unordered_map<string, unordered_set<string>> &adjList) {
  for (auto &target : adjList[cur]) {
    if (visited.find(target) == visited.end()) {
      visited.insert(target);
      result.serious += node2info[target].serious;
      result.general += node2info[target].general;
      search(result, target, visited, node2info, adjList);
    }
  }
}

void solve(int m, const unordered_set<string> &roots, unordered_map<string, Problem> &node2info,
           unordered_map<string, unordered_set<string>> &adjList) {
  int ans = 0;
  for (auto &root : roots) {
    Problem temp = node2info[root];
    unordered_set<string> visited;
    visited.insert(root);
    search(temp, root, visited, node2info, adjList);
    int total = 5 * temp.serious + 2 * temp.general;
    if (total > m) {
      ++ans;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int m;
  int n;
  cin >> m >> n;

  unordered_set<string> roots;
  unordered_map<string, Problem> node2info;
  unordered_map<string, unordered_set<string>> adjList;

  for (int i = 0; i < n; ++i) {
    string node_name;
    string father_node;
    cin >> node_name >> father_node;
    int problem_type;
    int problem_num;
    cin >> problem_type >> problem_num;

    if (problem_type == 0) {
      node2info[node_name].serious += problem_num;
    } else {
      node2info[node_name].general += problem_num;
    }

    if (father_node != "*") {
      adjList[father_node].insert(node_name);
    } else {
      roots.insert(node_name);
    }
  }

  solve(m, roots, node2info, adjList);

  return 0;
}