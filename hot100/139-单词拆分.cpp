#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> wordDictSet(wordDict.begin(), wordDict.end());
    int n = s.length();
    vector<bool> dp(n + 1);
    dp[0] = true;
    for (int end = 1; end <= n; ++end) {
      for (int start = 0; start < end; ++start) {
        if (dp[start] && wordDictSet.find(s.substr(start, end - start)) != wordDictSet.end()) {
          dp[end] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};
