#include "header.h"

class Solution {
 public:
  int firstUniqChar(string s) {
    int hash[26];
    for (auto &c : s) {
      hash[c - 'a']++;
    }
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      if (hash[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};
