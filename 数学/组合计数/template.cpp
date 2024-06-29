#include <algorithm>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

long long fac[N], ifac[N];  // 预处理阶乘和阶乘的逆元

long long qmi(long long a, long long b) {  // 快速幂
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

long long C(int a, int b) {  // 求C(a,b)的组合数
  return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

int main() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    ifac[i] = ifac[i - 1] * qmi(i, MOD - 2) % MOD;
  }
  cout << C(5, 2) << endl;
  return 0;
}
