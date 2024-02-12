#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      int minn = INT_MAX;
      for (int j = 1; j * j <= i; j++) {
        minn = min(minn, dp[i - j * j]);
      }
      dp[i] = minn + 1;
    }
    return dp[n];
  }
};

class Solution {
 public:
  // 判断是否为完全平方数
  bool isPerfectSquare(int x) {
    int y = sqrt(x);
    return y * y == x;
  }

  // 判断是否能表示为 4^k*(8m+7)
  bool checkAnswer4(int x) {
    while (x % 4 == 0) {
      x /= 4;
    }
    return x % 8 == 7;
  }

  int numSquares(int n) {
    if (isPerfectSquare(n)) {
      return 1;
    }
    if (checkAnswer4(n)) {
      return 4;
    }
    for (int i = 1; i * i <= n; i++) {
      int j = n - i * i;
      if (isPerfectSquare(j)) {
        return 2;
      }
    }
    return 3;
  }
};
