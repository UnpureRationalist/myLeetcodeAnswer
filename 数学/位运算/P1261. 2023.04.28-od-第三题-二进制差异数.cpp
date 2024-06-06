#include <bits/stdc++.h>
using namespace std;

long long solve(int n, vector<int> &nums) {
  vector<int> bits(32, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 31; j >= 0; j--) {  // 枚举最高位为 1 的位置
      if ((nums[i] >> j) & 1) {
        bits[j]++;
        nums[i] = j;
        break;
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += n - bits[nums[i]];
  }
  res /= 2;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (auto &num : nums) {
    cin >> num;
  }
  cout << solve(n, nums) << endl;
  return 0;
}
