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

  vector<int> dp(n, 1);
  int ans = 1;
  for (int i = 1; i < n; ++i) {
    dp[i] = abs(nums[i] - nums[i - 1]) <= 1 ? dp[i - 1] + 1 : dp[i];
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
