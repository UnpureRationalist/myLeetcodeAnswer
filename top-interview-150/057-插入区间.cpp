#include "header.h"

class Solution {
  bool isIntersect(const vector<int> &lhs, const vector<int> &rhs) { return rhs[0] <= lhs[1]; }

  void doMerge(vector<int> &lhs, const vector<int> &rhs) { lhs[1] = max(lhs[1], rhs[1]); }

  vector<vector<int>> merge(vector<vector<int>> &intervals) {
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

 public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
    auto iter = lower_bound(intervals.begin(), intervals.end(), newInterval,
                            [](const vector<int> &lhs, const vector<int> &rhs) {
                              return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
                            });
    intervals.insert(iter, newInterval);
    return merge(intervals);
  }
};
