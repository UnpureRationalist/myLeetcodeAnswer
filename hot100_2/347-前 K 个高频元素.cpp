#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> num2count;
    for (const auto &num : nums) {
      num2count[num]++;
    }
    priority_queue<pair<int, int>> q;
    for (const auto &[num, times] : num2count) {
      q.emplace(times, num);
    }
    vector<int> result;
    result.reserve(k);
    while (!q.empty() && k--) {
      result.push_back(q.top().second);
      q.pop();
    }
    return result;
  }
};
