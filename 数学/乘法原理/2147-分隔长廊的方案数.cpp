#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numberOfWays(string corridor) {
    int seats = count(corridor.begin(), corridor.end(), 'S');
    if (seats < 2 || seats % 2 != 0) {
      return 0;
    }
    vector<pair<int, int>> seat_lst;
    int n = corridor.length();
    int count = 0;
    for (int i = 0; i < n; ++i) {
      if (corridor[i] == 'S') {
        ++count;
        if (count == 1) {
          seat_lst.emplace_back(i, 0);
        } else {
          // count == 2
          seat_lst.back().second = i;
          count = 0;
        }
      }
    }
    int ranges = seat_lst.size();
    long long ans = 1;
    const int MOD = 1e9 + 7;
    for (int i = 1; i < ranges; ++i) {
      ans *= (seat_lst[i].first - seat_lst[i - 1].second);
      ans %= MOD;
    }
    return ans;
  }
};
