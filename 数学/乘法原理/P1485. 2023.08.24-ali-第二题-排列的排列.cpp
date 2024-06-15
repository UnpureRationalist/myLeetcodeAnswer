#include <bits/stdc++.h>
using namespace std;

int solve(int n, const vector<int> &nums) {
  unordered_map<int, int> num2times;
  for (const auto &num : nums) {
    num2times[num]++;
  }
  long long ans = 0;
  long long pre_mult = 1;
  const int MOD = 1e9 + 7;
  for (int i = 1; i <= n; ++i) {
    if (num2times.count(i) == 0) {
      break;
    }
    int times = num2times[i];
    pre_mult *= times;
    ans += pre_mult;
    pre_mult %= MOD;
    ans %= MOD;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int &num : nums) {
    cin >> num;
  }
  cout << solve(n, nums) << endl;
  return 0;
}
