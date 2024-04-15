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
    for (int i = 0; i < 32; ++i) {
      int total = 0;
      for (int num : nums) {
        total += ((num >> i) & 1);
      }
      if (total % 3) {
        ans |= (1 << i);
      }
    }
    return ans;
  }
};

class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    int seenOnce = 0, seenTwice = 0;

    for (int num : nums) {
      seenOnce = ~seenTwice & (seenOnce ^ num);
      seenTwice = ~seenOnce & (seenTwice ^ num);
    }

    return seenOnce;
  }
};
