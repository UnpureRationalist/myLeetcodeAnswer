#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> mp(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int end = 1; end <= n; ++end) {
      for (int start = 0; start < end; ++start) {
        if (dp[start] && mp.count(s.substr(start, end - start))) {
          dp[end] = 1;
          break;
        }
      }
    }
    return dp[n];
  }
};
