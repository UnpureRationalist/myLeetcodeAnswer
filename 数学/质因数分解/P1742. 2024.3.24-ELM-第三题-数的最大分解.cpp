#include <bits/stdc++.h>
using namespace std;

long long solve(int x) {
  vector<pair<int, int>> v;  // 记录质因子和其出现的次数
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) {
        cnt++;
        x /= i;
      }
      v.push_back({i, cnt});
    }
    if (x == 1) {
      break;
    }
  }
  if (x > 1) {
    v.push_back({x, 1});
  }
  if (v.size() == 1) {
    return v[0].second * 2;  // 只有一个质因子
  }
  long long res = 1;
  for (const auto &[factor, num] : v) {
    res *= (num + 1);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int x;
    cin >> x;
    cout << solve(x) << "\n";
  }
  return 0;
}
