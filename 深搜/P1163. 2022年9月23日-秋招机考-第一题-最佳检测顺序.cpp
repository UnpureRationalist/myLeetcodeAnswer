#include <bits/stdc++.h>
using namespace std;

void solve(int n, const vector<int> &nums) {
  vector<pair<int, int>> depends(n);
  for (int i = 0; i < n; ++i) {
    depends[i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    // 对第 i 个服务，计算它需要依赖哪些服务
    int cur = nums[i];
    while (cur != -1) {
      depends[cur].first++;
      cur = nums[cur];
    }
  }
  sort(depends.begin(), depends.end(), [](const pair<int, int> &lop, const pair<int, int> &rop) {
    if (lop.first != rop.first) {
      return lop.first > rop.first;
    }
    return lop.second < rop.second;
  });
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << depends[i].second;
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  solve(n, nums);
  return 0;
}
