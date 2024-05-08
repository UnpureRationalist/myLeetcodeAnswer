#include <bits/stdc++.h>
using namespace std;

class Solution {
  int rows;
  int cols;

  static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool legal(int x, int y) { return x >= 0 && x < rows && y >= 0 && y < cols; }

  bool check(const vector<vector<int>> &heights, int effort) {
    vector<vector<char>> visited(rows, vector<char>(cols, 0));
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    visited[0][0] = 1;
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      if (x == rows - 1 && y == cols - 1) {
        return true;
      }
      int cur_height = heights[x][y];
      for (int i = 0; i < 4; ++i) {
        int nx = x + dirs[i][0];
        int ny = y + dirs[i][1];
        if (legal(nx, ny) && !visited[nx][ny] && abs(heights[nx][ny] - cur_height) <= effort) {
          visited[nx][ny] = 1;
          q.emplace(nx, ny);
        }
      }
    }
    return false;
  }

 public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    rows = heights.size();
    cols = heights[0].size();
    int ans = 0;
    int left = 0;
    int right = 1e6;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      bool ok = check(heights, mid);
      if (ok && !check(heights, mid - 1)) {
        ans = mid;
        break;
      }
      if (ok) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};
