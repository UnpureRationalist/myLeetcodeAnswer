#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool timeEnough(const vector<int> &ranks, long long cars, long long time) {
    long long repair = 0;
    for (const auto &rank : ranks) {
      repair += static_cast<long long>(sqrt(time / rank));
    }
    return repair >= cars;
  }

 public:
  long long repairCars(vector<int> &ranks, int cars) {
    long long right = *min_element(ranks.begin(), ranks.end()) * static_cast<long long>(cars) * cars;
    long long left = 1;
    long long ans = 1;
    while (left <= right) {
      long long mid = left + (right - left) / 2;
      bool ok = timeEnough(ranks, cars, mid);
      if (ok && !timeEnough(ranks, cars, mid - 1)) {
        ans = mid;
        break;
      }
      if (ok) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};
