#include <bits/stdc++.h>
using namespace std;

// 计算攻击每个怪物，失败次数为 j 的概率
vector<vector<double>> getLoseProbability(int n, const vector<double> &nums) {
  vector<vector<double>> ans(n, vector<double>(4, 0.0));
  for (int i = 0; i < n; ++i) {
    double num = nums[i];
    ans[i][0] = 1.0 - num;
    ans[i][1] = num * (1.0 - num);
    ans[i][2] = num * num * (1.0 - num);
    ans[i][3] = 1.0 - ans[i][0] - ans[i][1] - ans[i][2];
  }
  return ans;
}

void solve(int n, const vector<double> &nums) {
  auto lose_times = getLoseProbability(n, nums);
  vector<vector<double>> dp(n + 1, vector<double>(3 * n + 4, 0.0));  // dp[i][j] 为攻击前 i 个怪物，失败次数为 j 的概率
  // init
  dp[0][0] = 1.0;
  // dp
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i * 3; ++j) {
      for (int k = 0; k <= 3; ++k) {
        dp[i][j + k] += dp[i - 1][j] * lose_times[i - 1][k];
      }
    }
  }

  // calculate expectation
  double res = 0.0;
  for (int i = 0; i <= 3 * n; ++i) {
    res += dp[n][i] * (i / 3);
  }
  cout << fixed << setprecision(6) << res << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<double> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  solve(n, nums);
  return 0;
}
