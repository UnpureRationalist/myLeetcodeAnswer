#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 private:
  vector<vector<int>> f;
  vector<vector<string>> ret;
  vector<string> ans;
  int n;

 public:
  void dfs(const string &s, int i) {
    if (i == n) {
      ret.push_back(ans);
      return;
    }
    for (int j = i; j < n; ++j) {
      if (f[i][j]) {
        ans.push_back(s.substr(i, j - i + 1));
        dfs(s, j + 1);
        ans.pop_back();
      }
    }
  }

  vector<vector<string>> partition(string s) {
    n = s.size();
    f.assign(n, vector<int>(n, true));

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
      }
    }

    dfs(s, 0);
    return ret;
  }
};
