#include <bits/stdc++.h>
using namespace std;

class Trie {
  class TrieNode {
   public:
    TrieNode() = default;

    explicit TrieNode(char c) : val_(c) {}

    void setEnd() { isEnd_ = true; }

    bool isEnd() const { return isEnd_; }

    TrieNode *getChild(char c) { return children_[c]; }

    TrieNode *insert(char c) {
      auto node = new TrieNode(c);
      children_[c] = node;
      return node;
    }

   private:
    bool isEnd_{false};
    char val_;
    unordered_map<char, TrieNode *> children_;
  };

 public:
  Trie() {}

  void insert(const string &word) {
    TrieNode *pre = &root_;
    TrieNode *cur = nullptr;
    for (const auto &c : word) {
      cur = pre->getChild(c);
      if (cur == nullptr) {
        cur = pre->insert(c);
      }
      pre = cur;
    }
    cur->setEnd();
  }

  bool search(const string &word) {
    TrieNode *pre = &root_;
    TrieNode *cur = nullptr;
    for (const auto &c : word) {
      cur = pre->getChild(c);
      if (cur == nullptr) {
        return false;
      }
      pre = cur;
    }
    return cur->isEnd();
  }

  bool startsWith(const string &prefix) {
    TrieNode *pre = &root_;
    TrieNode *cur = nullptr;
    for (const auto &c : prefix) {
      cur = pre->getChild(c);
      if (cur == nullptr) {
        return false;
      }
      pre = cur;
    }
    return true;
  }

 private:
  TrieNode root_{};
};
