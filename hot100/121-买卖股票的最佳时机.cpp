#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int min_price = prices[0];
    int result = 0;
    for (const auto &price : prices) {
      min_price = min(min_price, price);
      result = max(result, price - min_price);
    }
    return result;
  }
};
