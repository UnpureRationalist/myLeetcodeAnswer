#include <bits/stdc++.h>
using namespace std;

int solve(int n, const vector<int> &nums) {
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2 != 0) {
    return 0;
  }
  int target = sum / 2;
  vector<int> dp(target + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = target; j >= nums[i - 1]; --j) {
      dp[j] += dp[j - nums[i - 1]];
    }
  }
  return dp[target];
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  cout << solve(n, nums) << endl;
  return 0;
}
