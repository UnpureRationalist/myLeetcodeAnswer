#include <bits/stdc++.h>
using namespace std;

bool isSame(const vector<int> &nums) {
  int num = nums[0];
  auto iter = upper_bound(nums.begin(), nums.end(), num);
  return iter == nums.end();
}

long long getOperations(const vector<int> &nums, int left, int right) {
  int mid_idx = left + (right - left) / 2;
  int num = nums[mid_idx];
  long long ans = 0;
  for (int i = left; i <= right; ++i) {
    ans += abs(nums[i] - num);
  }
  return ans;
}

long long solve(int n, const vector<int> &nums) {
  if (isSame(nums)) {
    return 1;
  }
  // 两种选择：去掉 min 或者去掉 max
  long long ans1 = getOperations(nums, 1, n - 1);
  long long ans2 = getOperations(nums, 0, n - 2);
  return min(ans1, ans2);
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  cout << solve(n, nums) << endl;
  return 0;
}
