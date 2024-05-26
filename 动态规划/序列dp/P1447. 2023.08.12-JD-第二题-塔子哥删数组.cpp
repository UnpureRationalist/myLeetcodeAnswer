#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve(int n, const vector<long long> &nums) {
  if (n == 1) {
    for (int i = 0; i < 10; ++i) {
      if (i > 0) {
        cout << " ";
      }
      cout << (nums[0] == i);
    }
    cout << endl;
    return;
  }

  vector<vector<long long>> dp(n, vector<long long>(10, 0));
  // 初始化第一步运算：取最后两个数，进行加法或乘法
  long long add = nums[n - 1] + nums[n - 2];
  dp[n - 2][add % 10] += 1;
  long long mult = nums[n - 1] * nums[n - 2];
  dp[n - 2][mult % 10] += 1;
  // 从后向前递推
  for (int i = n - 3; i >= 0; --i) {
    int post = i + 1;
    for (int j = 0; j < 10; ++j) {
      if (dp[post][j] != 0) {
        long long add = nums[i] + j;
        int idx = add % 10;
        dp[i][idx] = (dp[i][idx] + dp[post][j]) % MOD;
        long long mult = nums[i] * j;
        idx = mult % 10;
        dp[i][idx] = (dp[i][idx] + dp[post][j]) % MOD;
      }
    }
  }
  for (int j = 0; j < 10; ++j) {
    if (j > 0) {
      cout << " ";
    }
    cout << dp[0][j];
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  solve(n, nums);
  return 0;
}
