#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int ans = 0;
    int minPrice = prices[0];
    for (int i = 1; i < n; ++i) {
      ans = max(ans, prices[i] - minPrice);
      minPrice = min(minPrice, prices[i]);
    }
    return ans;
  }
};
