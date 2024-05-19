#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<pair<int, int>> str2count(const vector<string> &strs) {
    int n = strs.size();
    vector<pair<int, int>> result(n);
    for (int i = 0; i < n; ++i) {
      int zero = count(strs[i].begin(), strs[i].end(), '0');
      int one = strs[i].length() - zero;
      result[i].first = zero;
      result[i].second = one;
    }
    return result;
  }

 public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<pair<int, int>> zeroOneCount = str2count(strs);
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int size = strs.size();
    for (int i = 0; i < size; ++i) {
      auto &[zeros, ones] = zeroOneCount[i];
      for (int zero = m; zero >= zeros; --zero) {
        for (int one = n; one >= ones; --one) {
          dp[zero][one] = max(dp[zero][one], dp[zero - zeros][one - ones] + 1);
        }
      }
    }
    return dp[m][n];
  }
};
