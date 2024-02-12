#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class MinStack {
 public:
  MinStack() = default;

  void push(int val) {
    if (stk.empty()) {
      stk.push(val);
      min_stk.push(val);
    } else {
      int min_val = min(min_stk.top(), val);
      stk.push(val);
      min_stk.push(min_val);
    }
  }

  void pop() {
    stk.pop();
    min_stk.pop();
  }

  int top() { return stk.top(); }

  int getMin() { return min_stk.top(); }

 private:
  stack<int> stk;
  stack<int> min_stk;
};
