#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 32;

int f[N][N];

void init()  // 预处理求组合数
{
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (!j) {
        f[i][j] = 1;
      } else {
        f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
      }
    }
  }
}

int solve(int l, int r, int x, int y) {
  vector<bool> st(32, false);  // 标记每一位是否被填过数
  int ones = 0;                // 统计 1 的个数
  bool flag = false;           // 标记是否有解 true 为无解情况
  for (int i = 0; i < 32; i++) {
    if (!(y >> i & 1))  // y 的第 i 位是 0
    {
      st[i] = true;  // N 的第 i 位只能填 0
    }
  }
  for (int i = 0; i < 32; i++) {
    if (x >> i & 1)  // x 的第 i 位是 1
    {
      if (st[i])  // 存在矛盾
      {
        flag = true;
        break;
      }
      st[i] = true;  // N 的第 i 位只能填 1
      ones++;
    }
  }
  if (flag) {
    return 0;
  }
  int cnt = 0;  // 没有确定填 1 还是 0 的位置有多少
  for (int i = 0; i < 32; i++) {
    if (!st[i]) {
      cnt++;
    }
  }
  l -= ones;
  r -= ones;  // 还需要填 [l,r] 个 0 即可
  int res = 0;
  for (int i = l; i <= r; i++) {
    res += f[cnt][i];  // 排列组合
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  init();
  while (T--) {
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    cout << solve(l, r, x, y) << "\n";
  }
  return 0;
}
