#include <bits/stdc++.h>
using namespace std;

int solve(long long x, long long y, long long target) {
  long long both = x + y;              // 采用操作 1 和操作 2
  long long single = x;                // 仅采用操作 1
  long long step = both + 2 * single;  // 周期为 3, 每经过三天，增加步长 step
  int ans = (target / step) * 3;
  target = target % step;
  if (target == 0) {
    return ans;
  }
  if (target <= both) {
    ++ans;
    return ans;
  }
  target -= both;
  ++ans;
  if (target <= single) {
    return ans + 1;
  }
  return ans + 2;
}

int main() {
  ios::sync_with_stdio(false);
  long long x, y, z;
  cin >> x >> y >> z;
  int ans = solve(x, y, z);
  cout << ans << endl;
  return 0;
}
