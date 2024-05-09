#include <bits/stdc++.h>
using namespace std;

class Solution {
  int ans;

  bool isSquare(int x) {
    int sqr = sqrt(x);
    return x == (sqr * sqr);
  }

  void dfs(int depth, int n, const vector<int> &nums, vector<char> &visited, vector<int> &path) {
    if (depth == n) {
      ++ans;
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (!visited[i] && (depth == 0 || (isSquare(nums[i] + path[depth - 1])))) {
        if (i > 0 && !visited[i - 1] && nums[i] == nums[i - 1]) {
          continue;
        }
        visited[i] = 1;
        path[depth] = nums[i];
        dfs(depth + 1, n, nums, visited, path);
        visited[i] = 0;
      }
    }
  }

 public:
  int numSquarefulPerms(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    ans = 0;
    vector<char> visited(n, 0);
    vector<int> path(n);
    dfs(0, n, nums, visited, path);
    return ans;
  }
};
