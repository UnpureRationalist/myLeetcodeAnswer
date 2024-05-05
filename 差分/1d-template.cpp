#include <algorithm>
#include <iostream>
using namespace std;

const int N = 100010;
int a[N], p[N];
int n, m;

void add(int l, int r, int c) {
  p[l] += c;
  p[r + 1] -= c;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];  // 输入 下标从 1 开始
  }
  for (int i = 1; i <= n; i++) {
    p[i] = a[i] - a[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    add(l, r, c);
  }
  for (int i = 1; i <= n; i++) {
    p[i] += p[i - 1];
    cout << p[i] << " ";
  }
  return 0;
}
