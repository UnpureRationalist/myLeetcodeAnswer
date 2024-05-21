#include <bits/stdc++.h>
using namespace std;

int solve(int n, const vector<int> &nums) {
  vector<int> dp(n + 1, n + 1);
  dp[0] = 0;
  for (const auto &num : nums) {
    for (int j = num; j <= n; ++j) {
      dp[j] = min(dp[j], dp[j - num] + 1);
    }
  }
  return (dp[n] == (n + 1)) ? -1 : dp[n];
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums;
  int num;
  while (cin >> num) {
    nums.emplace_back(num);
  }
  cout << solve(n, nums) << endl;
  return 0;
}
