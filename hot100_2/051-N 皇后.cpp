#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<vector<string>> result;

  vector<int> colIdx;

  void generateAns(int n) {
    vector<string> tmp(n, string(n, '.'));
    for (int i = 0; i < n; ++i) {
      tmp[i][colIdx[i]] = 'Q';
    }
    result.push_back(tmp);
  }

  inline bool legal(int row, int col) const {
    for (int i = 0; i < row; ++i) {
      if (col == colIdx[i] || abs(row - i) == abs(col - colIdx[i])) {
        return false;
      }
    }
    return true;
  }

  void dfs(int depth, int n) {
    if (depth == n) {
      generateAns(n);
      return;
    }
    for (int col = 0; col < n; ++col) {
      if (legal(depth, col)) {
        colIdx.push_back(col);
        dfs(depth + 1, n);
        colIdx.pop_back();
      }
    }
  }

 public:
  vector<vector<string>> solveNQueens(int n) {
    result.clear();
    dfs(0, n);
    return result;
  }
};
