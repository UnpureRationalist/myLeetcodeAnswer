#include <bits/stdc++.h>
using namespace std;

class BinaryIndexedTree {
 private:
  // 非负整数 x 在二进制表示下最低位 1 和后面的 0 构成的值
  int lowBit(int x) { return x & -x; }

 public:
  BinaryIndexedTree(int _n, const vector<int> &init_nums) : n(_n) {
    nums.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      add(i, init_nums[i - 1]);  // 初始化，init_nums 数组从 0 开始存储数字
    }
  }

  // 给数组第 x 个数增加 k
  void add(int x, int k) {
    for (int i = x; i <= n; i += lowBit(i)) {
      nums[i] += k;
    }
  }

  // 计算数组 [1, x] 前缀和
  long long presum(int x) {
    long long ans = 0;
    for (int i = x; i; i -= lowBit(i)) {
      ans += nums[i];
    }
    return ans;
  }

  // 计算区间 [left, right] 元素和
  long long query(int left, int right) { return presum(right) - presum(left - 1); }

 private:
  int n;
  vector<int> nums;
};

// 洛谷 P3374： https://www.luogu.com.cn/problem/P3374
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;

  vector<int> nums(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  BinaryIndexedTree tree(n, nums);

  for (int i = 0; i < m; ++i) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      tree.add(x, y);
    } else {
      cout << tree.query(x, y) << "\n";
    }
  }

  return 0;
}
