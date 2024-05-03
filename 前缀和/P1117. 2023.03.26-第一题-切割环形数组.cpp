#include <bits/stdc++.h>
using namespace std;

/*

考虑环形切割 无非两种情况: 切两边 和
切中间（切中间就是把中间分为一段，剩下的左右两边，因为是环形的关系，可以分成另外一段）
1. 首先考虑无解的情况：如果数组总和为奇数，那么必定无解。
2. 对于切两边来说，其实就是考虑前缀和 s[i] 是否等于总和的一半
3. 对于切中间来说，枚举到第 i 个点时，考虑 (1,i)区间 有多少个满足 [j,i] 区间和为总和的一半，
    可以使用哈希表记录前缀和出现的次数，然后枚举到 i 时，判断是否存在有 key 的值为 s[i]-sum 的（sum 为数组总和的一半），
    如果有，则累加对应的计数。

*/
long long solve(int n, long long sum, const vector<long long> &presum) {
  if (sum % 2 != 0) {
    return 0ll;
  }

  long long ans = 0;
  long long half = sum / 2;
  // 1. 切两边的情况，考虑 presum[i] 是否等于 sum 一半
  for (int i = 1; i < n; ++i) {  // i < n，不能取等号，因为区间不可以为空
    if (presum[i] == half) {
      ++ans;
    }
  }
  // 2. 切中间的情况
  unordered_map<long long, int> sum2times;
  // 枚举以 i 结尾的区间 sum
  for (int i = 1; i < n; ++i) {
    ans += sum2times[presum[i] - half];  // sum[i] - sum[j] = half, sum[j] = sum[i] - half
    sum2times[presum[i]]++;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n + 1, 0);
  vector<long long> presum(n + 1, 0ll);
  for (int i = 1; i <= n; ++i) {
    cin >> nums[i];
    presum[i] = presum[i - 1] + nums[i];
  }
  long long sum = presum[n];

  long long ans = solve(n, sum, presum);

  cout << ans << endl;

  return 0;
}
