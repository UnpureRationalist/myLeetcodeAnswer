#include "header.h"

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> c2times;
    for (const auto &c : magazine) {
      c2times[c]++;
    }
    for (const auto &c : ransomNote) {
      if (c2times.find(c) == c2times.end() || c2times[c] == 0) {
        return false;
      }
      c2times[c]--;
    }
    return true;
  }
};
