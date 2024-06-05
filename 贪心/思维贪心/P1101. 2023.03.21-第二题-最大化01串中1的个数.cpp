#include <bits/stdc++.h>
using namespace std;

int solve(string &str) {
  int n = str.length();
  vector<int> zero_pos;
  for (int i = 0; i < n; ++i) {
    if (str[i] == '0') {
      zero_pos.push_back(i);
    }
  }
  int zero_count = zero_pos.size();
  if (zero_count <= 1) {
    return 0;
  }
  if (zero_count % 2 == 0) {
    int ans = 0;
    for (int i = 0; i < zero_count; i += 2) {
      ans += zero_pos[i + 1] - zero_pos[i];
    }
    return ans;
  }
  // 后缀和来维护 str2 的操作次数
  vector<int> post_sum(zero_count + 1, 0);
  for (int i = zero_count - 1; i > 0; i -= 2) {
    post_sum[i - 1] = post_sum[i + 1] + zero_pos[i] - zero_pos[i - 1];
  }
  int pre = 0;
  int ans = INT32_MAX;
  for (int i = 0; i < zero_count; i += 2) {
    ans = min(ans, pre + post_sum[i + 1]);
    pre += zero_pos[i + 1] - zero_pos[i];
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  string str;
  cin >> str;
  cout << solve(str) << endl;
  return 0;
}
