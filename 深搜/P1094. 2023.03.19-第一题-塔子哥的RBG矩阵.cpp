#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
char matrix[MAXN][MAXN];

int rows;
int cols;

int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool legal(int x, int y) { return x >= 0 && x < rows && y >= 0 && y < cols; }

void dfs(int x, int y, vector<vector<char>> &visited) {
  visited[x][y] = 1;
  char c = matrix[x][y];
  for (int i = 0; i < 4; ++i) {
    int nx = x + dirs[i][0];
    int ny = y + dirs[i][1];
    if (legal(nx, ny) && !visited[nx][ny] && matrix[nx][ny] == c) {
      dfs(nx, ny, visited);
    }
  }
}

int calculate() {
  vector<vector<char>> visited(rows, vector<char>(cols, 0));
  int ans = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (!visited[i][j]) {
        dfs(i, j, visited);
        ++ans;
      }
    }
  }
  return ans;
}

void solve() {
  int real = calculate();

  // GB 全部赋值为 G
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] == 'B') {
        matrix[i][j] = 'G';
      }
    }
  }
  int seen = calculate();
  cout << real - seen << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> rows >> cols;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cin >> matrix[i][j];
    }
  }
  solve();
  return 0;
}
