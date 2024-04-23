#include "header.h"

// 力扣题解：动态规划
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    auto matches = [&](int i, int j) {
      if (i == 0) {
        return false;
      }
      if (p[j - 1] == '.') {
        return true;
      }
      return s[i - 1] == p[j - 1];
    };

    vector<vector<int>> f(m + 1, vector<int>(n + 1));
    f[0][0] = true;
    for (int i = 0; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
          f[i][j] |= f[i][j - 2];
          if (matches(i, j - 1)) {  // ".*"
            f[i][j] |= f[i - 1][j];
          }
        } else {
          if (matches(i, j)) {
            f[i][j] |= f[i - 1][j - 1];
          }
        }
      }
    }
    return f[m][n];
  }
};

// 书中方法，力扣超时
// 添加 optimPattern 方法后可以通过
class Solution {
  bool matchCore(const char *str, const char *pattern) {
    if (*str == '\0' && *pattern == '\0') {
      return true;  // 二者都指向字符串末尾，返回 true
    }
    if (*str != '\0' && *pattern == '\0') {
      return false;  // str 不是末尾 pattern 到末尾，返回 false
    }

    // 处理 pattern 第二个字符为 '*' 的情况
    if (pattern[1] == '*') {
      // 当前 pattern 和 str 字符相同 或者 pattern = ".*" 表示匹配任意字符
      if (*pattern == *str || (*pattern == '.' && *str != '\0')) {
        return matchCore(str + 1, pattern + 2)  // move on the next state
               || matchCore(str + 1, pattern)   // stay on the current state
               || matchCore(str, pattern + 2);  // ignore a '*'
      }
      return matchCore(str, pattern + 2);  // ignore a '*'
    }

    if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
      return matchCore(str + 1, pattern + 1);
    }
    return false;
  }

  bool isMatch(const char *str, const char *pattern) {
    if (str == nullptr || pattern == nullptr) {
      return false;
    }
    return matchCore(str, pattern);
  }

  bool endDuplicatePattern(const vector<char> &v) {
    int n = v.size();
    return v[n - 1] == v[n - 3] && v[n - 2] == v[n - 4];
  }

  string optimPattern(const string &p) {
    vector<char> v;
    int n = p.length();
    for (int i = 0; i < n; ++i) {
      char c = p[i];
      v.push_back(c);
      if (v.size() >= 4 && c == '*' && endDuplicatePattern(v)) {
        v.pop_back();
        v.pop_back();
      }
    }
    return string(v.begin(), v.end());
  }

 public:
  bool isMatch(string s, string p) {
    p = optimPattern(p);
    return isMatch(s.c_str(), p.c_str());
  }
};
