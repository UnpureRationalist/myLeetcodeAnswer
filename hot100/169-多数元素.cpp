#include <algorithm>
#include <climits>
#include <cmath>
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
  int majorityElement(vector<int> &nums) {
    int n = nums.size();
    while (true) {
      int candidate = nums[rand() % n];
      int count = 0;
      for (const auto &num : nums) {
        if (num == candidate) {
          ++count;
        }
      }
      if (count > n / 2) {
        return candidate;
      }
    }
    return -1;
  }
};

class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    int candidate = -1;
    int count = 0;
    for (const auto &num : nums) {
      if (num == candidate) {
        ++count;
      } else if (--count < 0) {
        candidate = num;
        count = 1;
      }
    }
    return candidate;
  }
};

class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    int ans = 0, votes = 0;
    for (int num : nums) {
      if (votes == 0) {
        ans = num;
      }
      votes += num == ans ? 1 : -1;
    }
    return ans;
  }
};
