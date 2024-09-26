#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int trap(vector<int> &height) {
    int ans = 0;
    int i = 0;
    int j = height.size() - 1;
    int lmax = height[0];
    int rmax = height.back();
    while (i < j) {
      lmax = max(lmax, height[i]);
      rmax = max(rmax, height[j]);
      if (lmax < rmax) {
        ans += lmax - height[i];
        ++i;
      } else {
        ans += rmax - height[j];
        --j;
      }
    }
    return ans;
  }
};
