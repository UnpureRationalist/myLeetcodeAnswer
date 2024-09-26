#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> decreaseStk;
    for (int i = 0; i < n; ++i) {
      while (!decreaseStk.empty() && temperatures[i] > temperatures[decreaseStk.top()]) {
        result[decreaseStk.top()] = i - decreaseStk.top();
        decreaseStk.pop();
      }
      decreaseStk.push(i);
    }
    return result;
  }
};
