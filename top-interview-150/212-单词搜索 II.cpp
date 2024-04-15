#include "header.h"

struct TrieNode {
  string word;
  vector<TrieNode *> children;
  TrieNode() : children{26, nullptr} {}

  void insertChild(char c, TrieNode *child) { children[c - 'a'] = child; }

  TrieNode *getChild(char c) { return children[c - 'a']; }

  bool isEnd() { return word.length() > 0; }
};

void insertTrie(TrieNode *root, const string &word) {
  TrieNode *node = root;
  for (auto &c : word) {
    if (!node->getChild(c)) {
      node->insertChild(c, new TrieNode());
    }
    node = node->getChild(c);
  }
  node->word = word;
}

class Solution {
 public:
  int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void dfs(vector<vector<char>> &board, int x, int y, TrieNode *root, unordered_set<string> &res) {
    char ch = board[x][y];
    if (!root->getChild(ch)) {
      return;
    }
    root = root->getChild(ch);
    if (root->isEnd()) {
      res.insert(root->word);
    }

    board[x][y] = '#';
    for (int i = 0; i < 4; ++i) {
      int nx = x + dirs[i][0];
      int ny = y + dirs[i][1];
      if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
        if (board[nx][ny] != '#') {
          dfs(board, nx, ny, root, res);
        }
      }
    }
    board[x][y] = ch;
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    TrieNode *root = new TrieNode();
    for (auto &word : words) {
      insertTrie(root, word);
    }

    unordered_set<string> res;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        dfs(board, i, j, root, res);
      }
    }

    return vector<string>(res.begin(), res.end());
  }
};
