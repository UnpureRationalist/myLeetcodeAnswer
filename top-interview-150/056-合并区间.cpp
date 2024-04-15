#include "header.h"

class Solution {
  bool isIntersect(const vector<int> &lhs, const vector<int> &rhs) { return rhs[0] <= lhs[1]; }

  void doMerge(vector<int> &lhs, const vector<int> &rhs) { lhs[1] = max(lhs[1], rhs[1]); }

 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
      return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
    });
    int n = intervals.size();
    vector<vector<int>> result;
    result.push_back(intervals[0]);
    for (int i = 1; i < n; ++i) {
      if (isIntersect(result.back(), intervals[i])) {
        doMerge(result.back(), intervals[i]);
      } else {
        result.emplace_back(intervals[i]);
      }
    }
    return result;
  }
};
