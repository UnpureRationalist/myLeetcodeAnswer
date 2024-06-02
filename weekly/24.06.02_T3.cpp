#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string clearStars(string s) {
    multimap<pair<char, int>, int> char2idx;
    unordered_set<int> removed_idx;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
      char c = s[i];
      if (c == '*') {
        auto iter = char2idx.begin();
        int idx = iter->second;
        char2idx.erase(iter);
        removed_idx.insert(idx);
      } else {
        char2idx.insert({{c, n - i}, i});
      }
    }
    string ans;
    for (int i = 0; i < n; ++i) {
      if (s[i] != '*' && removed_idx.find(i) == removed_idx.end()) {
        ans.push_back(s[i]);
      }
    }
    return ans;
  }
};
