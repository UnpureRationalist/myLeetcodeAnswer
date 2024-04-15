#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    int rows = 9;
    int cols = 9;
    // 行
    for (int row = 0; row < rows; ++row) {
      unordered_set<char> hash;
      for (const auto &c : board[row]) {
        if (c == '.') {
          continue;
        }
        if (hash.find(c) != hash.end()) {
          return false;
        }
        hash.insert(c);
      }
    }
    // 列
    for (int col = 0; col < cols; ++col) {
      unordered_set<char> hash;
      for (int row = 0; row < rows; ++row) {
        char c = board[row][col];
        if (c == '.') {
          continue;
        }
        if (hash.find(c) != hash.end()) {
          return false;
        }
        hash.insert(c);
      }
    }
    // 3*3
    for (int row = 0; row < rows; row += 3) {
      for (int col = 0; col < cols; col += 3) {
        unordered_set<char> hash;
        for (int i = row; i < row + 3; ++i) {
          for (int j = col; j < col + 3; ++j) {
            char c = board[i][j];
            if (c == '.') {
              continue;
            }
            if (hash.find(c) != hash.end()) {
              return false;
            }
            hash.insert(c);
          }
        }
      }
    }
    return true;
  }
};
