#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 1e6 + 10;

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(MAX_LEN, 0);
  int from, to;
  int end = 0;
  for (int i = 0; i < n; ++i) {
    cin >> from >> to;
    end = max(end, to);
    nums[from] += 1;
    nums[to + 1] -= 1;
  }
  long long ans = 0;
  int i = 0;
  while (nums[i] == 0) {
    ++i;
  }
  int sum = 0;
  for (; i <= end; ++i) {
    sum += nums[i];
    if (sum == 0) {
      ans += 1;
    } else if (sum == 1) {
      ans += 3;
    } else {
      ans += 4;
    }
  }
  cout << ans << endl;
  return 0;
}
