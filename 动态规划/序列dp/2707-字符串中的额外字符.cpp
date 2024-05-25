#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minExtraChar(string s, vector<string> &dictionary) {
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    int n = s.length();
    vector<int> dp(n + 1, n);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (dict.count(s.substr(j, i - j))) {
          dp[i] = min(dp[i], dp[j]);
        }
        dp[i] = min(dp[i], dp[j] + i - j);
      }
    }
    return dp[n];
  }
};
