#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int> &nums, const vector<long long> &presum, long long max_sum, long long k) {
  int n = nums.size();
  int idx = upper_bound(nums.begin(), nums.end(), k) - nums.begin();
  long long pre_sum = presum[idx];
  long long post_sum = (n - idx) * k;
  long long total = pre_sum + post_sum;
  return total <= max_sum;
}

int solve(const vector<int> &nums, int max_sum) {
  int n = nums.size();
  vector<long long> presum(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    presum[i] = presum[i - 1] + nums[i - 1];
  }
  if (presum[n] <= max_sum) {
    return -1;
  }
  int ans = 0;
  int left = 0;
  int right = nums.back();
  while (left <= right) {
    int mid = left + (right - left) / 2;
    bool ok = check(nums, presum, max_sum, mid);
    if (ok && !check(nums, presum, max_sum, mid + 1)) {
      ans = mid;
      break;
    }
    if (ok) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n, max_sum;
  cin >> n >> max_sum;
  vector<int> nums(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  int ans = solve(nums, max_sum);
  cout << ans << endl;
  return 0;
}
