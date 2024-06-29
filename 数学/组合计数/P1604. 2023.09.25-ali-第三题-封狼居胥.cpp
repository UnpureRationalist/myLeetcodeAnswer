#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

int n;
string s;
vector<int> a;
ll jc[N], fjc[N];

ll ksm(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

ll C(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  if (b == 0 || a == b) return 1;
  return jc[a] * fjc[a - b] % mod * fjc[b] % mod;
}

int main() {
  ios::sync_with_stdio(false);
  jc[0] = 1;
  for (int i = 1; i < N; i++) jc[i] = jc[i - 1] * i % mod;
  fjc[N - 1] = ksm(jc[N - 1], mod - 2);
  for (int i = N - 2; i; i--) fjc[i] = fjc[i + 1] * (i + 1) % mod;
  cin >> n >> s;
  int all = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') continue;
    int j = i;
    while (j + 1 < s.size() && s[j + 1] == '0') {
      j++;
    }
    a.push_back(j - i + 1);
    i = j;
    all += a.back();
  }
  ll ans = 1;
  for (int t : a) {
    ans = ans * C(all, t) % mod * ksm(2, t - 1) % mod;
    all -= t;
  }
  if (s[0] == '0') {
    ans = ans * ksm(ksm(2, a[0] - 1), mod - 2) % mod;
  }
  if (s.back() == '0') {
    ans = ans * ksm(ksm(2, a.back() - 1), mod - 2) % mod;
  }
  cout << ans << endl;
}
