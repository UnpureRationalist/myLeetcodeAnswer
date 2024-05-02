#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1010;
int rows = 0;
int cols = 0;

void calculatePreSum(const vector<vector<int>> &matrix, vector<vector<int>> &presum) {
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= cols; ++j) {
      presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + matrix[i][j];
    }
  }
}

int getMaxHurt(const vector<vector<int>> &presum, int rowMax, int colMax) {
  int ans = 0;
  for (int i = 1; i <= rows; ++i) {
    for (int j = 1; j <= cols; ++j) {
      int x1 = i, y1 = j;
      int x2 = min(rows, i + rowMax), y2 = min(cols, j + colMax);
      int cnt = presum[x2][y2] - presum[x2][y1 - 1] - presum[x1 - 1][y2] + presum[x1 - 1][y1 - 1];
      ans = max(ans, cnt);
    }
  }
  return ans;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<vector<int>> matrix(MAX, vector<int>(MAX, 0));
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    rows = max(rows, x);
    cols = max(cols, y);
    matrix[x][y] += 1;
  }
  vector<vector<int>> presum(MAX, vector<int>(MAX, 0));
  calculatePreSum(matrix, presum);
  int ans = getMaxHurt(presum, a, b);
  cout << ans << endl;
  return 0;
}
