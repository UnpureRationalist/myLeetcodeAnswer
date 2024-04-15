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
  int hammingWeight(uint32_t n) {
    int ans = 0;
    while (n) {
      ans += n & 1;
      n = n >> 1;
    }
    return ans;
  }
};
