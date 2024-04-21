#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool lowerAllBeforeUpper(const string &word, char lower) {
    char upper = lower - 'a' + 'A';
    int first_upper_idx = word.find_first_of(upper);
    int n = word.length();
    for (int i = first_upper_idx; i < n; ++i) {
      if (word[i] == lower) {
        return false;
      }
    }
    return true;
  }

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
        if (lowerAllBeforeUpper(word, i + 'a')) {
          ++count;
        }
      }
    }
    return count;
  }
};
