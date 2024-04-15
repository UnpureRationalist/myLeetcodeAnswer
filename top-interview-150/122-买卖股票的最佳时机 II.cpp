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
    int ans = 0;
    int n = prices.size();
    for (int i = 1; i < n; ++i) {
      ans += max(0, prices[i] - prices[i - 1]);
    }
    return ans;
  }
};
