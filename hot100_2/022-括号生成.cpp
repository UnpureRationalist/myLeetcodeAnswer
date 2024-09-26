#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<string> result;

  string tmp;

  void dfs(int left, int right) {
    if (left < 0 || right < 0) {
      return;
    }
    if (left == 0 && right == 0) {
      result.push_back(tmp);
      return;
    }
    if (left < right) {
      tmp.push_back(')');
      dfs(left, right - 1);
      tmp.pop_back();
    }
    tmp.push_back('(');
    dfs(left - 1, right);
    tmp.pop_back();
  }

 public:
  vector<string> generateParenthesis(int n) {
    result.clear();

    dfs(n, n);

    return result;
  }
};
