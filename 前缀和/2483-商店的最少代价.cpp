#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int bestClosingTime(string customers) {
    int n = customers.length();
    vector<int> pre(n + 1, 0);   //  pre[i] 表示第 i 个小时关门，前 i - 1 个小时 N 数量
    vector<int> post(n + 1, 0);  // post[i] 表示第 i 个小时关门，后 [i, n - 1] 个小时 Y 的数量
    for (int i = 1; i <= n; ++i) {
      pre[i] = pre[i - 1] + (customers[i - 1] == 'N');
    }
    for (int i = n - 1; i >= 0; --i) {
      post[i] = post[i + 1] + (customers[i] == 'Y');
    }
    int ans = -1;
    int min_cost = INT32_MAX;
    for (int i = 0; i <= n; ++i) {
      int cost = pre[i] + post[i];
      if (cost < min_cost) {
        ans = i;
        min_cost = cost;
      }
    }
    return ans;
  }
};
