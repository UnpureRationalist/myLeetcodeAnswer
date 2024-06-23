#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
int n;

ll cal(ll b) {
  ll a = 10;
  ll res = 45 * b % mod;  // 45 = 1 + 2 + 3 + ... + 9
  b--;
  while (b)  // 快速幂
  {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  cout << cal(n / 2) * cal((n + 1) / 2) % mod;
  return 0;
}
