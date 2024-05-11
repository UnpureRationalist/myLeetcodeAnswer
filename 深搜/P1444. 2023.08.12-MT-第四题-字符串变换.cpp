#include <bits/stdc++.h>
using namespace std;

int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool legal(int x, int y, int rows, int cols) { return x >= 0 && x < rows && y >= 0 && y < cols; }

int getIndex(int x, int y, int rows, int cols) { return x * cols + y; }

void dfs(int x, int y, int rows, int cols, const string &str, vector<vector<char>> &visited) {
  visited[x][y] = 1;
  char c = str[getIndex(x, y, rows, cols)];
  for (int dir = 0; dir < 4; ++dir) {
    int nx = x + dirs[dir][0];
    int ny = y + dirs[dir][1];
    if (legal(nx, ny, rows, cols) && !visited[nx][ny] && c == str[getIndex(nx, ny, rows, cols)]) {
      dfs(nx, ny, rows, cols, str, visited);
    }
  }
}

int calculate(int rows, int cols, const string &str) {
  vector<vector<char>> visited(rows, vector<char>(cols, 0));
  int ans = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (!visited[i][j]) {
        dfs(i, j, rows, cols, str, visited);
        ++ans;
      }
    }
  }
  return ans;
}

void solve(int n, const string &str) {
  int ans = INT32_MAX;
  // 枚举 rows cols
  for (int rows = 1; rows <= n; ++rows) {
    if (n % rows == 0) {
      int cols = n / rows;
      int temp = calculate(rows, cols, str);
      ans = min(ans, temp);
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string str;
  cin >> str;
  solve(n, str);
  return 0;
}
