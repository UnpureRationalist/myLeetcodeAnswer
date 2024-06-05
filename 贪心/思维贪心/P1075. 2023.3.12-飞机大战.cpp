#include <bits/stdc++.h>
using namespace std;

int minKey(int n, const vector<int> &nums) {
  // A: 2 枚子弹，每个子弹会对命中的敌人造成 1 点固定伤害
  // B: 一枚子弹，消灭一个敌人
  // 策略：如果有 m （偶数）个血量为 1 的敌人，按 m/2 次 A 键；剩余全部按 B 键
  auto iter = upper_bound(nums.begin(), nums.end(), 1);
  if (iter == nums.begin()) {
    // 没有小于 1 的敌人，直接返回 n
    return n;
  }
  int count = iter - nums.begin();
  if (count % 2 == 0) {
    return count / 2 + n - count;
  }
  return count / 2 + 1 + n - count;
}

int main() {
  ios::sync_with_stdio(false);
  int T, n;
  cin >> T >> n;
  vector<int> nums(n);
  while (T--) {
    for (auto &num : nums) {
      cin >> num;
    }
    sort(nums.begin(), nums.end());
    cout << minKey(n, nums) << "\n";
  }
  return 0;
}
