#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool canFillWithinForce(const vector<int> &position, int k, int force) {
    int fill_num = 1;
    auto iter = lower_bound(position.begin(), position.end(), position[0] + force);
    while (iter != position.end()) {
      ++fill_num;
      if (fill_num >= k) {
        return true;
      }
      iter = lower_bound(iter, position.end(), *iter + force);
    }
    return fill_num >= k;
  }

 public:
  int maximumTastiness(vector<int> &price, int k) {
    sort(price.begin(), price.end());
    int left = 0;
    int max_force = price.back() - price.front();
    int right = max_force;
    int ans = left;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      bool ok = canFillWithinForce(price, k, mid);
      if (ok && (ok == max_force || !canFillWithinForce(price, k, mid + 1))) {
        ans = mid;
        break;
      }
      if (ok) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }
};
