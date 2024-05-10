#include <bits/stdc++.h>
using namespace std;

void dfs(int depth, int n, const vector<int> &nums, const vector<int> &postsum, vector<int> &sum, int &min_differ) {
  if (depth == n) {
    // handle
    if (sum[0] > sum[1] && sum[1] > sum[2] && sum[2] > 0) {
      if (sum[0] - sum[2] < min_differ) {
        min_differ = sum[0] - sum[2];
      }
    }
    return;
  }
  // 剪枝
  if (sum[0] + postsum[depth] <= sum[1] || sum[1] + postsum[depth] <= sum[2]) {
    return;
  }

  // 枚举第 depth 个奖品作为 1 2 3 等奖
  for (int i = 0; i < 3; ++i) {
    sum[i] += nums[depth];
    dfs(depth + 1, n, nums, postsum, sum, min_differ);
    sum[i] -= nums[depth];
  }
}

void solve(int n, const vector<int> &nums) {
  // 后缀和数组 postsum[i] 表示选择 i 及后面所有元素，也即：nums[i: n - 1] 之和
  vector<int> postsum(n, 0);
  postsum[n - 1] = nums[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    postsum[i] = postsum[i + 1] + nums[i];
  }
  vector<int> sums(3, 0);  // 分别表示一二三等奖之和
  int min_differ = INT32_MAX;
  dfs(0, n, nums, postsum, sums, min_differ);
  cout << (min_differ == INT32_MAX ? 0 : min_differ) << endl;
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
