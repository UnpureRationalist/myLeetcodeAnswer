#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val{0};
  TreeNode *left{nullptr};
  TreeNode *right{nullptr};
};

class BinaryTree {
 public:
  BinaryTree(const string &str, int i, int j) { root = build(str, i, j); }

  long long calculate() {
    long long ans = 0;
    queue<TreeNode *> q;
    if (root != nullptr) {
      q.emplace(root);
    }
    int depth = 1;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *cur = q.front();
        q.pop();
        ans += cur->val * depth;
        if (cur->left) {
          q.emplace(cur->left);
        }
        if (cur->right) {
          q.emplace(cur->right);
        }
      }
      ++depth;
    }
    return ans;
  }

 private:
  TreeNode *build(const string &str, int i, int j) {
    if (i > j) {
      return nullptr;
    }
    if (i == j && str[i] == 'X') {
      return nullptr;
    }
    if (i + 2 == j && str[i + 1] == 'X') {
      return nullptr;
    }
    TreeNode *root = new TreeNode();
    int ltree = i;
    stack<char> stk;
    stk.push(str[i]);
    while (!stk.empty()) {
      ++ltree;
      if (str[ltree] == '(') {
        stk.push('(');
      } else if (str[ltree] == ')') {
        stk.pop();
      }
    }
    root->left = build(str, i + 1, ltree - 1);
    int num_start = ltree + 1;
    int num_end = num_start + 1;
    while (str[num_end] != '(') {
      ++num_end;
    }
    root->val = stoi(str.substr(num_start, num_end - num_start));
    root->right = build(str, num_end + 1, j - 1);
    return root;
  }

  TreeNode *root;
};

void solve(const string &str) {
  int n = str.length();
  BinaryTree tree(str, 0, n - 1);
  cout << tree.calculate() << endl;
}

int main() {
  ios::sync_with_stdio(false);
  string str;
  cin >> str;
  solve(str);
  return 0;
}
