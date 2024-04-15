#include "header.h"

class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    auto cmp = [&nums1, &nums2](const pair<int, int> &lhs, const pair<int, int> &rhs) {
      return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
    };

    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> ans;
    ans.reserve(k);
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < min(k, m); i++) {
      pq.emplace(i, 0);  // 初始化所有 (nums1[i], nums2[0]) 入优先队列
    }
    while (ans.size() < k) {
      auto [idx1, idx2] = pq.top();
      pq.pop();
      ans.emplace_back(initializer_list<int>{nums1[idx1], nums2[idx2]});
      if (idx2 + 1 < n) {
        pq.emplace(idx1, idx2 + 1);  // (nums1[idx1], nums2[idx2 + 1]) 入队列
      }
    }
    return ans;
  }
};
