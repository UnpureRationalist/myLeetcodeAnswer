#include <bits/stdc++.h>
using namespace std;

class Solution {
  int rows;
  int cols;

  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  inline bool legal(int row, int col) const { return row >= 0 && row < rows && col >= 0 && col < cols; }

  bool dfs(int row, int col, int depth, const string &word, const vector<vector<char>> &board,
           vector<vector<char>> &visited) {
    if (depth == word.length()) {
      return true;
    }
    for (int dir = 0; dir < 4; ++dir) {
      int nx = row + dirs[dir][0];
      int ny = col + dirs[dir][1];
      if (legal(nx, ny) && !visited[nx][ny] && board[nx][ny] == word[depth]) {
        visited[nx][ny] = 1;
        bool ans = dfs(nx, ny, depth + 1, word, board, visited);
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

    vector<vector<char>> visited(rows, vector<char>(cols, 0));

    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (board[row][col] == word[0]) {
          visited[row][col] = 1;
          bool ans = dfs(row, col, 1, word, board, visited);
          if (ans) {
            return true;
          }
          visited[row][col] = 0;
        }
      }
    }
    return false;
  }
};
