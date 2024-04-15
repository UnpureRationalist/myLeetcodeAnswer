#include "header.h"

class Solution {
  int rows;
  int cols;

  vector<vector<char>> visited;

  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool isLegal(int x, int y) const { return x >= 0 && x < rows && y >= 0 && y < cols; }

  bool dfs(vector<vector<char>> &board, string &word, int depth, int x, int y) {
    if (depth + 1 == word.length()) {
      return true;
    }
    bool ans = false;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dirs[i][0];
      int ny = y + dirs[i][1];
      if (isLegal(nx, ny) && !visited[nx][ny] && word[depth + 1] == board[nx][ny]) {
        visited[nx][ny] = 1;
        ans = dfs(board, word, depth + 1, nx, ny);
        visited[nx][ny] = 0;
        if (ans) {
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
    visited = vector<vector<char>>(rows, vector<char>(cols, 0));
    bool ok = false;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (word[0] == board[i][j]) {
          visited[i][j] = 1;
          ok = dfs(board, word, 0, i, j);
          visited[i][j] = 0;
        }
        if (ok) {
          return true;
        }
      }
    }
    return false;
  }
};
