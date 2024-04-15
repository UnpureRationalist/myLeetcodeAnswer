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
  int rangeBitwiseAnd(int left, int right) {
    while (left < right) {
      right = right & (right - 1);
    }
    return right;
  }
};
