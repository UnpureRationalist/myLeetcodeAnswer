#include "header.h"

class Solution {
 public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> hash;
    for (const auto &c : s) {
      hash[c]++;
    }
    for (const auto &c : t) {
      if (hash.find(c) == hash.end()) {
        return false;
      }
      hash[c]--;
    }
    for (const auto &[key, value] : hash) {
      if (value != 0) {
        return false;
      }
    }
    return true;
  }
};
