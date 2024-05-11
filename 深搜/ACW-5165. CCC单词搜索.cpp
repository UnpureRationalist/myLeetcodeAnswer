#include <bits/stdc++.h>
using namespace std;

int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int vertical[8][2] = {{2, 3}, {2, 3}, {0, 1}, {0, 1}, {5, 6}, {4, 7}, {4, 7}, {5, 6}};

bool legal(int x, int y, int rows, int cols) { return x >= 0 && x < rows && y >= 0 && y < cols; }

void dfs(int x, int y, int depth, int n, int rows, int cols, const string &word, const vector<vector<char>> &matrix,
         vector<vector<char>> &visited, int &ans, int dir, bool change) {
  if (depth == n) {
    ++ans;
    return;
  }
  // 第一步，必须向 dir 方向搜索
  int nx = x + dirs[dir][0];
  int ny = y + dirs[dir][1];
  if (depth == 1) {
    if (legal(nx, ny, rows, cols) && !visited[nx][ny] && matrix[nx][ny] == word[depth]) {
      visited[nx][ny] = 1;
      dfs(nx, ny, depth + 1, n, rows, cols, word, matrix, visited, ans, dir, false);
      visited[nx][ny] = 0;
    }
  } else {  // 后面步骤，要不继续 dir ，要不向垂直方向搜索
    if (change) {
      // 已经改变过搜索方向，必须继续向同方向搜索
      if (legal(nx, ny, rows, cols) && !visited[nx][ny] && matrix[nx][ny] == word[depth]) {
        visited[nx][ny] = 1;
        dfs(nx, ny, depth + 1, n, rows, cols, word, matrix, visited, ans, dir, true);
        visited[nx][ny] = 0;
      }
    } else {
      // 尚未改变搜索方向，有两种选择：同方向 或者 垂直方向

      // 同方向搜索
      if (legal(nx, ny, rows, cols) && !visited[nx][ny] && matrix[nx][ny] == word[depth]) {
        visited[nx][ny] = 1;
        dfs(nx, ny, depth + 1, n, rows, cols, word, matrix, visited, ans, dir, false);
        visited[nx][ny] = 0;
      }

      // 垂直方向
      for (int j = 0; j < 2; ++j) {
        int vert_dir = vertical[dir][j];
        int nx = x + dirs[vert_dir][0];
        int ny = y + dirs[vert_dir][1];
        if (legal(nx, ny, rows, cols) && !visited[nx][ny] && matrix[nx][ny] == word[depth]) {
          visited[nx][ny] = 1;
          dfs(nx, ny, depth + 1, n, rows, cols, word, matrix, visited, ans, vert_dir, true);
          visited[nx][ny] = 0;
        }
      }
    }
  }
}

void solve(int rows, int cols, const string &word, const vector<vector<char>> &matrix) {
  int ans = 0;
  int n = word.length();

  vector<vector<char>> visited(rows, vector<char>(cols, 0));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] == word[0]) {
        for (int dir = 0; dir < 8; ++dir) {
          visited[i][j] = 1;
          dfs(i, j, 1, n, rows, cols, word, matrix, visited, ans, dir, false);
          visited[i][j] = 0;
        }
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  string word;
  cin >> word;
  int rows, cols;
  cin >> rows >> cols;
  vector<vector<char>> matrix(rows, vector<char>(cols));
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cin >> matrix[i][j];
    }
  }
  solve(rows, cols, word, matrix);
  return 0;
}
