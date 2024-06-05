#include <bits/stdc++.h>
using namespace std;

long long solve(int n, int k, vector<int> &nums) {
  // [1, k] 需要交换到前 k 个位置
  // 也即 [k + 1, n] 需要交换到后 n - k 个位置
  if (k == n) {
    return 0;
  }
  vector<int> pre, post;
  for (int i = 0; i < k; ++i) {
    if (nums[i] > k) {
      pre.push_back(i);
    }
  }
  for (int i = k; i < n; ++i) {
    if (nums[i] <= k) {
      post.push_back(i);
    }
  }
  long long ans = 0;
  int len = pre.size();
  for (int i = 0; i < len; ++i) {
    ans += post[i] - pre[i];
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vector<int> nums(n);
  for (auto &num : nums) {
    cin >> num;
  }
  cout << solve(n, k, nums) << endl;
  return 0;
}
