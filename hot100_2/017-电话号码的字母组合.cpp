#include <bits/stdc++.h>
using namespace std;

class Solution {
  int n;
  vector<string> result;
  string tmp;

  unordered_map<char, string> num2string{{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                         {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

  void dfs(int depth, const string &digits) {
    if (depth == n) {
      result.push_back(tmp);
      return;
    }
    for (const auto &c : num2string[digits[depth]]) {
      tmp.push_back(c);
      dfs(depth + 1, digits);
      tmp.pop_back();
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    n = digits.size();
    result.clear();
    tmp.clear();

    if (n == 0) {
      return result;
    }

    dfs(0, digits);

    return result;
  }
};
