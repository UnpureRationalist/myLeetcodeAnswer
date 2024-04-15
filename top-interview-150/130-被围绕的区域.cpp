#include "header.h"

class Solution {
  int m;
  int n;

  vector<vector<bool>> visited;

  bool inEdge(int x, int y) { return x == 0 || y == 0 || x == m - 1 || y == n - 1; }

  bool inEdge(vector<pair<int, int>> &lst) {
    for (const auto &[x, y] : lst) {
      if (inEdge(x, y)) {
        return true;
      }
    }
    return false;
  }

  bool isLegal(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

  int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  void dfs(vector<vector<char>> &board, int x, int y, vector<pair<int, int>> &lst) {
    for (int i = 0; i < 4; ++i) {
      int newx = x + dirs[i][0];
      int newy = y + dirs[i][1];
      if (isLegal(newx, newy) && board[newx][newy] == 'O' && !visited[newx][newy]) {
        visited[newx][newy] = true;
        lst.emplace_back(newx, newy);
        dfs(board, newx, newy, lst);
      }
    }
  }

 public:
  void solve(vector<vector<char>> &board) {
    m = board.size();
    n = board[0].size();
    visited = vector<vector<bool>>(m, vector<bool>(n, false));
    for (int i = 1; i < m - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (board[i][j] == 'O' && !visited[i][j]) {
          vector<pair<int, int>> lst;
          visited[i][j] = true;
          lst.emplace_back(i, j);
          dfs(board, i, j, lst);
          if (!inEdge(lst)) {
            for (const auto &[x, y] : lst) {
              board[x][y] = 'X';
            }
          }
        }
      }
    }
  }
};

class Solution {
 public:
  int m, n;

  void dfs(vector<vector<char>> &board, int x, int y) {
    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
      return;
    }
    board[x][y] = 'A';
    dfs(board, x + 1, y);
    dfs(board, x - 1, y);
    dfs(board, x, y + 1);
    dfs(board, x, y - 1);
  }

  void solve(vector<vector<char>> &board) {
    m = board.size();
    if (m == 0) {
      return;
    }
    n = board[0].size();
    for (int i = 0; i < m; i++) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }
    for (int i = 1; i < n - 1; i++) {
      dfs(board, 0, i);
      dfs(board, m - 1, i);
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'A') {
          board[i][j] = 'O';
        } else if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};
