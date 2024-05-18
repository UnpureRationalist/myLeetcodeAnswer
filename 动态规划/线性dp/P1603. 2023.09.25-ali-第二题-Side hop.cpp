#include <bits/stdc++.h>
using namespace std;

void solve(int n, const vector<vector<long long>> &matrix) {
  // 两种走法：
  // 1. 先向右走一步，再向上或向下走两步
  // 2. 先向右走两步，再向上或向下走一步
  // 显然，每次至少向右移动 1 列，因此应该按列从小到大进行枚举递推
  // 最终的结果，就是第 n - 1 列的最大值
  // 先分析边界条件：第 0 列，dp[0][0] = matrix[0][0]，只有这一个可能的位置，其它行都不可能到达
  // 递推条件：第 col 列 第 row 行，有：
  // dp[row][col] = max(dp[row - 2, col - 1], dp[row + 2, col - 1], dp[row - 1, col - 2], dp[row + 1, col - 2]) +
  // matrix[row][col]
  vector<vector<long long>> dp(n, vector<long long>(n, 0));
  dp[0][0] = matrix[0][0];
  long long ans = dp[0][0];
  for (int col = 1; col < n; ++col) {
    for (int row = 0; row < n; ++row) {
      long long max_last = 0;
      if (row - 2 >= 0) {
        max_last = max(max_last, dp[row - 2][col - 1]);
      }
      if (row + 2 < n) {
        max_last = max(max_last, dp[row + 2][col - 1]);
      }
      if (col - 2 >= 0) {
        if (row - 1 >= 0) {
          max_last = max(max_last, dp[row - 1][col - 2]);
        }
        if (row + 1 < n) {
          max_last = max(max_last, dp[row + 1][col - 2]);
        }
      }
      if (max_last != 0) {
        dp[row][col] = max_last + matrix[row][col];
      }
      ans = max(ans, dp[row][col]);
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<long long>> matrix(n, vector<long long>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }
  solve(n, matrix);
  return 0;
}
