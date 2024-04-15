#include "header.h"

class Solution {
  vector<string> ans;
  string temp;

  void dfs(int n, int left, int right) {
    if (n == left && n == right) {
      ans.push_back(temp);
      return;
    }
    if (left > n || right > n || left < right) {
      return;
    }
    // （
    temp.push_back('(');
    dfs(n, left + 1, right);
    temp.pop_back();

    // )
    temp.push_back(')');
    dfs(n, left, right + 1);
    temp.pop_back();
  }

 public:
  vector<string> generateParenthesis(int n) {
    ans.clear();
    temp.clear();
    dfs(n, 0, 0);
    return ans;
  }
};
