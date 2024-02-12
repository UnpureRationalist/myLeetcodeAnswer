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
  int N;
  vector<int> pos;

  bool isLegal(int row, int col) {
    for (int i = 0; i < row; ++i) {
      if (pos[i] == col || abs(i - row) == abs(pos[i] - col)) {
        return false;
      }
    }
    return true;
  }

  void solve(int depth, vector<vector<string>> &res) {
    if (depth == N) {
      // 构造 vector 放入 res
      vector<string> temp(N, string());
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (j == pos[i])
            temp[i].push_back('Q');
          else
            temp[i].push_back('.');
        }
      }
      res.push_back(temp);
      return;
    }
    for (int i = 0; i < N; ++i) {
      if (isLegal(depth, i)) {
        pos[depth] = i;
        solve(depth + 1, res);
      }
    }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    this->N = n;
    pos.resize(n + 1);
    vector<vector<string>> res;
    solve(0, res);
    return res;
  }
};
