#include "header.h"

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
      while (!indices.empty() && nums[i] >= nums[indices.back()]) {
        indices.pop_back();  // 如果双端队列非空 并且
                             // 当前数大于队列尾端下标对应的数，则尾端数不可能是滑动窗口内最大值，pop_back 删除
      }
      indices.push_back(i);
    }
    for (int i = k; i < n; ++i) {
      result.push_back(nums[indices.front()]);
      while (!indices.empty() && nums[i] >= nums[indices.back()]) {
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

// 引申：带 max 函数的队列
template <typename T>
class QueueWithMax {
 public:
  QueueWithMax() : currentIndex(0) {}

  void push_back(T number) {
    while (!maximums.empty() && number >= maximums.back().number) {
      maximums.pop_back();
    }

    InternalData internalData = {number, currentIndex};
    data.push_back(internalData);
    maximums.push_back(internalData);

    ++currentIndex;
  }

  void pop_front() {
    if (maximums.empty()) {
      throw new exception("queue is empty");
    }

    if (maximums.front().index == data.front().index) {
      maximums.pop_front();
    }

    data.pop_front();
  }

  T max() const {
    if (maximums.empty()) {
      throw new exception("queue is empty");
    }

    return maximums.front().number;
  }

 private:
  struct InternalData {
    T number;
    int index;
  };

  deque<InternalData> data;
  deque<InternalData> maximums;
  int currentIndex;
};
