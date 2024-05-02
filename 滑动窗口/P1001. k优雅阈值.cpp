#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, const vector<int> &nums) {
  int ans = 0;
  unordered_map<int, int> num2times;
  for (int l = 0, r = 0; r < n; ++r) {
    num2times[nums[r]]++;
    // 移动左指针并更新答案
    while (num2times[nums[r]] >= k) {
      ans += n - r;  // r 右侧都满足条件
      auto iter = num2times.find(nums[l]);
      (iter->second)--;
      if (iter->second == 0) {
        num2times.erase(iter);
      }
      ++l;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  int k;
  cin >> n >> k;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  int ans = solve(n, k, nums);
  cout << ans << endl;
  return 0;
}
