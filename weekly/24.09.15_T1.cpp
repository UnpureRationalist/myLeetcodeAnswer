#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> getSneakyNumbers(vector<int> &nums) {
    unordered_map<int, int> num2count;
    for (const auto &num : nums) {
      num2count[num]++;
    }
    vector<int> result;
    for (const auto &[num, count] : num2count) {
      if (count >= 2) {
        result.push_back(num);
      }
    }
    return result;
  }
};
