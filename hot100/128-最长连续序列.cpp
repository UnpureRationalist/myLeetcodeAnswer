#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash(nums.begin(), nums.end());

    int result = 0;

    for (const auto& num : hash) {
      if (hash.find(num - 1) == hash.end()) {
        int cur_len = 1;
        int cur_num = num;
        while (hash.find(++cur_num) != hash.end()) {
          ++cur_len;
        }
        result = max(result, cur_len);
      }
    }
    return result;
  }
};

class Solution2 {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> hash;
    int res = 0;
    for (auto num : nums) {
      if (hash.find(num) == hash.end()) {
        int left_length = hash.find(num - 1) == hash.end() ? 0 : hash[num - 1];
        int right_length = hash.find(num + 1) == hash.end() ? 0 : hash[num + 1];
        int update_value = left_length + right_length + 1;
        res = max(res, update_value);
        hash[num] = update_value;
        hash[num - left_length] = update_value;
        hash[num + right_length] = update_value;
      }
    }
    return res;
  }
};

class Solution3 {
 public:
  int longestConsecutive(vector<int>& nums) {
    // 开始填表 x
    // D[x] 是 x 作为一个端点时，最长的连续区间的长度
    unordered_map<int, int> hash;

    // 先全部初始化为 0
    for (auto x : nums) hash[x] = 0;

    // m 跟踪最大的 d;
    int res = 0;

    for (auto x : nums) {
      // 填表过程:
      // 为什么要更新两端:
      //
      if (hash[x] == 0) {
        int L = hash[x - 1];  // 左侧 x-1 为右端点的情况
        int R = hash[x + 1];  // 右侧 x+1 为左断点的情况
        int d = 1 + L + R;
        hash[x - L] = d;  // 左侧的 x-L 处为左端点的情况，长度要扩大到 1+L+R;
        hash[x + R] = d;  // 右侧的 x+R 处同理
        // x 处作为端点的情况，应该取 L+1 和 R+1 的最大值
        // (算上自己一个元素)
        hash[x] = std::max(L + 1, R + 1);
        if (d > res) res = d;
      }
    }

    return res;
  }
};