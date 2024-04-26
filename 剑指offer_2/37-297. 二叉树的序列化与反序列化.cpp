#include "header.h"

class Codec {
  void serializeInternal(TreeNode *root, string &ans) {
    if (root == nullptr) {
      ans.append("$,");
      return;
    }
    int num = root->val;
    ans.append(to_string(num) + ",");
    serializeInternal(root->left, ans);
    serializeInternal(root->right, ans);
  }

  TreeNode *deserializeInternal(const string &data, int &idx) {
    if (idx >= data.length()) {
      return nullptr;
    }
    int end_idx = find(data.begin() + idx, data.end(), ',') - data.begin();
    string cur_str = data.substr(idx, end_idx - idx);
    if (cur_str == "$") {
      idx = end_idx + 1;
      return nullptr;
    }
    TreeNode *root = new TreeNode(stoi(cur_str));
    idx = end_idx + 1;
    root->left = deserializeInternal(data, idx);
    root->right = deserializeInternal(data, idx);
    return root;
  }

 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    string ans;
    serializeInternal(root, ans);
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    int idx = 0;
    return deserializeInternal(data, idx);
  }
};
