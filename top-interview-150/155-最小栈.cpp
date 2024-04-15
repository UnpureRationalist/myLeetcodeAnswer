#include "header.h"

class MinStack {
 private:
  stack<int> stk;
  stack<int> min_values;

 public:
  MinStack() {}

  void push(int val) {
    stk.push(val);
    if (min_values.empty() || min_values.top() > val) {
      min_values.push(val);
    } else {
      min_values.push(min_values.top());
    }
  }

  void pop() {
    stk.pop();
    min_values.pop();
  }

  int top() { return stk.top(); }

  int getMin() { return min_values.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
