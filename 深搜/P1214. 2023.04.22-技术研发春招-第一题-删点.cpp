#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n + 1, 0);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    nums[u]++;
    nums[v]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (nums[i] == 2) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
