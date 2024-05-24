#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 三种状态：休息、看书、健身。不允许连续两天健身或者连续两天看书，即对状态转移做出限制
 *      dp[i][s] 表示前 i 天处于状态 s 的最小休息天数。s = {0, 1, 2} 分别表示休息、看书、健身
 *      则有以下状态转移方程：
 *      dp[i][s] = min(dp[i - 1][s]) + 1, s = {0, 1, 2}     if a[i] == 0    健身房图书馆都关闭
 *                 min(dp[i - 1][0], dp[i - 1][])     if a[i] == 1    图书馆开放，健身房关闭
 *                      if a[i] == 2    健身房开放，图书馆关闭
 *                      if a[i] == 3    健身房图书馆都开放
 *
 * @param n
 * @param nums
 * @return int
 */

int solve(int n, const vector<int> &nums) {
  vector<vector<int>> dp(n + 1, vector<int>(3, n));
  dp[0][0] = 0;  // 第 0 天只有休息一种状态

  for (int i = 1; i <= n; ++i) {
    int status = nums[i - 1];

    dp[i][0] = *min_element(dp[i - 1].begin(), dp[i - 1].end()) + 1;  // 休息

    switch (status) {
      case 1:
        // 去图书馆
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        break;

      case 2:
        // 去健身房
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        break;

      case 3:
        // 去图书馆
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        // 去健身房
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        break;

      default:
        break;
    }
  }
  return *min_element(dp[n].begin(), dp[n].end());
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
