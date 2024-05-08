#include <bits/stdc++.h>
using namespace std;

long long s[20];

void init() {
  long long times = 1;
  for (int i = 1; i <= 14; i++) {
    s[i] = i * 9 * times;
    times *= 10;
  }
}

// 计算 [1, x] 共有多少个字符
long long numOfChars(long long x) {
  long long res = x - 1;  // 逗号 + 分号 的数量
  long long m = to_string(x).size();
  for (int i = 1; i < m; i++) {
    res += s[i];
  }
  long long val = pow(10ll, m - 1);
  res += (x - val + 1) * m;
  return res;
}

// 返回字符串前 n 个字符中有多少个逗号 , 和 分号 ;
pair<long long, long long> numOfSymbol(long long n) {
  long long left = 0, right = 1e12;
  long long ans = 0;
  while (left <= right) {
    long long mid = left + (right - left) / 2;
    bool ok = numOfChars(mid) <= n;
    if (ok && (numOfChars(mid + 1) > n)) {
      ans = mid;
      break;
    }
    if (ok) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  // 第 ans 个字符是否恰好是数字
  long long total = (numOfChars(ans) < n) ? ans : ans - 1;  // 计算总共有多少个字符(有 x 个数字就有 x-1 个字符)
  long long semicolon = total / 3;
  long long comma = total - semicolon;
  return {comma, semicolon};  // 返回分号和逗号的数量
}

void solve(long long left, long long right) {
  auto [comma1, semicolon1] = numOfSymbol(right);
  auto [comma2, semicolon2] = numOfSymbol(left - 1);
  auto comma = comma1 - comma2;
  auto semicolon = semicolon1 - semicolon2;
  cout << comma << " " << semicolon << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  init();
  int T;
  cin >> T;
  while (T--) {
    long long left, right;
    cin >> left >> right;
    solve(left, right);
  }
  return 0;
}