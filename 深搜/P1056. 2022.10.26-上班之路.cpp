#include <bits/stdc++.h>
using namespace std;

int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool legal(int x, int y, int rows, int cols) { return x >= 0 && x < rows && y >= 0 && y < cols; }

bool dfs(int last_dir, int x, int y, int tx, int ty, int change_dirs, int clear_barriers, int rows, int cols,
         const vector<vector<char>> &matrix, vector<vector<char>> &visited) {
  if (x == tx && y == ty) {
    return true;
  }

  if (last_dir == -1) {
    // 第一步，可以选择任意方向
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dirs[dir][0];
      int ny = y + dirs[dir][1];
      if (legal(nx, ny, rows, cols) && !visited[nx][ny]) {
        bool ok = false;
        if (matrix[nx][ny] == '.') {
          visited[nx][ny] = 1;
          ok = dfs(dir, nx, ny, tx, ty, change_dirs, clear_barriers, rows, cols, matrix, visited);
          visited[nx][ny] = 0;
        }
        if (ok) {
          return true;
        }
        if (matrix[nx][ny] == '*' && clear_barriers > 0) {
          visited[nx][ny] = 1;
          ok = dfs(dir, nx, ny, tx, ty, change_dirs, clear_barriers - 1, rows, cols, matrix, visited);
          visited[nx][ny] = 0;
        }
        if (ok) {
          return true;
        }
        if (matrix[nx][ny] == 'T') {
          return true;
        }
      }
    }
  } else {
    // 不是第一步，必须考虑转向次数
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dirs[dir][0];
      int ny = y + dirs[dir][1];
      if (legal(nx, ny, rows, cols) && !visited[nx][ny]) {
        bool ok = false;
        if (last_dir == dir) {
          if (matrix[nx][ny] == '.') {
            visited[nx][ny] = 1;
            ok = dfs(dir, nx, ny, tx, ty, change_dirs, clear_barriers, rows, cols, matrix, visited);
            visited[nx][ny] = 0;
          }
          if (ok) {
            return true;
          }
          if (matrix[nx][ny] == '*' && clear_barriers > 0) {
            visited[nx][ny] = 1;
            ok = dfs(dir, nx, ny, tx, ty, change_dirs, clear_barriers - 1, rows, cols, matrix, visited);
            visited[nx][ny] = 0;
          }
          if (ok) {
            return true;
          }
          if (matrix[nx][ny] == 'T') {
            return true;
          }
        } else if (change_dirs > 0) {
          if (matrix[nx][ny] == '.') {
            visited[nx][ny] = 1;
            ok = dfs(dir, nx, ny, tx, ty, change_dirs - 1, clear_barriers, rows, cols, matrix, visited);
            visited[nx][ny] = 0;
          }
          if (ok) {
            return true;
          }
          if (matrix[nx][ny] == '*' && clear_barriers > 0) {
            visited[nx][ny] = 1;
            ok = dfs(dir, nx, ny, tx, ty, change_dirs - 1, clear_barriers - 1, rows, cols, matrix, visited);
            visited[nx][ny] = 0;
          }
          if (ok) {
            return true;
          }
          if (matrix[nx][ny] == 'T') {
            return true;
          }
        }
      }
    }
  }

  return false;
}

void solve(int sx, int sy, int tx, int ty, int change_dirs, int clear_barriers, int rows, int cols,
           const vector<vector<char>> &matrix) {
  vector<vector<char>> visited(rows, vector<char>(cols, 0));
  bool ans = dfs(-1, sx, sy, tx, ty, change_dirs, clear_barriers, rows, cols, matrix, visited);
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);

  int change_dirs;
  int clear_barriers;
  cin >> change_dirs >> clear_barriers;

  int rows, cols;
  cin >> rows >> cols;

  vector<vector<char>> matrix(rows, vector<char>(cols));
  int sx, sy;
  int tx, ty;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (matrix[i][j] == 'T') {
        tx = i;
        ty = j;
      }
    }
  }

  solve(sx, sy, tx, ty, change_dirs, clear_barriers, rows, cols, matrix);

  return 0;
}
