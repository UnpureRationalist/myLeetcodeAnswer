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
  void dfs(vector<string> &result, int left, int right, string &temp) {
    if (left < 0 || right < 0) {
      return;
    }
    if (left == 0 && right == 0) {
      result.emplace_back(temp);
      return;
    }
    if (left > right) {
      return;
    }
    temp.push_back('(');
    dfs(result, left - 1, right, temp);
    temp.pop_back();

    temp.push_back(')');
    dfs(result, left, right - 1, temp);
    temp.pop_back();
  }

 public:
  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string temp;
    dfs(result, n, n, temp);
    return result;
  }
};