#include <bits/stdc++.h>
using namespace std;

long long mod5Num(int n, int mod) {
  int ans = n / 5;
  int left = n % 5;
  if (mod == 0 || left == 0) {
    return ans;
  }
  if (left >= mod) {
    ans += 1;
  }
  return ans;
}

// x % 5 == 0  y % 5 == 0  -->  (x + y) % 5 == 0
// x % 5 == 1  y % 5 == 4  -->  (x + y) % 5 == 0
// ...
// x % 5 == 4  y % 5 == 1  -->  (x + y) % 5 == 0
long long solve(int n, int m) {
  long long ans = 0;
  for (int i = 0; i < 5; ++i) {
    ans += mod5Num(n, i) * mod5Num(m, (5 - i) % 5);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  cout << solve(n, m) << endl;
  return 0;
}
