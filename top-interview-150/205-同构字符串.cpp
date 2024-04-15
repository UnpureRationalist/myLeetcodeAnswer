#include "header.h"

class Solution {
 public:
  // 不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s2t;
    unordered_set<char> targets;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      if (s2t.find(s[i]) == s2t.end()) {
        if (targets.find(t[i]) != targets.end()) {
          return false;
        }
        s2t[s[i]] = t[i];      // 记录映射关系 <s[i], t[i]>
        targets.insert(t[i]);  // 记录 string t 中出现过的字符
      } else {
        if (s2t[s[i]] != t[i]) {
          return false;
        }
      }
    }
    return true;
  }
};
