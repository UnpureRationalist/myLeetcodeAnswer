#include <bits/stdc++.h>
using namespace std;
/*

    s[i] - s[j - 1] = k * (i - j + 1)
--> s[i] - ki = s[j - 1] - k(j - 1)
--> 左右侧形式都为 s[i] - ki
    因此，当枚举到下标 i 时，只需要判断哈希表中是否存在 s[i] - ki 即可，如果存在，则更新最大长度;
    不存在的话，就把当前的值（s[i] - ki）和下标( i )作为哈希表的 key 和 val 存到哈希表中

*/
int solve(long long n, long long k, const vector<long long> &presum) {
  int ans = 0;
  unordered_map<long long, int> num2idx;
  num2idx[0] = 0;
  for (int i = 1; i <= n; ++i) {
    if (num2idx.count(presum[i] - k * i)) {
      ans = max(ans, i - num2idx[presum[i] - k * i]);
    } else {
      num2idx[presum[i] - k * i] = i;  // 需要保存最小的下标 i
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  vector<int> nums(n + 1, 0);
  vector<long long> presum(n + 1, 0ll);
  for (int i = 1; i <= n; ++i) {
    cin >> nums[i];
    presum[i] = presum[i - 1] + nums[i];
  }
  int ans = solve(n, k, presum);
  cout << ans << endl;
  return 0;
}
