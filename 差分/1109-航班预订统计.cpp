#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> ans(n + 1, 0);
    for (const auto &booking : bookings) {
      int from = booking[0];
      int to = booking[1];
      int seats = booking[2];
      ans[from - 1] += seats;
      ans[to] -= seats;
    }
    for (int i = 1; i < n; ++i) {
      ans[i] += ans[i - 1];
    }
    ans.pop_back();
    return ans;
  }
};
