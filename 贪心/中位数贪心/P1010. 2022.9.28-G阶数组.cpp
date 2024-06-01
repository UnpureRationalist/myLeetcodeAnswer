#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1E5 + 10;

int n, w[N], f[N];
bool st[N];
int k, d;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> d;
  unordered_map<int, vector<int>> nums;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    nums[i % k].push_back(w[i]);
  }

  int cnt = 0, maxv = -1e9;
  for (int i = 0; i < k; i++) {
    auto &v = nums[i];
    int num = *max_element(v.begin(), v.end());
    maxv = max(maxv, num);
    ll sum = accumulate(v.begin(), v.end(), 0ll);
    int m = v.size();
    cnt += 1ll * num * m - sum;
  }

  if (cnt > d) {
    puts("-1");
  } else {
    int last = d - cnt;  // 还剩这么多操作次数可以分配
    int maxv = INT_MIN;
    for (int i = 0; i < k; i++) {
      auto &v = nums[i];
      int m = v.size();
      int num = *max_element(v.begin(), v.end());
      maxv = max(maxv, num + last / m);
    }
    cout << maxv << endl;
  };
  return 0;
}
