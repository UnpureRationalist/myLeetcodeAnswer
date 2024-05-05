#include <bits/stdc++.h>
using namespace std;

class Solution {
  vector<int> roads;

  void add(int l, int r, int w) {
    roads[l + 1] += w;
    roads[r + 1] -= w;
  }

 public:
  Solution() : roads(1010, 0) {}
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    for (const auto &trip : trips) {
      add(trip[1], trip[2], trip[0]);
    }
    int n = roads.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += roads[i];
      if (sum > capacity) {
        return false;
      }
    }
    return true;
  }
};
