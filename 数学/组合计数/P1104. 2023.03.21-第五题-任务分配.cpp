#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1E5 + 10, mod = 1e9 + 7;

int n, k;

ll fact[N], infact[N];

ll qmi(ll a, ll b, ll p) {
  ll res = 1, t = a;
  while (b) {
    if (b & 1) res = (res * t) % p;
    t = (t * t) % p;
    b >>= 1;
  }
  return res;
}

void init()  // 逆元预处理
{
  fact[0] = infact[0] = 1;
  for (int i = 1; i <= n / 2; i++) {
    fact[i] = (ll)fact[i - 1] * i % mod;
    infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
  }
}

ll c_caluc(int a, int b)  // 计算C(a,b)
{
  return (ll)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

int main() {
  cin >> n >> k;
  if (n & 1 || k > n)
    puts("0");  // 无法分割成2个消耗一样的任务
  else {
    // 考虑f[i]为 n/2分成i份的方案数  f[i]=C(n/2-1,i)  从n/2-1个缝隙中选i-1个缝隙分开
    // 答案就是 f[1]*f[k-1]+f[2]*f[k-2]+...+f[k-1]*f[1]
    ll res = 0;
    init();
    for (int i = 1; i <= k - 1; i++) {
      if (n / 2 < i || n / 2 < k - i) continue;
      ll left = c_caluc(n / 2 - 1, i - 1), right = c_caluc(n / 2 - 1, k - i - 1);
      res = (res + (left * right) % mod) % mod;
    }
    cout << res << endl;
  }
  return 0;
}
