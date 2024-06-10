#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;  // 记录质因子和其出现的次数(也可以使用哈希表)

void solve(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      int cnt = 0;
      while (x % i == 0) {
        cnt++;
        x /= i;
      }
      v.push_back({i, cnt});
    }
  }
  if (x > 1) {
    v.push_back({x, 1});
  }
}

int main() {
  int n;
  cin >> n;
  solve(n);
  for (auto &t : v) {  // 输出每个质数以及其出现的次数
    cout << t.first << " " << t.second << endl;
  }
  return 0;
}
