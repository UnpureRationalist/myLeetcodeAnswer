#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    // 初始化，和为 0 的前缀和个数为 1
    mp[0] = 1;
    int result = 0;
    int pre_sum = 0;  // 保存前缀和
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      pre_sum += nums[i];        // 更新下标 [0, i] 前缀和
      int target = pre_sum - k;  // pre_sum[i] - target = k
      result += mp[target];
      mp[pre_sum]++;  // 更新 <pre_sum, count> 哈希表
    }
    return result;
  }
};

class Solution2 {
 public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, pre = 0;
    for (auto& x : nums) {
      pre += x;
      if (mp.find(pre - k) != mp.end()) {
        count += mp[pre - k];
      }
      mp[pre]++;
    }
    return count;
  }
};