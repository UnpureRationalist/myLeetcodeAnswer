#include <bits/stdc++.h>
using namespace std;

class MinStack {
 public:
  MinStack() = default;

  void push(int val) {
    valueStk_.push(val);
    if (minStk_.empty() || val < getMin()) {
      minStk_.push(val);
    } else {
      minStk_.push(minStk_.top());
    }
  }

  void pop() {
    valueStk_.pop();
    minStk_.pop();
  }

  int top() { return valueStk_.top(); }

  int getMin() { return minStk_.top(); }

 private:
  stack<int> valueStk_;
  stack<int> minStk_;
};
