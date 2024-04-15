#include "header.h"

class WordDictionary {
  struct Node {
    char c_;
    bool end_{false};
    unordered_map<char, Node *> children_;

    Node() = default;

    Node(char c) : c_(c) {}

    bool isEnd() const { return end_; }

    void setEnd() { end_ = true; }

    Node *getChild(char c) { return children_[c]; }

    void addChild(char c, Node *child) { children_[c] = child; }
  };

  bool dfs(Node *pre, string &s, int depth) {
    if (depth == s.length()) {
      return pre->isEnd();
    }
    char c = s[depth];
    if (c != '.') {
      Node *child = pre->getChild(c);
      if (child == nullptr) {
        return false;
      }
      return dfs(child, s, depth + 1);
    }
    for (const auto &[key, child] : pre->children_) {
      if (child) {
        bool ans = dfs(child, s, depth + 1);
        if (ans) {
          return true;
        }
      }
    }
    return false;
  }

 public:
  WordDictionary() = default;

  void addWord(string word) {
    Node *pre = &root;
    Node *cur = nullptr;
    for (auto &c : word) {
      cur = pre->getChild(c);
      if (cur == nullptr) {
        cur = new Node(c);
        pre->addChild(c, cur);
      }
      pre = cur;
    }
    cur->setEnd();
  }

  bool search(string word) {
    Node *pre = &root;
    return dfs(pre, word, 0);
  }

 private:
  Node root{};
};
