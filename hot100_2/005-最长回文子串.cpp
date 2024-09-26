#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.length();
    if (n < 2) {
      return s;
    }
    int maxLen = 1;
    int beginIdx = 0;
    vector<vector<char>> dp(n, vector<char>(n, 0));  // dp[i][j] 表示 s[i...j] 是否回文
    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }
    for (int len = 2; len <= n; ++len) {
      int maxIdx = n - len + 1;
      for (int i = 0; i < maxIdx; ++i) {
        int j = i + len - 1;
        if (s[i] == s[j]) {
          dp[i][j] = len <= 2 ? 1 : dp[i + 1][j - 1];
        }
        if (dp[i][j] && len > maxLen) {
          beginIdx = i;
          maxLen = len;
        }
      }
    }
    return s.substr(beginIdx, maxLen);
  }
};
