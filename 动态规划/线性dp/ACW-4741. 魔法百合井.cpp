#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 10;

int T, dist[N], n;

void solve(int i) {
  cin >> n;
  queue<int> q;
  memset(dist, 0x3f, sizeof(dist));

  dist[1] = 1;
  for (int i = 1; i <= n; i++) {
    dist[i] = i;
  }

  for (int i = 2; i <= n; i++) {
    dist[i] = min(dist[i], dist[i - 1] + 1);
    int x = i;
    for (int j = 1; (j + 1) * x <= n; j++) {
      dist[(j + 1) * x] = min(dist[j * x + i], dist[x] + 4 + j * 2);
    }
  }
  printf("Case #%d: %d\n", i, dist[n]);
}

int main() {
  cin >> T;
  for (int i = 1; i <= T; i++) {
    solve(i);
  }
  return 0;
}
