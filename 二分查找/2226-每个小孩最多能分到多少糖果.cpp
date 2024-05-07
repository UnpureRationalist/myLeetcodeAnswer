#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool enough(const vector<int> &candies, long long k, int m) {
    long long ans = 0;
    for (const auto &elem : candies) {
      ans += elem / m;
      if (ans >= k) {
        return true;
      }
    }
    return ans >= k;
  }

 public:
  int maximumCandies(vector<int> &candies, long long k) {
    long long total = accumulate(candies.begin(), candies.end(), 0ll);
    if (total < k) {
      return 0;
    }
    int left = 1;
    int right = *max_element(candies.begin(), candies.end());
    int ans = 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      bool ok = enough(candies, k, mid);
      if (ok && !enough(candies, k, mid + 1)) {
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
