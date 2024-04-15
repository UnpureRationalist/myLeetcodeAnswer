#include "header.h"

class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int n = s.length();
    vector<char> dp(n + 1, 0);
    dp[0] = 1;
    unordered_set<string> mp(wordDict.begin(), wordDict.end());
    for (int end = 1; end <= n; ++end) {
      for (int start = 0; start < end; ++start) {
        if (dp[start] && mp.find(s.substr(start, end - start)) != mp.end()) {
          dp[end] = 1;
          break;
        }
      }
    }
    return dp[n];
  }
};
