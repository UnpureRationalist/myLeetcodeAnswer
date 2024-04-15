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
  int singleNumber(vector<int> &nums) {
    int ans = 0;
    for (const auto &num : nums) {
      ans ^= num;
    }
    return ans;
  }
};
