#include <bits/stdc++.h>
using namespace std;

int solve(int n, const vector<int> &nums) {
  int ans = n;
  for (int l = 0, r = 0; r < n; ++r) {
    while (nums[r] - nums[l] + 1 > n) {  // 如果 nums[r] 与 nums[l] 之间的羊圈数量 大于 n，移动左指针
      ++l;
    }
    ans = min(ans, n - (r - l + 1));
  }
  return ans;
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
  int ans = solve(n, nums);
  cout << ans << endl;
  return 0;
}
