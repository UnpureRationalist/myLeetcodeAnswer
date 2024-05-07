#include <bits/stdc++.h>
using namespace std;

class Solution {
  int upper(int x, int k) { return (x + k - 1) / k; }

  bool check(const vector<int> &piles, int hours, int k) {
    int idx = upper_bound(piles.begin(), piles.end(), k) - piles.begin();
    int sum = idx;
    int n = piles.size();
    for (int i = idx; i < n; ++i) {
      sum += upper(piles[i], k);
    }
    return sum <= hours;
  }

 public:
  int minEatingSpeed(vector<int> &piles, int h) {
    sort(piles.begin(), piles.end());
    int ans = 0;
    int left = 1;
    int right = piles.back();

    while (left <= right) {
      int mid = left + (right - left) / 2;
      bool ok = check(piles, h, mid);
      if (ok && (mid == 1 || !check(piles, h, mid - 1))) {
        ans = mid;
        break;
      }
      if (ok) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};
