#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
#define x first
#define y second
typedef long long ll;

const int N = 1E5 + 10;
ll a, b, s[20], T;

ll pow(ll a, ll b) {
  ll res = 1;
  for (int i = 0; i < b; i++) res *= a;
  return res;
}

void init() {
  for (int i = 1; i <= 14; i++) {
    s[i] = i * 9 * pow(10, i - 1);
  }
}

ll f(ll x)  // 计算1-x共有多少个字符
{
  ll res = x - 1;  // 逗号+分号的数量
  int m = to_string(x).size();
  for (int i = 1; i < m; i++) {
    res += s[i];
  }
  ll val = pow(10, m - 1);
  res += (x - val + 1) * m;
  return res;
}

vector<ll> get_val(ll a) {
  ll l = 0, r = 1e12;
  while (l < r) {
    ll mid = l + r + 1 >> 1;
    if (f(mid) <= a)
      l = mid;
    else
      r = mid - 1;
  }
  ll total = (f(l) < a) ? l : l - 1;  // 计算总共有多少个字符(有x个数字就有x-1个字符)
  ll x = total / 3, y = total - x;
  return {x, y};  // 返回分号和逗号的数量
}

int main() {
  init();
  cin >> T;
  while (T--) {
    cin >> a >> b;
    auto u = get_val(a - 1), v = get_val(b);
    printf("%lld %lld\n", v[1] - u[1], v[0] - u[0]);
  }
  return 0;
}
