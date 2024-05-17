#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int rows, cols, target;
  cin >> rows >> cols >> target;
  vector<vector<int>> matrix(rows, vector<int>(cols));
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cin >> matrix[i][j];
    }
  }
  vector<vector<int>> dp(rows, vector<int>(cols, 0));
  dp[0][0] = matrix[0][0];
  if (matrix[0][0] >= target) {
    cout << 0 << endl;
    return 0;
  }
  int ans = rows + cols;
  for (int col = 1; col < cols; ++col) {
    dp[0][col] = dp[0][col - 1] + matrix[0][col];
    if (dp[0][col] >= target) {
      ans = min(ans, col);
    }
  }
  for (int row = 1; row < rows; ++row) {
    dp[row][0] = dp[row - 1][0] + matrix[row][0];
    if (dp[row][0] >= target) {
      ans = min(ans, row);
    }
  }
  for (int row = 1; row < rows; ++row) {
    for (int col = 1; col < cols; ++col) {
      dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]) + matrix[row][col];
      if (dp[row][col] >= target) {
        ans = min(ans, row + col);
      }
    }
  }
  if (dp[rows - 1][cols - 1] < target) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
