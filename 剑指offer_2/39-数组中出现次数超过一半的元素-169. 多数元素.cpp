#include "header.h"

// 基于 partition 函数的时间复杂度 O(n) 算法
class Solution {
  int partition(vector<int> &data, int length, int start, int end) {
    int index = (start + end) / 2;
    swap(data[index], data[end]);
    int small = start - 1;
    for (index = start; index < end; ++index) {
      if (data[index] < data[end]) {
        ++small;
        if (small != index) {
          swap(data[index], data[small]);
        }
      }
    }
    ++small;
    swap(data[small], data[end]);
    return small;
  }

 public:
  int majorityElement(vector<int> &nums) {
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    int index = partition(nums, n, start, end);
    int middle = n >> 1;
    while (index != middle) {
      if (index > middle) {
        end = index - 1;
        index = partition(nums, n, start, end);
      } else {
        start = index + 1;
        index = partition(nums, n, start, end);
      }
    }
    return nums[middle];
  }
};

// 投票法
class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    int n = nums.size();
    int result = nums[0];
    int times = 1;
    for (int i = 1; i < n; ++i) {
      if (times == 0) {
        result = nums[i];
        times = 1;
      } else if (nums[i] == result) {
        ++times;
      } else {
        --times;
      }
    }
    return result;
  }
};

// 变例：229. 多数元素 II
// 给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
class Solution {
 public:
  vector<int> majorityElement(vector<int> &nums) {
    vector<int> ans;
    int element1 = 0;
    int element2 = 0;  // 数组中最多有 2 个元素，出现超过 ⌊ n/3 ⌋ 次
    int vote1 = 0;
    int vote2 = 0;

    for (auto &num : nums) {
      if (vote1 > 0 && num == element1) {  // 如果该元素为第一个元素，则计数加1
        vote1++;
      } else if (vote2 > 0 && num == element2) {  // 如果该元素为第二个元素，则计数加1
        vote2++;
      } else if (vote1 == 0) {  // 选择第一个元素
        element1 = num;
        vote1++;
      } else if (vote2 == 0) {  // 选择第二个元素
        element2 = num;
        vote2++;
      } else {  // 如果三个元素均不相同，则相互抵消1次
        vote1--;
        vote2--;
      }
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for (auto &num : nums) {
      if (vote1 > 0 && num == element1) {
        cnt1++;
      }
      if (vote2 > 0 && num == element2) {
        cnt2++;
      }
    }
    // 检测元素出现的次数是否满足要求
    if (vote1 > 0 && cnt1 > nums.size() / 3) {
      ans.push_back(element1);
    }
    if (vote2 > 0 && cnt2 > nums.size() / 3) {
      ans.push_back(element2);
    }

    return ans;
  }
};
