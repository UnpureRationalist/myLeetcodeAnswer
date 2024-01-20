#include <algorithm>
#include <vector>
using namespace std;

class Solution {
  bool canMerge(const vector<int> &left, const vector<int> &right) {
    return left[1] >= right[0];
  }

  vector<int> doMerge(const vector<int> &left, const vector<int> &right) {
    return {left[0], max(left[1], right[1])};
  }

 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> result;
    int n = intervals.size();
    for (int i = 0; i < n; ++i) {
      if (!result.empty()) {
        // result 中区间是否能和 intervals[i] 合并
        auto &back = result.back();
        if (canMerge(back, intervals[i])) {
          result.back() = doMerge(back, intervals[i]);
          continue;
        }
      }
      result.push_back(intervals[i]);
    }
    return result;
  }
};

class Solution2 {
 public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() == 0) {
      return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); ++i) {
      int L = intervals[i][0], R = intervals[i][1];
      if (merged.empty() || merged.back()[1] < L) {
        merged.push_back({L, R});
      } else {
        merged.back()[1] = max(merged.back()[1], R);
      }
    }
    return merged;
  }
};