#include "header.h"

class Solution {
 public:
  string simplifyPath(string path) {
    stack<string> stk;
    int n = path.length();
    int i = 1;
    while (i < n) {
      while (i < n && path[i] == '/') {
        ++i;
      }
      if (i == n) {
        break;
      }
      // 截取字符串
      int j = i + 1;
      while (j < n && path[j] != '/') {
        ++j;
      }

      string temp = path.substr(i, j - i);

      i = j;  // update index

      if (temp == ".") {
        continue;
      }
      if (temp == "..") {
        if (stk.size() >= 2) {
          stk.pop();
          stk.pop();
        }
      } else {
        stk.emplace(1, '/');
        stk.emplace(temp);
      }
    }
    if (stk.empty()) {
      stk.emplace(1, '/');
    }
    vector<string> v;
    v.reserve(stk.size());
    while (!stk.empty()) {
      v.emplace_back(move(stk.top()));
      stk.pop();
    }
    reverse(v.begin(), v.end());
    return accumulate(v.begin(), v.end(), string(""));
  }
};
