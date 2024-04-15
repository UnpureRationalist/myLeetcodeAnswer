#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int min_price = prices[0];
    int ans = 0;
    for (const auto& price : prices) {
      min_price = min(min_price, price);
      ans = max(ans, price - min_price);
    }
    return ans;
  }
};
