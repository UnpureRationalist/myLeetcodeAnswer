#include "header.h"

class Solution {
 public:
  int evalRPN(vector<string> &tokens) {
    stack<int> stk;
    for (const auto &str : tokens) {
      if (str == "+" || str == "-" || str == "*" || str == "/") {
        int rhs = stk.top();
        stk.pop();
        int lhs = stk.top();
        stk.pop();
        int value = -1;
        switch (str[0]) {
          case '+':
            value = lhs + rhs;
            break;

          case '-':
            value = lhs - rhs;
            break;

          case '*':
            value = lhs * rhs;
            break;

          case '/':
            value = lhs / rhs;
            break;
        }
        stk.push(value);
      } else {
        stk.push(stoi(str));
      }
    }
    return stk.top();
  }
};
