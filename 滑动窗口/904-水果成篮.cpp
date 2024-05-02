#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int totalFruit(vector<int> &fruits) {
    int n = fruits.size();
    int ans = 0;
    unordered_map<int, int> num2times;
    for (int l = 0, r = 0; r < n; ++r) {
      num2times[fruits[r]]++;  // r 进入窗口
      // 移动左指针
      while (num2times.size() > 2) {
        auto iter = num2times.find(fruits[l]);
        (iter->second)--;
        if (iter->second == 0) {
          num2times.erase(iter);
        }
        ++l;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
