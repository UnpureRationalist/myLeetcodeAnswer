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
  uint32_t reverseBits(uint32_t n) {
    int left = 0, right = 31;
    while (left < right) {
      int lbit = (n >> left) & 1;
      int rbit = (n >> right) & 1;
      if (lbit != rbit) {
        if (lbit) {
          n = n & (~(1 << left));
          n = n | (1 << right);
        } else {
          n = n | (1 << left);
          n = n & (~(1 << right));
        }
      }
      ++left;
      --right;
    }
    return n;
  }
};
