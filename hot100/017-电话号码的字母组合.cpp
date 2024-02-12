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
  int n;
  vector<string> result;
  vector<bool> visited;
  string temp;
  vector<string> mp{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  int getResultSize(const string &digits) {
    int ans = 1;
    for (auto &c : digits) {
      ans *= mp[c - '0'].length();
    }
    return ans;
  }

  void dfs(int depth, const string &digits) {
    if (depth == n) {
      result.emplace_back(temp);
      return;
    }
    for (int i = depth; i < n; ++i) {
      if (!visited[i]) {
        visited[i] = true;
        for (auto &c : mp[digits[i] - '0']) {
          temp.push_back(c);
          dfs(depth + 1, digits);
          temp.pop_back();
        }
        visited[i] = false;
      }
    }
  }

 public:
  vector<string> letterCombinations(const string &digits) {
    result.clear();
    temp.clear();
    if (digits.empty()) {
      return result;
    }
    n = digits.length();
    visited.resize(n, false);
    temp.reserve(n);
    int ans = getResultSize(digits);
    result.reserve(ans);

    dfs(0, digits);

    return result;
  }
};
