#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    int n = s.length();
    unordered_map<char, int> char2idx;

    int beginIdx = 0;

    for (int i = 0; i < n; ++i) {
      if (char2idx.find(s[i]) != char2idx.end()) {
        while (char2idx.find(s[i]) != char2idx.end()) {
          char2idx.erase(s[beginIdx]);
          beginIdx++;
        }
      }
      char2idx.emplace(s[i], i);
      ans = max(ans, static_cast<int>(char2idx.size()));
    }

    return ans;
  }
};
