#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
 public:
  MedianFinder() = default;

  void addNum(int num) {
    if (minHalf_.size() > maxHalf_.size()) {
      // insert to `maxHalf_`
      if (num < minHalf_.top()) {
        int tmp = minHalf_.top();
        minHalf_.pop();
        minHalf_.emplace(num);
        maxHalf_.emplace(tmp);
      } else {
        maxHalf_.emplace(num);
      }
    } else {
      // insert to `minHalf_`
      if (!maxHalf_.empty()) {
        if (num <= maxHalf_.top()) {
          minHalf_.emplace(num);
        } else {
          int tmp = maxHalf_.top();
          maxHalf_.pop();
          maxHalf_.emplace(num);
          minHalf_.emplace(tmp);
        }
      } else {
        minHalf_.emplace(num);
      }
    }
  }

  double findMedian() {
    if (minHalf_.size() != maxHalf_.size()) {
      return minHalf_.top();
    }
    return (minHalf_.top() + maxHalf_.top()) / 2.0;
  }

 private:
  priority_queue<int> minHalf_;
  priority_queue<int, vector<int>, greater<int>> maxHalf_;
};
