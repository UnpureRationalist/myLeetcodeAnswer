#include <bits/stdc++.h>
using namespace std;

int solve(long long n, long long k) {
  if (n == 1) {
    return 1;
  }
  long long mid = 1ll << (n - 1);
  if (k == mid) {
    return n;
  }
  if (k < mid) {
    return solve(n - 1, k);
  }
  return solve(n - 1, k - mid);
}

int main() {
  ios::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  cout << solve(n, k) << endl;
  return 0;
}
