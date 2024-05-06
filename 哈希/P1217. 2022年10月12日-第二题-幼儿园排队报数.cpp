#include <bits/stdc++.h>
using namespace std;

// 40 ≤ nums[i] ≤ 110
void solve(int n, const vector<int> &nums) {
  vector<int> result(n, 0);
  vector<int> num2times(120, 0);
  for (int i = n - 1; i >= 0; --i) {
    int num = nums[i];
    int sum = 0;
    for (int j = 40; j < num; ++j) {
      sum += num2times[j];
    }
    num2times[num]++;
    result[i] = sum;
  }
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << result[i];
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  solve(n, nums);

  return 0;
}
