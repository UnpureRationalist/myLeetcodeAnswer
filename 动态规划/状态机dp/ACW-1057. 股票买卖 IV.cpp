#include <bits/stdc++.h>
using namespace std;

int solve(int k, const vector<int> &prices) {
  if (prices.empty()) {
    return 0;
  }

  int n = prices.size();
  k = min(k, n / 2);
  vector<vector<int>> buy(n, vector<int>(k + 1));
  vector<vector<int>> sell(n, vector<int>(k + 1));

  buy[0][0] = -prices[0];
  sell[0][0] = 0;
  for (int i = 1; i <= k; ++i) {
    buy[0][i] = sell[0][i] = INT_MIN / 2;
  }

  for (int i = 1; i < n; ++i) {
    buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
    for (int j = 1; j <= k; ++j) {
      buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
      sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
    }
  }

  return *max_element(sell[n - 1].begin(), sell[n - 1].end());
}

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> prices(n);
  for (int i = 0; i < n; ++i) {
    cin >> prices[i];
  }
  cout << solve(k, prices) << endl;
  return 0;
}
