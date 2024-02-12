#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    if (queMin.empty() || num <= queMin.top()) {
      queMin.push(num);
      if (queMax.size() + 1 < queMin.size()) {
        queMax.push(queMin.top());
        queMin.pop();
      }
    } else {
      queMax.push(num);
      if (queMax.size() > queMin.size()) {
        queMin.push(queMax.top());
        queMax.pop();
      }
    }
  }

  double findMedian() {
    if (queMin.size() > queMax.size()) {
      return queMin.top();
    }
    return (queMin.top() + queMax.top()) / 2.0;
  }

 private:
  priority_queue<int, vector<int>, less<int>> queMin;
  priority_queue<int, vector<int>, greater<int>> queMax;
};
