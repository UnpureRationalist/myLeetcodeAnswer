#include <bits/stdc++.h>
using namespace std;

int doHalf(int max_val, int min_val, int &ans) {
  while (max_val > min_val) {
    max_val /= 2;
    ++ans;
  }
  return max_val;
}

int solve(int n, const vector<int> &nums) {
  int min_val = *min_element(nums.begin(), nums.end());
  priority_queue<int> q;
  for (auto &num : nums) {
    q.emplace(num);
  }
  int ans = 0;
  while (!q.empty()) {
    int max_val = q.top();
    q.pop();
    if (max_val == min_val) {
      break;
    }
    int halfed = doHalf(max_val, min_val, ans);
    if (halfed < min_val) {
      min_val = halfed;
    }
    q.emplace(halfed);
  }
  return ans;
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
