#include <bits/stdc++.h>
using namespace std;

int maxSubsetSumLessEqualTarget(const vector<int> &nums, int target, vector<int> &idx_lst1, vector<int> &idx_lst2) {
  int n = nums.size();
  vector<int> dp(target + 1, 0);
  vector<vector<bool>> select(n + 1, vector<bool>(target + 1, false));
  for (int i = 0; i < n; ++i) {
    for (int j = target; j >= nums[i]; --j) {
      if (dp[j - nums[i]] + nums[i] > dp[j]) {
        dp[j] = dp[j - nums[i]] + nums[i];
        select[i][j] = true;
      }
    }
  }
  int last = n - 1;
  int left = dp[target];
  while (last >= 0) {
    if (select[last][left]) {
      idx_lst1.push_back(last);
      left -= nums[last];
    } else {
      idx_lst2.push_back(last);
    }
    --last;
  }
  return dp[target];
}

void solve(int n, const vector<int> &nums) {
  int sum = accumulate(nums.begin(), nums.end(), 0);
  int target = sum / 2;
  vector<int> idx_lst1, idx_lst2;
  int max_subset_sum = maxSubsetSumLessEqualTarget(nums, target, idx_lst1, idx_lst2);
  int ans = sum - 2 * max_subset_sum;
  cout << ans << "\n";

  priority_queue<pair<int, int>> q1, q2;
  for (const auto &idx : idx_lst1) {
    q1.emplace(nums[idx], idx);
  }
  for (const auto &idx : idx_lst2) {
    q2.emplace(nums[idx], idx);
  }
  vector<pair<int, int>> results;
  while (!q1.empty() && !q2.empty()) {
    auto [x, idx1] = q1.top();
    q1.pop();
    auto [y, idx2] = q2.top();
    q2.pop();

    results.emplace_back(idx1 + 1, idx2 + 1);

    if (x != y) {
      if (x > y) {
        q1.emplace(x - y, idx1);
      } else {
        q2.emplace(y - x, idx2);
      }
    }
  }
  cout << results.size() << "\n";
  for (const auto &[start, end] : results) {
    cout << start << " " << end << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  solve(n, nums);
  return 0;
}
