#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> hash(5000);  // (key, index)
    for (int i = 0; i < n; ++i) {
      int left = target - nums[i];
      if (hash.find(left) != hash.end()) {
        return {hash[left], i};
      }
      hash[nums[i]] = i;
    }
    return {};
  }
};