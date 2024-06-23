#include <iostream>
using namespace std;

typedef long long ll;

// 求 a^b%p 结果
ll qmi(ll a, ll b, ll p) {
  ll res = 1, t = a;
  while (b) {
    if (b & 1) res = (res * t) % p;
    t = (t * t) % p;
    b >>= 1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b, q;
    cin >> a >> b >> q;
    cout << qmi(a, b, q) << endl;
  }
  return 0;
}
