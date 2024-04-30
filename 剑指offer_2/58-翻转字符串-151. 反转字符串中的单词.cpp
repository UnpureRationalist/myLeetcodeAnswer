#include "header.h"

class Solution {
 public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int n = s.length();
    int start = 0;
    string result;
    while (start < n) {
      while (start < n && s[start] == ' ') {
        ++start;
      }
      int end = start + 1;
      while (end < n && s[end] != ' ') {
        ++end;
      }
      if (start < n) {
        string temp = s.substr(start, end - start);
        reverse(temp.begin(), temp.end());
        if (result.empty()) {
          result = temp;
        } else {
          result.push_back(' ');
          result.append(temp);
        }
      }
      start = end + 1;
    }
    return result;
  }
};

// 796. 旋转字符串
class Solution {
  bool isRotateEqual(const string &s, const string &goal, int rotate_idx) {
    int n = s.length();
    int i = 0;
    int goal_mid = n - rotate_idx;
    // s 前 rotate_idx 个字符与 goal 最后面 rotate_idx 个字符比较
    for (; i < rotate_idx; ++i) {
      if (s[i] != goal[goal_mid + i]) {
        return false;
      }
    }
    // s 后面剩余的字符 与 goal 前面剩余的字符比较
    int j = 0;
    for (; i < n; ++i, ++j) {
      if (s[i] != goal[j]) {
        return false;
      }
    }
    return true;
  }

 public:
  bool rotateString(string s, string goal) {
    int n = s.length();
    int m = goal.length();
    if (n != m) {
      return false;
    }
    for (int i = 0; i < n; ++i) {
      if (isRotateEqual(s, goal, i)) {
        return true;
      }
    }
    return false;
  }
};
