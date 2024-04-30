#include "header.h"

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int ans = 0;
    int minPrice = prices[0];
    for (const auto &price : prices) {
      ans = max(ans, price - minPrice);
      minPrice = min(minPrice, price);
    }
    return ans;
  }
};
