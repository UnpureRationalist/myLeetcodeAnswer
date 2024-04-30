#include "header.h"

class Solution {
 public:
  vector<double> statisticsProbability(int num) {
    constexpr int numSurfaces = 6;
    vector<vector<int>> probabilities(2, vector<int>(numSurfaces * num + 1, 0));
    int flag = 0;
    for (int i = 1; i <= numSurfaces; ++i) {
      probabilities[flag][i] = 1;
    }
    for (int k = 2; k <= num; ++k) {
      for (int i = 0; i < k; ++i) {
        probabilities[1 - flag][i] = 0;
      }
      for (int i = k; i <= numSurfaces * k; ++i) {
        probabilities[1 - flag][i] = 0;
        for (int j = 1; j <= i && j <= numSurfaces; ++j) {
          probabilities[1 - flag][i] += probabilities[flag][i - j];
        }
      }
      flag = 1 - flag;
    }
    vector<double> result(numSurfaces * num - num + 1, 0);
    double total = pow(numSurfaces, num);
    for (int i = num; i <= numSurfaces * num; ++i) {
      result[i - num] = probabilities[flag][i] / total;
    }
    return result;
  }
};
