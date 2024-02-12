#include <algorithm>
#include <climits>
#include <cmath>
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
  int help(string s) {
    int ans = 0, n = s.length();
    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
          dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        }
        ans = max(ans, dp[i]);
      }
    }
    return ans;
  }

 public:
  int longestValidParentheses(string s) {
    int n = s.length();
    int start = 0;
    while (start < n && s[start] == ')') {
      ++start;
    }
    return help(s.substr(start));
  }
};
