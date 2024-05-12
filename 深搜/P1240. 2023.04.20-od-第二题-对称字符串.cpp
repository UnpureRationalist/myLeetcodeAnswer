#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool solve(ll n, ll k) {
  if (n == 1) {
    return true;
  }
  // n > 2
  ll half = 1ll << (n - 2);
  if (k < half) {
    return !solve(n - 1, k);
  }
  return solve(n - 1, k - half);
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    ll n, k;
    cin >> n >> k;
    cout << (solve(n, k) ? "red" : "blue") << "\n";
  }
  return 0;
}
