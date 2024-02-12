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
  int n;
  vector<vector<int>> result;
  vector<int> visited;

  vector<int> temp;

  void dfs(int limit, int start, vector<int> &nums) {
    if (temp.size() == limit) {
      result.emplace_back(temp);
      return;
    }
    for (int i = start; i < n; ++i) {
      if (!visited[i]) {
        visited[i] = true;
        temp.emplace_back(nums[i]);
        dfs(limit, i + 1, nums);
        temp.pop_back();
        visited[i] = false;
      }
    }
  }

 public:
  vector<vector<int>> subsets(vector<int> &nums) {
    n = nums.size();
    result.clear();
    result.reserve(1 << n);
    visited.resize(n, false);
    temp.clear();
    temp.reserve(n);

    result.emplace_back(vector<int>());
    result.emplace_back(nums);

    for (int limit = 1; limit < n; ++limit) {
      dfs(limit, 0, nums);
    }

    return result;
  }
};
