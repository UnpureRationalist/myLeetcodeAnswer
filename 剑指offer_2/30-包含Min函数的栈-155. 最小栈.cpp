#include "header.h"

class MinStack {
 public:
  MinStack() = default;

  void push(int val) {
    data_stk.emplace(val);
    if (min_stk.empty() || val < min_stk.top()) {
      min_stk.emplace(val);
    } else {
      min_stk.emplace(min_stk.top());
    }
  }

  void pop() {
    data_stk.pop();
    min_stk.pop();
  }

  int top() { return data_stk.top(); }

  int getMin() { return min_stk.top(); }

 private:
  stack<int> data_stk;
  stack<int> min_stk;
};