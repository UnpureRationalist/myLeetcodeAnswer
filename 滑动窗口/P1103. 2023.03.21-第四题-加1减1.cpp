#include <bits/stdc++.h>
using namespace std;

int solve(const vector<int> &nums, int n, int k) {
  int ans = INT32_MAX;
  vector<int> ops(10, 0);
  for (int l = 0, r = 0; r < n; ++r) {
    for (int i = 0; i < 10; ++i) {
      ops[i] += abs(i - nums[r]);
    }
    if (r >= k - 1) {
      for (const auto &op : ops) {
        ans = min(ans, op);
      }
    }
    if ((r - l + 1) == k) {
      for (int i = 0; i < 10; ++i) {
        ops[i] -= abs(i - nums[l]);
      }
      ++l;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  int k;
  cin >> n >> k;

  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  int ans = solve(nums, n, k);
  cout << ans << endl;
  return 0;
}
