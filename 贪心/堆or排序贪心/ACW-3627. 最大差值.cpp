#include <bits/stdc++.h>
using namespace std;

long long getMaxDiffer(int k, const vector<int> &nums) {
  long long ans = 0;
  priority_queue<long long> q;
  for (const auto &num : nums) {
    if (num > 0) {
      q.emplace(num);
    }
  }
  while (q.size() >= 2 && k--) {
    long long max_val = q.top();
    q.pop();
    long long sec_max = q.top();
    q.pop();
    ans = max_val + sec_max;
    q.emplace(max_val + sec_max);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto &num : nums) {
      cin >> num;
    }
    cout << getMaxDiffer(k, nums) << "\n";
  }
  return 0;
}
