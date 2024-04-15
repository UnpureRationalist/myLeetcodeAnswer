#include "header.h"

class Solution {
  int n;

  pair<int, int> idx2xy(int idx) {
    --idx;  // [0, n^2 - 1]
    int row = idx / n;
    idx = idx % n;
    int col = row & 1 ? n - 1 - idx : idx;
    return {n - 1 - row, col};
  }

 public:
  int snakesAndLadders(vector<vector<int>> &board) {
    n = board.size();
    int target = n * n;
    vector<char> visited(target + 1, 0);
    queue<int> q;
    visited[1] = 0;
    q.push(1);
    int ans = 0;
    while (!q.empty()) {
      int size = q.size();
      ++ans;
      while (size--) {
        int cur = q.front();
        q.pop();
        int end = min(cur + 6, target);
        for (int next = cur + 1; next <= end; ++next) {
          auto [x, y] = idx2xy(next);
          int pos = board[x][y] != -1 ? board[x][y] : next;
          if (pos == target) {
            return ans;
          }
          if (!visited[pos]) {
            visited[pos] = 1;
            q.push(pos);
          }
        }
      }
    }
    return -1;
  }
};
