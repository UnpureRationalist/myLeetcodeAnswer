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
  vector<int> twoSum(vector<int> &numbers, int target) {
    int n = numbers.size();
    int i = 0, j = n - 1;
    while (i < j) {
      int sum = numbers[i] + numbers[j];
      if (sum == target) {
        return {i + 1, j + 1};
      }
      if (sum > target) {
        --j;
      } else {
        ++i;
      }
    }
    return {-1, -1};
  }
};
