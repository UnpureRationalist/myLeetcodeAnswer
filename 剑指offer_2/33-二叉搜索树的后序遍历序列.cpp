#include "header.h"

// 变例： Leetcode 255. 验证二叉搜索树的前序遍历序列
class Solution {
  bool verifyPreorder(const vector<int> &preorder, int start, int end) {
    if (start >= end) {
      return true;
    }
    int mid = preorder[start];
    int i = start + 1;
    for (; i <= end; ++i) {
      if (preorder[i] > mid) {
        break;
      }
    }
    int j = i;
    for (; j <= end; ++j) {
      if (preorder[j] < mid) {
        return false;  // 如果右子树中有小于 mid 的值，说明不是二叉搜索树
      }
    }
    return verifyPreorder(preorder, start + 1, i - 1) && verifyPreorder(preorder, i, end);
  }

 public:
  bool verifyPreorder(vector<int> &preorder) { return verifyPreorder(preorder, 0, preorder.size() - 1); }
};
