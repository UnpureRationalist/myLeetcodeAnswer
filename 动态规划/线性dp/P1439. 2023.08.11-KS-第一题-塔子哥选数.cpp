#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // 初始化有一个元素，真实的数下标从 1 开始
  vector<int> a(1);
  int x;
  while (cin >> x) {
    a.push_back(x);
  }

  int n = int(a.size()) - 1;
  // f[i] 表示只考虑前 i 个数可以获得的最大值。
  vector<long long> f(n + 1, 0);
  vector<int> ok(n + 1, 0);

  f[0] = 0;
  f[1] = a[1];
  ok[1] = 1;
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i - 1];
    if (f[i - 2] + a[i] >= f[i - 1]) {
      // 这里表示 f[i] 是选择了第 i 个数
      f[i] = f[i - 2] + a[i];
      ok[i] = 1;
    }
  }

  vector<int> ans;
  int cur = n;
  // 从后往前考虑每个被选了的数
  while (cur > 0) {
    if (ok[cur]) {
      ans.push_back(cur - 1);
      cur -= 2;
    } else {
      cur -= 1;
    }
  }

  // 翻转一下，就是正序
  reverse(ans.begin(), ans.end());
  for (auto &u : ans) cout << u << " ";
  cout << "\n";
  cout << f[n] << "\n";

  return 0;
}
