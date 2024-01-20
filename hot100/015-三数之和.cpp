#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  vector<pair<int, int>> middle_result;

  void getTarget2Sum(int left_idx, vector<int>& nums, int target) {
    middle_result.clear();
    int right_idx = nums.size() - 1;
    while (left_idx < right_idx) {
      if (nums[left_idx] + nums[right_idx] == target) {
        middle_result.emplace_back(make_pair(nums[left_idx], nums[right_idx]));
        int left_value = nums[left_idx];
        while (left_idx < right_idx && nums[left_idx] == left_value) {
          ++left_idx;
        }
        int right_value = nums[right_idx];
        while (right_idx > left_idx && nums[right_idx] == right_value) {
          --right_idx;
        }
      } else if (nums[left_idx] + nums[right_idx] < target) {
        ++left_idx;
      } else {
        --right_idx;
      }
    }
  }

 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n;) {
      int target_2_sum = -nums[i];
      // 使用双指针查找和为 -nums[i] 的两个元素
      getTarget2Sum(i + 1, nums, target_2_sum);
      for (auto& elems : middle_result) {
        result.emplace_back(
            std::vector<int>{nums[i], elems.first, elems.second});
      }
      int current_value = nums[i];
      while (i < n && nums[i] == current_value) {
        ++i;
      }
    }

    return result;
  }
};

class Solution2 {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    // 枚举 a
    for (int first = 0; first < n; ++first) {
      // 需要和上一次枚举的数不相同
      if (first > 0 && nums[first] == nums[first - 1]) {
        continue;
      }
      // c 对应的指针初始指向数组的最右端
      int third = n - 1;
      int target = -nums[first];
      // 枚举 b
      for (int second = first + 1; second < n; ++second) {
        // 需要和上一次枚举的数不相同
        if (second > first + 1 && nums[second] == nums[second - 1]) {
          continue;
        }
        // 需要保证 b 的指针在 c 的指针的左侧
        while (second < third && nums[second] + nums[third] > target) {
          --third;
        }
        // 如果指针重合，随着 b 后续的增加
        // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
        if (second == third) {
          break;
        }
        if (nums[second] + nums[third] == target) {
          ans.push_back({nums[first], nums[second], nums[third]});
        }
      }
    }
    return ans;
  }
};