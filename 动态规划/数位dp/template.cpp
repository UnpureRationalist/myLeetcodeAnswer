#include <bits/stdc++.h>
using namespace std;

const int N = 1E3 + 10;

int dp[N][N], n;
string s;

int solve(int i, int mask, bool is_limit, bool is_num) {
  if (i == n) {
    return is_num;  // is_num 为 true 表示得到了一个合法数字
  }
  if (!is_limit && is_num && dp[i][mask] != -1) {
    return dp[i][mask];
  }
  int res = 0;
  if (!is_num) {  // 跳过当前数位
    res = solve(i + 1, mask, false, false);
  }
  int up = (is_limit) ? s[i] - '0' : 9;  // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
  for (int d = 1 - is_num; d <= up; d++) {  // 不能出现前导0
    if ((mask >> d & 1) == 0) {
      res += solve(i + 1, mask | (1 << d), is_limit && d == up, true);
    }
  }
  if (!is_limit && is_num) {
    dp[i][mask] = res;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  n = s.size();
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0, true, false) << endl;
  return 0;
}
