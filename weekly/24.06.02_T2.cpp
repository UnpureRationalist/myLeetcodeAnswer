#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool isIntersect(const vector<int> &lop, const vector<int> &rop) { return rop[0] <= lop[1]; }

  vector<int> doMerge(const vector<int> &lop, const vector<int> &rop) {
    int left = lop[0];
    int right = max(lop[1], rop[1]);
    return {left, right};
  }

  vector<vector<int>> Merge(vector<vector<int>> &meetings) {
    vector<vector<int>> ans;
    ans.push_back(meetings[0]);
    int n = meetings.size();
    for (int i = 1; i < n; ++i) {
      if (isIntersect(ans.back(), meetings[i])) {
        ans.back() = doMerge(ans.back(), meetings[i]);
      } else {
        ans.push_back(meetings[i]);
      }
    }
    return ans;
  }

  int calculate(int days, const vector<vector<int>> &meetings) {
    int ans = days;
    for (const auto &elem : meetings) {
      int dur = elem[1] - elem[0] + 1;
      ans -= dur;
    }
    return ans;
  }

 public:
  int countDays(int days, vector<vector<int>> &meetings) {
    sort(meetings.begin(), meetings.end());
    vector<vector<int>> merged_days = Merge(meetings);
    return calculate(days, merged_days);
  }
};
