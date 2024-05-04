#include <bits/stdc++.h>
using namespace std;

int solve(int n, const vector<int> &nums) {
  if (n == 2) {
    return 0;
  }
  vector<int> postMax(n, nums.back());  // postMax[i] 表示 nums[i] 右侧，即 [i + 1, n - 1] 区间内的最大值
  vector<int> postMin(n, nums.back());  // postMin[i] 表示 nums[i] 右侧，即 [i + 1, n - 1] 区间内的最小值
  for (int i = n - 2; i >= 0; --i) {
    postMax[i] = max(postMax[i + 1], nums[i + 1]);
    postMin[i] = min(postMin[i + 1], nums[i + 1]);
  }
  int pre_min = nums[0];
  int pre_max = nums[0];
  int ans = INT32_MAX;
  for (int i = 0; i < n - 1; ++i) {
    // 枚举合并 nums[i] 和 nums[i + 1]
    int sum = nums[i] + nums[i + 1];
    int min_val;
    int max_val;
    if (i == 0) {
      min_val = min(sum, postMin[i + 1]);
      max_val = max(sum, postMax[i + 1]);
    } else if (i == n - 2) {
      min_val = min(sum, pre_min);
      max_val = max(sum, pre_max);
    } else {
      min_val = min(pre_min, min(sum, postMin[i + 1]));
      max_val = max(pre_max, max(sum, postMax[i + 1]));
    }
    pre_min = min(pre_min, nums[i]);
    pre_max = max(pre_max, nums[i]);
    ans = min(ans, max_val - min_val);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  int ans = solve(n, nums);
  cout << ans << endl;
  return 0;
}
