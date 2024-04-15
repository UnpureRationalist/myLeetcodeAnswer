#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    int i = 0;
    while (true) {
      if (i >= strs[0].length()) {
        break;
      }
      char c = strs[0][i];
      int j = 1;
      for (; j < n; ++j) {
        if (strs[j][i] != c) {
          break;
        }
      }
      if (j != n) {
        break;
      }
      ++i;
    }
    return strs[0].substr(0, i);
  }
};
