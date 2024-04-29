#include "header.h"

//  Leetcode LCR 170. 交易逆序对的总数
class Solution {
  int reversePairs(vector<int> &data, vector<int> &backup, int start, int end) {
    if (start == end) {
      backup[start] = data[start];
      return 0;
    }
    int length = (end - start) / 2;
    int left = reversePairs(backup, data, start, start + length);
    int right = reversePairs(backup, data, start + length + 1, end);  // 此处 data 和 backup 进行交换

    int i = start + length;  // 前半段最后一个数字下标
    int j = end;
    int indexCopy = end;
    int count = 0;
    while (i >= start && j >= start + length + 1) {
      if (data[i] > data[j]) {
        backup[indexCopy--] = data[i--];
        count += j - start - length;
      } else {
        backup[indexCopy--] = data[j--];
      }
    }
    for (; i >= start; --i) {
      backup[indexCopy--] = data[i];
    }
    for (; j >= start + length + 1; --j) {
      backup[indexCopy--] = data[j];
    }
    return left + right + count;
  }

 public:
  int reversePairs(vector<int> &record) {
    int n = record.size();
    if (n <= 1) {
      return 0;
    }
    vector<int> temp(record.begin(), record.end());
    return reversePairs(record, temp, 0, n - 1);
  }
};

// 变例：Leetcode 493. 翻转对
class Solution {
 public:
  int reversePairsRecursive(vector<int> &nums, int left, int right) {
    if (left == right) {
      return 0;
    }

    int mid = (left + right) / 2;
    int n1 = reversePairsRecursive(nums, left, mid);
    int n2 = reversePairsRecursive(nums, mid + 1, right);
    int ret = n1 + n2;

    // 首先统计下标对的数量
    int i = left;
    int j = mid + 1;  // 最小下标开始向右遍历
    while (i <= mid) {
      while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) {
        j++;
      }
      ret += (j - mid - 1);
      i++;
    }

    // 随后合并两个排序数组
    vector<int> sorted(right - left + 1);
    int p1 = left, p2 = mid + 1;
    int p = 0;
    while (p1 <= mid || p2 <= right) {
      if (p1 > mid) {
        sorted[p++] = nums[p2++];
      } else if (p2 > right) {
        sorted[p++] = nums[p1++];
      } else {
        if (nums[p1] < nums[p2]) {
          sorted[p++] = nums[p1++];
        } else {
          sorted[p++] = nums[p2++];
        }
      }
    }
    for (int i = 0; i < sorted.size(); i++) {
      nums[left + i] = sorted[i];
    }
    return ret;
  }

  int reversePairs(vector<int> &nums) {
    if (nums.size() <= 1) {
      return 0;
    }
    return reversePairsRecursive(nums, 0, nums.size() - 1);
  }
};
