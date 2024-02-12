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
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> num2times;
    for (const auto &num : nums) {
      num2times[num]++;
    }
    priority_queue<pair<int, int>> q;
    for (const auto &[num, times] : num2times) {
      q.emplace(times, num);
    }
    vector<int> result(k);
    for (int i = 0; i < k; ++i) {
      result[i] = q.top().second;
      q.pop();
    }
    return result;
  }
};
