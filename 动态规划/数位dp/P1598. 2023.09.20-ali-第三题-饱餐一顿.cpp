#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;

int f[N][10], n, res;

string s;

int dp(int i, int mask, bool is_limit, bool is_num) {
  if (i == n) {
    return is_num;  // is_num 为 true 表示得到了一个合法数字
  }
  if (!is_limit && is_num && f[i][mask] != -1) {
    return f[i][mask];
  }
  int res = 0;
  if (!is_num) {  // 跳过当前数位
    res = dp(i + 1, mask, false, false);
  }
  int up = (is_limit) ? s[i] - '0' : 9;  // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
  for (int d = 1 - is_num; d <= up; d++) {  // 不能出现前导0
    if (d != mask) {
      res = (res + dp(i + 1, d, is_limit && d == up, true)) % mod;
    }
  }
  if (!is_limit && is_num) {
    f[i][mask] = res;
  }
  return res;
}

int main() {
  cin >> s;
  n = s.size();
  memset(f, -1, sizeof(f));
  cout << dp(0, 0, true, false) << endl;
  return 0;
}
