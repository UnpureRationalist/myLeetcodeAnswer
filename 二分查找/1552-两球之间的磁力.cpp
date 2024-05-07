#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool canFillWithinForce(const vector<int> &position, int m, int force) {
    int fill_num = 1;
    auto iter = lower_bound(position.begin(), position.end(), position[0] + force);
    while (iter != position.end()) {
      ++fill_num;
      if (fill_num >= m) {
        return true;
      }
      iter = lower_bound(iter, position.end(), *iter + force);
    }
    return fill_num >= m;
  }

 public:
  int maxDistance(vector<int> &position, int m) {
    sort(position.begin(), position.end());
    int left = 1;
    int max_force = position.back() - position.front();
    int right = max_force;
    int ans = left;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      bool ok = canFillWithinForce(position, m, mid);
      if (ok && (ok == max_force || !canFillWithinForce(position, m, mid + 1))) {
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
