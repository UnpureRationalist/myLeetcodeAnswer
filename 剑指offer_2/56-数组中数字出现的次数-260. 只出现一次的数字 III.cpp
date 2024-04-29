#include "header.h"

class Solution {
  unsigned int findFirstBit1(int num) {
    int indexBit = 0;
    while ((num & 1) == 0 && (indexBit < 8 * sizeof(int))) {
      num = num >> 1;
      ++indexBit;
    }
    return indexBit;
  }

  bool isBit1(int num, unsigned int indexBit) {
    num = num >> indexBit;
    return num & 1;
  }

 public:
  vector<int> singleNumber(vector<int> &nums) {
    int result = 0;
    for (const auto &num : nums) {
      result ^= num;
    }
    unsigned int indexOf1 = findFirstBit1(result);
    int num1 = 0;
    int num2 = 0;
    for (const auto &num : nums) {
      if (isBit1(num, indexOf1)) {
        num1 ^= num;
      } else {
        num2 ^= num;
      }
    }
    return {num1, num2};
  }
};

// 类似题： Leetcode 137. 只出现一次的数字 II
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
