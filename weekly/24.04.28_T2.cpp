#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int n = nums1.size();
    int m = nums2.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        // 枚举删除 nums1 中下标为 i 和 j 的元素
        int idx1 = 0;
        int idx2 = 0;
        int x = 0;
        bool first = true;
        bool legal = true;
        while (idx1 < n && idx2 < m) {
          if (idx1 == i || idx1 == j) {
            ++idx1;
            continue;
          }
          if (first) {
            first = false;
            x = nums2[idx2] - nums1[idx1];
          } else {
            if ((nums2[idx2] - nums1[idx1]) != x) {
              legal = false;
              break;
            }
          }
          ++idx1;
          ++idx2;
        }
        if (legal) {
          ans = min(ans, x);
        }
      }
    }
    return ans;
  }
};
