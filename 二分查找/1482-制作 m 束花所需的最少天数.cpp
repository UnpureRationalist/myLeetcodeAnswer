#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool check(const vector<int> &bloomDay, int m, int k, int days) {
    int count = 0;
    int n = bloomDay.size();
    for (int i = 0; i < n;) {
      while (i < n && bloomDay[i] > days) {
        ++i;
      }
      int j = i + 1;
      while (j < n && (j - i) < k && bloomDay[j] <= days) {
        ++j;
      }
      int len = j - i;
      if (len == k) {
        ++count;
      }
      i = j;
    }
    return count >= m;
  }

 public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    long long n = bloomDay.size();
    if (n < static_cast<long long>(m) * k) {
      return -1;
    }
    int left = *min_element(bloomDay.begin(), bloomDay.end());
    int right = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = left;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      bool ok = check(bloomDay, m, k, mid);
      if (ok && !check(bloomDay, m, k, mid - 1)) {
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
