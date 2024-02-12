#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie {
  class TrieNode {
   public:
    TrieNode() : children_(26, nullptr) {}

    TrieNode(char c) : val_{c}, children_(26, nullptr) {}

    bool isEnd() const { return is_end_; }

    void AddChild(char c, TrieNode *child) { children_[c - 'a'] = child; }

    TrieNode *GetChild(char c) { return children_[c - 'a']; }

    void SetEnd() { is_end_ = true; }

   private:
    bool is_end_{false};
    char val_{0};
    vector<TrieNode *> children_;  // 仅小写字母
  };

  bool Empty() const { return root.isEnd(); }

 public:
  Trie() {}

  void insert(string word) {
    TrieNode *pre = &root;
    TrieNode *cur = nullptr;
    int n = word.length();

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
