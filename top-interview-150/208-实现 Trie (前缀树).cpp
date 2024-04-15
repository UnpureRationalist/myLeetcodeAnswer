#include "header.h"

class Trie {
  class TrieNode {
   public:
    TrieNode() = default;

    TrieNode(char c) : val_{c} {}

    bool isEnd() const { return is_end_; }

    void AddChild(char c, TrieNode *child) { children_[c] = child; }

    TrieNode *GetChild(char c) { return children_[c]; }

    void SetEnd() { is_end_ = true; }

   private:
    bool is_end_{false};
    char val_{0};
    unordered_map<char, TrieNode *> children_;
  };

 public:
  Trie() {}

  void insert(string word) {
    TrieNode *pre = &root;
    TrieNode *cur = nullptr;
    for (auto &c : word) {
      cur = pre->GetChild(c);
      if (cur == nullptr) {
        cur = new TrieNode(c);
        pre->AddChild(c, cur);
      }
      pre = cur;
    }
    cur->SetEnd();
  }

  bool search(string word) {
    TrieNode *pre = &root;
    TrieNode *cur = nullptr;
    for (auto &c : word) {
      cur = pre->GetChild(c);
      if (cur == nullptr) {
        return false;
      }
      pre = cur;
    }
    return cur->isEnd();
  }

  bool startsWith(string prefix) {
    TrieNode *pre = &root;
    TrieNode *cur = nullptr;
    for (auto &c : prefix) {
      cur = pre->GetChild(c);
      if (cur == nullptr) {
        return false;
      }
      pre = cur;
    }
    return true;
  }

 private:
  TrieNode root{};
};
