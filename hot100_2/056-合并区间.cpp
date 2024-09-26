#include <bits/stdc++.h>
using namespace std;

class Solution {
  inline bool isIntersect(const vector<int> &lop, const vector<int> &rop) { return lop[1] >= rop[0]; }

  inline void doMerge(vector<int> &back, const vector<int> &rop) { back[1] = max(back[1], rop[1]); }

 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;
    int n = intervals.size();
    result.push_back(intervals[0]);
    for (int i = 1; i < n; ++i) {
      if (isIntersect(result.back(), intervals[i])) {
        doMerge(result.back(), intervals[i]);
      } else {
        result.push_back(intervals[i]);
      }
    }
    return result;
  }
};
