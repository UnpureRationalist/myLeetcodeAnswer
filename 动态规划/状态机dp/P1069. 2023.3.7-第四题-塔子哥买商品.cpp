#include <bits/stdc++.h>
using namespace std;

struct Product {
  int price;
  int love;
};

/**
 * @brief 对于每种商品，有 3 种选择：不买，原价买，半价买（原价买了前一个物品）
 *
 *
 * @param n
 * @param money
 * @param products
 * @return long long
 */

long long solve(int n, int money, const vector<Product> &products) {
  long long ans = 0;
  vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(money + 1, vector<long long>(3, -1e9)));
  dp[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    const auto [price, love] = products[i - 1];
    for (int j = 0; j <= money; ++j) {
      dp[i][j][0] = *max_element(dp[i - 1][j].begin(), dp[i - 1][j].end());
      if (j >= price) {
        dp[i][j][1] = *max_element(dp[i - 1][j - price].begin(), dp[i - 1][j - price].end()) + love;
      }
      int half = price / 2;
      if (j >= half) {
        dp[i][j][2] = dp[i - 1][j - half][1] + love;
      }
      ans = max(ans, *max_element(dp[i][j].begin(), dp[i][j].end()));
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n, money;
  cin >> n >> money;
  vector<Product> products(n);
  for (int i = 0; i < n; ++i) {
    cin >> products[i].price;
  }
  for (int i = 0; i < n; ++i) {
    cin >> products[i].love;
  }
  cout << solve(n, money, products) << endl;
  return 0;
}
