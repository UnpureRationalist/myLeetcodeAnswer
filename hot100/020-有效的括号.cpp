#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;
    for (const auto &c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stk.push(c);
      } else {
        if (stk.empty()) {
          return false;
        }
        char temp = stk.top();
        stk.pop();
        if (c == ')' && temp == '(' || c == ']' && temp == '[' || c == '}' && temp == '{') {
          continue;
        } else {
          return false;
        }
      }
    }
    return stk.empty();
  }
};
