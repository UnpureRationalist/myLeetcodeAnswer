#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numberOfSpecialChars(string word) {
    int count = 0;
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);
    for (auto &c : word) {
      if (isupper(c)) {
        upper[c - 'A']++;
      } else {
        lower[c - 'a']++;
      }
    }
    for (int i = 0; i < 26; ++i) {
      if (lower[i] && upper[i]) {
        ++count;
      }
    }
    return count;
  }
};