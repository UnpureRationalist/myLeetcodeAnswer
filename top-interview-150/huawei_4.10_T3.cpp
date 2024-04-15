#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int calConnectedNum(const vector<vector<int>> &adjMatrix, const vector<int> &exposed, int drop_idx) {
  int n = adjMatrix.size();
  vector<char> visited(n, 0);

  priority_queue<pair<int, int>> q;
  for (auto &exposed_idx : exposed) {
    if (exposed_idx != drop_idx) {
      q.emplace(10, exposed_idx);
      visited[exposed_idx] = 1;
    }
  }
  while (!q.empty()) {
    int q_size = q.size();
    vector<int> next_step_weight(n, -1);
    while (q_size--) {
      auto [weight, idx] = q.top();
      q.pop();
      for (int j = 0; j < n; ++j) {
        if (adjMatrix[idx][j] != 0 && !visited[j] && weight >= adjMatrix[idx][j]) {
          next_step_weight[j] = max(next_step_weight[j], adjMatrix[idx][j]);
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      if (next_step_weight[j] != -1) {
        q.emplace(next_step_weight[j], j);
        visited[j] = 1;
      }
    }
  }
  int ans = 0;
  for (auto &visit : visited) {
    ans += visit != 0;
  }
  return ans;
}

int solve(const vector<vector<int>> &adjMatrix, vector<int> &exposed) {
  int n = adjMatrix.size();
  int connected_num = n + 1;
  int ans_idx = exposed[0];
  sort(exposed.begin(), exposed.end());
  for (auto &drop_idx : exposed) {
    int temp = calConnectedNum(adjMatrix, exposed, drop_idx);
    if (temp < connected_num) {
      ans_idx = drop_idx;
      connected_num = temp;
    }
  }
  return ans_idx;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> adjMatrix[i][j];
    }
  }
  vector<int> exposed;
  int temp_idx;
  while (cin >> temp_idx) {
    exposed.push_back(temp_idx);
  }
  int ans = solve(adjMatrix, exposed);
  cout << ans << endl;
  return 0;
}
