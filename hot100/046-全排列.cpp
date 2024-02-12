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

  vector<int> temp;

  vector<bool> visited;

  int fact(int n) {
    int s = n;
    while (--n > 1) {
      s *= n;
    }
    return s;
  }

  void dfs(int depth, vector<int> &nums) {
    if (depth == n) {
      result.push_back(temp);
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        visited[i] = true;
        temp.emplace_back(nums[i]);
        dfs(depth + 1, nums);
        temp.pop_back();
        visited[i] = false;
      }
    }
  }

 public:
  vector<vector<int>> permute(vector<int> &nums) {
    n = nums.size();
    int m = fact(n);
    result.clear();
    result.reserve(m);
    temp.clear();
    temp.reserve(m);

    visited.resize(n, false);

    dfs(0, nums);
    return result;
  }
};
