#include <bits/stdc++.h>
using namespace std;

void dfs(int depth, int n, const vector<int> &nums, vector<char> &selected, vector<int> &weights, long long sum) {
  if (depth == n) {
    if (sum >= 0) {
      for (int i = 0; i < n; ++i) {
        if (selected[i]) {
          weights[i]++;
        }
      }
    }
    return;
  }
  // 选
  selected[depth] = 1;
  dfs(depth + 1, n, nums, selected, weights, sum + nums[depth]);
  selected[depth] = 0;
  // 不选
  dfs(depth + 1, n, nums, selected, weights, sum);
}

void solve(int n, const vector<int> &nums) {
  vector<char> slected(n, 0);
  vector<int> weights(n, 0);
  dfs(0, n, nums, slected, weights, 0);
  cout << accumulate(weights.begin(), weights.end(), 0ll) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  solve(n, nums);
  return 0;
}
