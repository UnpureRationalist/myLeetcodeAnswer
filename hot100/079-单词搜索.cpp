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
  int rows;
  int cols;

  vector<vector<bool>> visited;

  vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool dfs(vector<vector<char>> &board, int i, int j, int depth, string &word) {
    if (depth == word.length()) {
      return true;
    }
    if (depth > word.length()) {
      return false;
    }
    for (const auto &vec : dirs) {
      int i_new = i + vec[0];
      int j_new = j + vec[1];
      if (i_new >= 0 && i_new < rows && j_new >= 0 && j_new < cols && !visited[i_new][j_new] &&
          board[i_new][j_new] == word[depth]) {
        visited[i_new][j_new] = true;
        bool exist = dfs(board, i_new, j_new, depth + 1, word);
        visited[i_new][j_new] = false;
        if (exist) {
          return true;
        }
      }
    }
    return false;
  }

 public:
  bool exist(vector<vector<char>> &board, string word) {
    rows = board.size();
    cols = board[0].size();

    visited.resize(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (board[i][j] == word[0]) {
          visited[i][j] = true;
          bool exist = dfs(board, i, j, 1, word);
          visited[i][j] = false;
          if (exist) {
            return true;
          }
        }
      }
    }
    return false;
  }
};