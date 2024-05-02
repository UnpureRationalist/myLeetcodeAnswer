#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int rows, cols;
  cin >> rows >> cols;

  vector<vector<int>> matrix(rows + 1, vector<int>(cols + 1, 0));
  vector<vector<long long>> presum(rows + 1, vector<long long>(cols + 1, 0));
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= cols; ++j) {
      cin >> matrix[i][j];
      presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + matrix[i][j];
    }
  }

  long long sum = presum[rows][cols];
  long long half = (sum + 1) / 2;

  long long ans = INT64_MAX;

  auto area_sum = [&presum](int x1, int y1, int x2, int y2) -> long long {
    return presum[x2][y2] - presum[x2][y1 - 1] - presum[x1 - 1][y2] + presum[x1 - 1][y1 - 1];
  };

  // 枚举正方形左上角
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= cols; ++j) {
      // 二分查找正方形的边长
      int left = 1;
      int right = min(rows - i + 1, cols - j + 1);
      // 找到大于等于 half 的最小的边长
      while (left < right) {
        int mid = (left + right) / 2;
        if (area_sum(i, j, i + mid - 1, j + mid - 1) >= half) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      long long temp = area_sum(i, j, i + left - 1, j + left - 1);
      ans = min(ans, abs(temp - (sum - temp)));
      if (left > 1) {
        left -= 1;
        ans = min(ans, abs(sum - 2ll * area_sum(i, j, i + left - 1, j + left - 1)));
      }
    }
  }

  cout << ans << endl;

  return 0;
}
