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
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int i = 0;
    while (i < n) {
      int sum_gas = 0;
      int sum_cost = 0;
      int count = 0;
      while (count < n) {
        int j = (i + count) % n;
        sum_gas += gas[j];
        sum_cost += cost[j];
        if (sum_cost > sum_gas) {
          break;
        }
        ++count;
      }
      if (count == n) {
        return i;
      }
      i += count + 1;
    }
    return -1;
  }
};
