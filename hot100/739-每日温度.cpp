#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> s;  // 单调栈，其存储下标 idx，保证栈底到栈顶，temperatures[idx] 是递减的
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
        result[s.top()] = i - s.top();
        s.pop();
      }
      s.push(i);
    }
    return result;
  }
};
