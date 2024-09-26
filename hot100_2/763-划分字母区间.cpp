#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    int array[26] = {0};
    for (const auto &c : s) {
      array[c - 'a']++;
    }
    int n = s.length();
    vector<int> result;
    int i = 0;
    int lastIdx = -1;
    int tmp[26] = {0};
    while (i < n) {
      int idx = s[i] - 'a';
      tmp[idx]++;
      if (tmp[idx] == array[idx]) {
        bool check = true;
        for (int j = 0; j < 26; ++j) {
          if (tmp[j] != 0 && tmp[j] != array[j]) {
            check = false;
            break;
          }
        }
        if (check) {
          result.push_back(i - lastIdx);
          lastIdx = i;
        }
      }
      ++i;
    }
    return result;
  }
};

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    int n = s.length();
    int char2lastidx[26];
    for (int i = 0; i < n; ++i) {
      char2lastidx[s[i] - 'a'] = i;
    }
    vector<int> result;
    int max_idx = 0;
    int last_idx = -1;
    for (int i = 0; i < n; ++i) {
      max_idx = max(max_idx, char2lastidx[s[i] - 'a']);
      if (i == max_idx) {
        result.push_back(i - last_idx);
        last_idx = i;
      }
    }
    return result;
  }
};
