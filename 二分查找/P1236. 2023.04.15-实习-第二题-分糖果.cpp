#include <bits/stdc++.h>
using namespace std;

// 判断 n 个人, a b 两种糖果, 每人至少分 k 个是否够分
bool enough(int n, int a, int b, int k) { return n <= (a / k + b / k); }

void solve(int n, int a, int b) {
  int left = 1;
  int right = (a + b) / n;
  int ans = 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (enough(n, a, b, mid) && !enough(n, a, b, mid + 1)) {
      ans = mid;
      break;
    }
    if (enough(n, a, b, mid)) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, a, b;
    cin >> n >> a >> b;
    solve(n, a, b);
  }
  return 0;
}
