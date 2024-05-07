#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int> &nums, const vector<long long> &presum, long long max_response, long long k) {
  int n = nums.size();
  int idx = upper_bound(nums.begin(), nums.end(), k) - nums.begin();
  long long pre_sum = presum[idx];
  long long post_sum = (n - idx) * k;
  long long total = pre_sum + post_sum;
  return total <= max_response;
}

long long solve(const vector<int> &nums, int max_response) {
  int n = nums.size();
  vector<long long> presum(n + 1, 0);  // presum[i] 表示 nums[0, i) 前缀和
  for (int i = 1; i <= n; ++i) {
    presum[i] = presum[i - 1] + nums[i - 1];
  }

  if (presum[n] <= max_response) {
    return -1;
  }

  long long ans = 0;
  long long left = 0;
  long long right = nums.back();  // nums 中最大值

  while (left <= right) {
    int mid = left + (right - left) / 2;
    bool ok = check(nums, presum, max_response, mid);
    if (ok && !check(nums, presum, max_response, mid + 1)) {
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
  vector<int> nums;
  int temp;
  while (cin >> temp) {
    nums.emplace_back(temp);
  }
  int max_response = nums.back();
  nums.pop_back();
  sort(nums.begin(), nums.end());
  int ans = solve(nums, max_response);
  cout << ans << endl;
  return 0;
}
