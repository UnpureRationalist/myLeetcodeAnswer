#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = m + n - 1;
    int i = m - 1;
    int j = n - 1;
    while (j >= 0) {
      if (i >= 0 && nums1[i] >= nums2[j]) {
        nums1[idx--] = nums1[i--];
      } else {
        nums1[idx--] = nums2[j--];
      }
    }
  }
};
