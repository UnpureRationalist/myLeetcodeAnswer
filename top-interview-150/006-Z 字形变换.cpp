#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  void next(int &row, int &col, int numRows) {
    if (col % (numRows - 1) == 0) {
      if (row == numRows - 1) {
        --row;
        ++col;
      } else {
        ++row;
      }
    } else {
      --row;
      ++col;
    }
  }

 public:
  string convert(string s, int numRows) {
    int n = s.length();
    if (numRows == 1 || numRows >= n) {
      return s;
    }

    int blocks = 2 * numRows - 2;
    int cols = (n + blocks - 1) / blocks * (numRows - 1);
    vector<string> matrix(numRows, string(cols, ' '));
    int row = 0, col = 0;
    for (int i = 0; i < n; ++i) {
      matrix[row][col] = s[i];
      next(row, col, numRows);
    }
    string ans;
    ans.reserve(n);
    for (const auto &str : matrix) {
      for (const auto &c : str) {
        if (c != ' ') {
          ans.push_back(c);
        }
      }
    }
    return ans;
  }
};

class Solution {
 public:
  string convert(string s, int numRows) {
    int n = s.length(), r = numRows;
    if (r == 1 || r >= n) {
      return s;
    }
    string ans;
    int t = r * 2 - 2;
    for (int i = 0; i < r; ++i) {           // 枚举矩阵的行
      for (int j = 0; j + i < n; j += t) {  // 枚举每个周期的起始下标
        ans += s[j + i];                    // 当前周期的第一个字符
        if (0 < i && i < r - 1 && j + t - i < n) {
          ans += s[j + t - i];  // 当前周期的第二个字符
        }
      }
    }
    return ans;
  }
};

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows < 2) return s;
    vector<string> rows(numRows);
    int i = 0, flag = -1;
    for (char c : s) {
      rows[i].push_back(c);
      if (i == 0 || i == numRows - 1) flag = -flag;
      i += flag;
    }
    string res;
    for (const string &row : rows) res += row;
    return res;
  }
};
