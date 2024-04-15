#include "header.h"

class MedianFinder {
 private:
  priority_queue<int, vector<int>, less<int>> maxheap;  // 保存数据流前一半元素（总数为奇数时保存较多元素）
  priority_queue<int, vector<int>, greater<int>> minheap;  // 后一半

 public:
  MedianFinder() {}

  void addNum(int num) {
    if (maxheap.empty()) {
      maxheap.emplace(num);
      return;
    }
    if (maxheap.size() == minheap.size()) {
      int left = maxheap.top();
      int right = minheap.top();
      if (num <= right) {
        maxheap.emplace(num);
      } else {
        minheap.pop();
        maxheap.emplace(right);
        minheap.emplace(num);
      }
    } else {
      int mid = maxheap.top();
      if (num >= mid) {
        minheap.emplace(num);
      } else {
        maxheap.pop();
        maxheap.emplace(num);
        minheap.emplace(mid);
      }
    }
  }

  double findMedian() {
    if (maxheap.size() > minheap.size()) {
      return maxheap.top();
    }
    return (maxheap.top() + minheap.top()) / 2.0;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */