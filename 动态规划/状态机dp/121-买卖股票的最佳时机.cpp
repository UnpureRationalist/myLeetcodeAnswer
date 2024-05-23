#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    int min_price = prices[0];
    for (const auto &price : prices) {
      ans = max(ans, price - min_price);
      min_price = min(min_price, price);
    }
    return ans;
  }
};
