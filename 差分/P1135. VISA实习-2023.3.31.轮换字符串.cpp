#include <bits/stdc++.h>
using namespace std;

void solve(int n, string &str, int m, const vector<int> &nums) {
  vector<int> increase(n + 1, 0);
  for (auto &num : nums) {
    increase[0] += 1;
    increase[num] -= 1;
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += increase[i];
    str[i] = (str[i] - 'a' + sum) % 26 + 'a';
  }
  cout << str << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  string str;
  cin >> str;
  vector<int> nums(m, 0);
  for (int i = 0; i < m; ++i) {
    cin >> nums[i];
  }
  solve(n, str, m, nums);
  return 0;
}
