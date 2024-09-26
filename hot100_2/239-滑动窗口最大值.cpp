#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int>> num2idx;
    for (int i = 0; i < k; ++i) {
      num2idx.emplace(nums[i], i);
    }
    vector<int> result;
    result.reserve(n - k + 1);
    result.push_back(num2idx.top().first);
    for (int i = k; i < n; ++i) {
      num2idx.emplace(nums[i], i);
      int minIdx = i - k;
      while (num2idx.top().second <= minIdx) {
        num2idx.pop();
      }
      result.push_back(num2idx.top().first);
    }
    return result;
  }
};

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    int n = nums.size();
    if (n < k || k < 1) {
      return result;
    }
    deque<int> indices;
    for (int i = 0; i < k; ++i) {
      while (!indices.empty() && nums[i] > nums[indices.back()]) {
        indices.pop_back();  // 如果双端队列非空 并且
                             // 当前数大于队列尾端下标对应的数，则尾端数不可能是滑动窗口内最大值，pop_back 删除
      }
      indices.push_back(i);
    }
    for (int i = k; i < n; ++i) {
      result.push_back(nums[indices.front()]);
      while (!indices.empty() && nums[i] > nums[indices.back()]) {
        indices.pop_back();  // 与前面原因相同
      }
      if (!indices.empty() && indices.front() <= (i - k)) {
        indices.pop_front();  // 当 pop_front 的下标小于 i - k 时，超过滑动窗口值 pop_front 删除
      }
      indices.push_back(i);
    }
    result.push_back(nums[indices.front()]);
    return result;
  }
};
