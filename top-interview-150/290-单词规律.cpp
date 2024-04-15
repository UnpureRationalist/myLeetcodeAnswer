#include "header.h"

class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    int n = pattern.length();
    int m = s.length();
    unordered_map<char, string> c2s;
    unordered_map<string, char> s2c;
    int i = 0;
    int j = 0;
    for (; i < n && j < m; ++i) {
      while (j < m && s[j] == ' ') {
        ++j;
      }
      int end = j < m ? j + 1 : j;
      while (end < m && s[end] != ' ') {
        ++end;
      }
      string temp = s.substr(j, end - j);
      if (c2s.find(pattern[i]) == c2s.end() && s2c.find(temp) == s2c.end()) {
        c2s[pattern[i]] = temp;
        s2c[temp] = pattern[i];
      }
      if (c2s[pattern[i]] != temp || s2c[temp] != pattern[i]) {
        return false;
      }
      j = end + 1;
    }
    return i == n && j == m + 1;
  }
};
