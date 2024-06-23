#include <bits/stdc++.h>
using namespace std;

class Solution {
  int myPow(int base, int p, int mod) {
    if (p == 0) {
      return 1 % mod;
    }
    if (base == 0) {
      return 0;
    }
    if (p & 1) {
      int ans = base * myPow(base, p - 1, mod) % mod;
      return ans;
    }
    int temp = myPow(base, p / 2, mod);
    return temp * temp % mod;
  }

  int calculate(int a, int b, int c, int m) { return myPow(myPow(a, b, 10), c, m); }

  bool isGood(const vector<int> &var, int target) {
    int a = var[0], b = var[1], c = var[2], m = var[3];
    return calculate(a, b, c, m) == target;
  }

 public:
  vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {
    int n = variables.size();
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (isGood(variables[i], target)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};
