#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1E5 + 10;
int n, a[N], f[N], k;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  int res = 1e9;

  for (int i = 0; i <= k; i++) {
    int minv = 1e9, maxv = 0;
    if (i > 0) {
      minv = min(minv, a[0] * 2);
      maxv = max(maxv, a[i - 1] * 2);
    }
    if (k > i) {
      minv = min(minv, a[n - (k - i)] / 2);
      maxv = max(maxv, a[n - 1] / 2);
    }
    if (k < n) {
      minv = min(minv, a[i]);
      maxv = max(maxv, a[n - (k - i) - 1]);
    }
    res = min(res, maxv - minv);
  }

  cout << res << endl;
  return 0;
}
