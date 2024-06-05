#include <bits/stdc++.h>
using namespace std;

vector<int> getColContinus(int rows, int col, const vector<string> &matrix) {
  vector<int> ans;
  int count = 0;
  for (int row = 0; row < rows; ++row) {
    if (matrix[row][col] == 'o') {
      ++count;
    } else {
      if (count >= 2) {
        ans.push_back(count);
      }
      count = 0;
    }
  }
  if (count >= 2) {
    ans.push_back(count);
  }
  return ans;
}

int solve(int rows, int cols, int k, vector<string> &matrix) {
  vector<int> nums;
  for (int col = 0; col < cols; ++col) {
    auto colCounter = getColContinus(rows, col, matrix);
    for (auto &num : colCounter) {
      nums.emplace_back(num);  // num 个连续格子中，上面的 num - 1 个格子是优美格子
    }
  }
  int sum = accumulate(nums.begin(), nums.end(), 0);  // 格子总数
  int n = nums.size();
  if (k >= sum) {
    return sum - n;
  }
  // k < sum，则应该优先在连续格子数多的位置涂色
  sort(nums.begin(), nums.end(), greater<int>());
  int ans = 0;
  for (int i = 0; i < n && k >= 2; ++i) {
    if (nums[i] > k) {
      ans += k - 1;
      k = 0;
    } else {
      ans += nums[i] - 1;
      k -= nums[i];
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int rows, cols, k;
  cin >> rows >> cols >> k;
  vector<string> matrix(rows);
  for (auto &str : matrix) {
    cin >> str;
  }
  cout << solve(rows, cols, k, matrix) << endl;
  return 0;
}
