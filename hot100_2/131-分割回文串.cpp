#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  vector<vector<int>> dp;
  vector<vector<string>> ret;
  vector<string> ans;
  int n;

  void dfs(const string &s, int i) {
    if (i == n) {
      ret.push_back(ans);
      return;
    }
    for (int j = i; j < n; ++j) {
      if (dp[i][j]) {
        ans.push_back(s.substr(i, j - i + 1));
        dfs(s, j + 1);
        ans.pop_back();
      }
    }
  }

 public:
  vector<vector<string>> partition(string s) {
    n = s.size();
    dp.assign(n, vector<int>(n, true));

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
      }
    }

    dfs(s, 0);
    return ret;
  }
};
