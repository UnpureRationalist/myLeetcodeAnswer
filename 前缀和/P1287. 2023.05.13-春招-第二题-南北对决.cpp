#include <bits/stdc++.h>
using namespace std;

void solve(int n, const vector<int> &nums) {
  vector<int> leftOne(n, 0);   // leftOne[i] 表示 nums[i] 左侧，即 [0, i - 1] 区间内 1 的数量
  vector<int> rightOne(n, 0);  // rightOne[i] 表示 nums[i] 右侧，即 [i + 1, n - 1] 区间内 1 的数量
  for (int i = 1; i < n; ++i) {
    leftOne[i] = leftOne[i - 1] + (nums[i - 1] == 1);
  }
  for (int i = n - 2; i >= 0; --i) {
    rightOne[i] = rightOne[i + 1] + (nums[i + 1] == 1);
  }
  vector<int> winTimes(n, 0);
  for (int i = 0; i < n; ++i) {
    if (nums[i]) {
      int leftWin = i - leftOne[i];  // 左侧不同门派的数量
      int rightWin = rightOne[i];    // 右侧同一门派的数量
      winTimes[i] = leftWin + rightWin;
    } else {
      int leftWin = leftOne[i];
      int rightWin = (n - i - 1) - rightOne[i];
      winTimes[i] = leftWin + rightWin;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << winTimes[i];
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
    }
    solve(n, nums);
  }
  return 0;
}
