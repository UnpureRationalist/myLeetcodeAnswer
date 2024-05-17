#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  vector<int> dp(n + 1, 0);
  dp[1] = nums[0];
  for (int i = 2; i <= n; ++i) {
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
  }
  cout << dp[n] << endl;
  return 0;
}
