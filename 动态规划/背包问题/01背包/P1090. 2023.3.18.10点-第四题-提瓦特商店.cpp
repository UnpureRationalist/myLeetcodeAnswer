#include <bits/stdc++.h>
using namespace std;

void solve(int n, int money, int discount, const vector<pair<int, int>> &nums) {
  vector<vector<int>> dp(money + 1, vector<int>(discount + 1, 0));  // dp[i][j] 表示有 i 元钱和 j 张折扣券最多能买几件
  for (int k = 0; k < n; ++k) {
    int original = nums[k].first;
    int after = nums[k].second;
    for (int i = money; i >= after; --i) {
      for (int j = discount; j >= 0; --j) {
        if (i >= original) {
          dp[i][j] = max(dp[i][j], dp[i - original][j] + 1);  // 原价购买
        }
        if (j >= 1) {
          dp[i][j] = max(dp[i][j], dp[i - after][j - 1] + 1);  // 折扣券购买
        }
      }
    }
  }
  int max_products = dp[money][discount];
  int min_money = money;
  for (int i = 1; i <= money; ++i) {
    for (int j = 1; j <= discount; ++j) {
      if (dp[i][j] == max_products) {
        min_money = min(min_money, i);
      }
    }
  }
  cout << max_products << " " << min_money << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n, money, discount;
  cin >> n >> money >> discount;
  vector<pair<int, int>> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i].first >> nums[i].second;
  }
  solve(n, money, discount, nums);
  return 0;
}
