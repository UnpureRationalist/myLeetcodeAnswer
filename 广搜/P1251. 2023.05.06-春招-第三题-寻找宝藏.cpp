#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1010;

int dx[5] = {-1, 1, 0, 0, 0}, dy[5] = {0, 0, 1, -1, 0};  // 上下左右原地不动五个方向

int dist[N][N][3];  // 到达(x,y) 状态为z的最小距离

bool g[N][N];        // 标记有没有障碍物
string state[N][N];  // 标记每个点的状态

int n, k, sx, sy, ex, ey;

struct node {
  int x, y, time;
};

int bfs() {
  memset(dist, 0x3f, sizeof(dist));
  dist[sx][sy][0] = 0;
  queue<node> q;
  q.push({sx, sy, 0});
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    if (t.x == ex && t.y == ey) return t.time;
    int x = t.x, y = t.y, time = t.time;
    for (int i = 0; i < 5; i++) {
      int a = dx[i] + x, b = dy[i] + y, next_time = time + 1;
      if (a < 0 || a >= n || b < 0 || b >= n || g[a][b] || state[a][b][next_time % 3] == '1') continue;
      if (dist[a][b][next_time % 3] > dist[x][y][time % 3] + 1) {
        dist[a][b][next_time % 3] = dist[x][y][time % 3] + 1;
        q.push({a, b, next_time});
      }
    }
  }
  return -1;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    g[a][b] = true;
  }
  cin >> ex >> ey >> sx >> sy;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> state[i][j];
    }
  }
  cout << bfs() << endl;
  return 0;
}
