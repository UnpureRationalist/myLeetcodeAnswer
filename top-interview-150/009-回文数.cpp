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
  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && (x % 10) == 0)) {
      return false;
    }
    int revert = 0;
    while (x > revert) {
      revert = 10 * revert + x % 10;
      x /= 10;
    }
    return x == revert || x == revert / 10;
  }
};
