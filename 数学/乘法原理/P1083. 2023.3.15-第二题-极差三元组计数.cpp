#include <bits/stdc++.h>
using namespace std;

long long solve(int n, const vector<int> &nums) {
  unordered_map<int, int> num2times;
  // 枚举左端点 i
  //    假设 w[i] 为最小值 则有 (a,a+1,a+1) (a,a+1,a) (a,a,a+1) 三种情况满足条件
  //    假设 w[i] 为最大值 则有 (a,a-1,a-1) (a,a-1,a) (a,a,a-1) 三种情况满足条件
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    int x = nums[i];
    res += 1ll * num2times[x] * num2times[x + 1];                // 选一个 a, 一个 a+1
    res += 1ll * num2times[x + 1] * (num2times[x + 1] - 1) / 2;  // 选两个 a+1
    res += 1ll * num2times[x] * num2times[x - 1];                // 选一个 a, 一个 a-1
    res += 1ll * num2times[x - 1] * (num2times[x - 1] - 1) / 2;  // 选两个 a-1
    num2times[x]++;
  }
  return res;
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
