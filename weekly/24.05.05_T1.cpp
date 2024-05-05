#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_set<char> hash{'a', 'e', 'i', 'o', 'u'};

 public:
  bool isValid(string word) {
    int n = word.length();
    if (n < 3) {
      return false;
    }
    bool contain_meta = false;
    bool contain_other = false;
    for (auto &c : word) {
      if (!isalnum(c)) {
        return false;
      }
      c = tolower(c);
      if (hash.count(c)) {
        contain_meta = true;
      } else if (isalpha(c)) {
        contain_other = true;
      }
    }
    return contain_meta && contain_other;
  }
};
