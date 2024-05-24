#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 每名医生可以安排 [0, 4] 个机器人，效率变化分别为：[-0.2, 0, 0.1, 0.2, 0.3]
 *      dp[i][j] 表示前 i 个医生共安排 j 个机器人的最高总效率
 *
 * @param n
 * @param k
 * @param nums
 * @return int
 */

int solve(int n, int k, const vector<int> &nums) {
  int ans = 0;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  vector<double> rates{0.8, 1.0, 1.1, 1.2, 1.3};
  for (int i = 1; i <= n; ++i) {
    int num = nums[i - 1];
    for (int j = 0; j <= k; ++j) {
      for (int robot = min(j, 4); robot >= 0; --robot) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - robot] + static_cast<int>(num * rates[robot]));
      }
      ans = max(ans, dp[i][j]);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  cout << solve(n, k, nums) << endl;
  return 0;
}
