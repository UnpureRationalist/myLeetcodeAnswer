#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
 public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
  Node *construct(vector<vector<int>> &grid, pair<int, int> leftTop, pair<int, int> rightDown) {
    bool same = true;
    int value = grid[leftTop.first][leftTop.second];
    for (int row = leftTop.first; row <= rightDown.first; ++row) {
      for (int col = leftTop.second; col <= rightDown.second; ++col) {
        if (grid[row][col] != value) {
          same = false;
          break;
        }
      }
    }
    if (same) {
      return new Node{value == 1, true};
    }
    Node *root = new Node{};
    int midRow = (leftTop.first + rightDown.first) / 2;
    int midCol = (leftTop.second + rightDown.second) / 2;
    root->topLeft = construct(grid, leftTop, {midRow, midCol});
    root->topRight = construct(grid, {leftTop.first, midCol + 1}, {midRow, rightDown.second});
    root->bottomLeft = construct(grid, {midRow + 1, leftTop.second}, {rightDown.first, midCol});
    root->bottomRight = construct(grid, {midRow + 1, midCol + 1}, rightDown);
    return root;
  }

 public:
  Node *construct(vector<vector<int>> &grid) {
    int n = grid.size();
    return construct(grid, {0, 0}, {n - 1, n - 1});
  }
};
