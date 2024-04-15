#include "header.h"

class Solution {
  unordered_map<char, string> mp;

  void dfs(string &digits, int depth, vector<string> &ans, string &curr) {
    if (digits.length() == depth) {
      ans.push_back(curr);
      return;
    }
    for (auto &c : mp[digits[depth]]) {
      curr.push_back(c);
      dfs(digits, depth + 1, ans, curr);
      curr.pop_back();
    }
  }

 public:
  Solution() {
    int count = 0;
    for (int i = 2; i <= 9; ++i) {
      int num = ((i == 7 || i == 9) ? 4 : 3);
      for (int j = 0; j < num; ++j) {
        mp[i + '0'].push_back(count + 'a');
        ++count;
      }
    }
  }

  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0) {
      return ans;
    }
    string curr;
    dfs(digits, 0, ans, curr);
    return ans;
  }
};
