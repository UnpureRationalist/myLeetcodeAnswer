#include "header.h"

class Solution {
 public:
  /**
   * @brief 核心思想：用最低位 bit 表示原始状态；用倒数第二低位 bit 表示更新后状态
   *
   * @param board
   */
  void gameOfLife(vector<vector<int>> &board) {
    int rows = board.size();
    int cols = board[0].size();

    static int neighbors[3] = {0, 1, -1};
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        int sum = 0;
        for (int i = 0; i < 3; ++i) {
          for (int j = 0; j < 3; ++j) {
            if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
              int x = row + neighbors[i];
              int y = col + neighbors[j];
              if (x >= 0 && x < rows && y >= 0 && y < cols) {
                sum += board[x][y] & 1;
              }
            }
          }
        }
        if (board[row][col] & 1) {
          if (sum == 2 || sum == 3) {
            board[row][col] |= 2;
          }
        } else {
          if (sum == 3) {
            board[row][col] |= 2;
          }
        }
      }
    }
    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        board[row][col] >>= 1;
      }
    }
  }
};
