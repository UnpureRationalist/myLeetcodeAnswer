#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
char matrix[MAXN][MAXN];
int rows;
int cols;

char visited[MAXN][MAXN];

int dirs[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool legal(int x, int y) { return x >= 0 && x < rows && y >= 0 && y < cols; }

void dfs(int x, int y) {
  matrix[x][y] = '0';
  for (int dir = 0; dir < 8; ++dir) {
    int nx = x + dirs[dir][0];
    int ny = y + dirs[dir][1];
    if (legal(nx, ny) && matrix[nx][ny] == '1') {
      dfs(nx, ny);
    }
  }
}

void solve() {
  int ans = 0;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] == '1') {
        dfs(i, j);
        ++ans;
      }
    }
  }
  cout << ans << endl;
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
