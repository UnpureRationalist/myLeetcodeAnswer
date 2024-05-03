#include <bits/stdc++.h>
using namespace std;

/*

    区间乘积大于 0：白魔法；小于 0：黑魔法
    转化为区间内负数的数量：
        负数数量为偶数：乘积大于 0，白魔法
        负数数量为奇数：乘积小于 0，黑魔法

    nums[i] = 1 表示 nums[i] 为负数，可利用前缀和计算
    sum_nums[i, j] = presum[i] - presum[j - 1]
                   = 0, if presum[i] - presum[j - 1] 为偶数
                   = 1, if presum[i] - presum[j - 1] 为奇数
    当枚举到下标 i 时，表示以 nums[i] 结尾的施展魔法方案，用 counts[2] 数组分别表示前缀和为偶数和奇数的下标数目，
    则可直接读取 counts 数组获取以 i 结尾的黑白魔法方案数

*/

void solve(int n, const vector<int> &nums) {
  long long black = 0, white = 0;
  int counts[2] = {1, 0};  // counts[0] = 1 表示 0 个元素的前缀和为偶数
  for (int i = 1, sum = 0; i <= n; ++i) {
    sum = (sum + nums[i]) % 2;
    black += counts[1 - sum];
    white += counts[sum];
    counts[sum]++;
  }
  cout << black << " " << white << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n + 1, 0);
  int temp;
  for (int i = 1; i <= n; ++i) {
    cin >> temp;
    if (temp < 0) {
      nums[i] = 1;  // 负数标 1，正数标 0
    }
  }
  solve(n, nums);
  return 0;
}
