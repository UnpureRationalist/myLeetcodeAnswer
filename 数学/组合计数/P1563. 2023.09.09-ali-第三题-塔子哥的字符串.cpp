#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, N = 1E5 + 10;

long long qmi(long long a, long long b, long long p) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  vector<int> cnts(26, 0);
  for (char &ch : s) {
    cnts[ch - 'a']++;
  }
  long long res = 0;
  for (int i = 0; i < 26; i++) {
    if (cnts[i] < 2) {
      continue;
    }
    long long cnt = 1ll * cnts[i] * (cnts[i] - 1) / 2;
    for (int j = 0; j < 26; j++) {  // 枚举其他字符出现的次数0,1,3,...(就是不能出现2次)
      if (j == i) {
        continue;
      }
      long long cur = (qmi(2, cnts[j], mod) - 1ll * cnts[j] * (cnts[j] - 1) / 2 + mod) % mod;
      cnt = (cnt * cur) % mod;
    }
    res = (res + cnt) % mod;
  }
  cout << res << endl;
  return 0;
}
