#include "header.h"

class Solution {
 public:
  bool checkDynasty(vector<int> &places) {
    sort(places.begin(), places.end());
    int n = places.size();
    int numZero = 0;
    while (numZero < n && places[numZero] == 0) {
      ++numZero;
    }
    for (int i = numZero; i < n - 1; ++i) {
      if (places[i + 1] == places[i]) {
        return false;
      }
      numZero -= places[i + 1] - places[i] - 1;
    }
    return numZero >= 0;
  }
};
