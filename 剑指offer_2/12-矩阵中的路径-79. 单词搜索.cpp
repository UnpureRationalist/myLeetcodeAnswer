#include "header.h"

class Solution {
  int rows;
  int cols;
  vector<vector<char>> visited;

  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool dfs(vector<vector<char>> &board, const string &word, int found_len, int row, int col) {
    if (found_len == word.length()) {
      return true;
    }
    for (int i = 0; i < 4; ++i) {
      int next_row = row + dirs[i][0];
      int next_col = col + dirs[i][1];
      if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols && !visited[next_row][next_col] &&
          board[next_row][next_col] == word[found_len]) {
        visited[next_row][next_col] = 1;
        bool found = dfs(board, word, found_len + 1, next_row, next_col);
        visited[next_row][next_col] = 0;
        if (found) {
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
    visited.resize(rows, vector<char>(cols, 0));
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (board[row][col] == word[0]) {
          visited[row][col] = 1;
          bool found = dfs(board, word, 1, row, col);
          visited[row][col] = 0;
          if (found) {
            return true;
          }
        }
      }
    }
    return false;
  }
};
