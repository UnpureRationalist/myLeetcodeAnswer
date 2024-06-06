#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  ll a, b;
  cin >> a >> b;
  int res = 0;
  for (int len = 2; len <= 63; len++)  // 枚举二进制长度
  {
    ll num = (1ll << len) - 1;         // 全 1 序列
    for (int j = 0; j < len - 1; j++)  // 不能含有前导 0 因此只能枚举第 0 ~ n-1 位
    {
      ll val = num ^ (1ll << j);  // 当前位置 0
      if (val >= a && val <= b) res++;
    }
  }
  cout << res << endl;
  return 0;
}
