#include <bits/stdc++.h>
using namespace std;

class Solution {
  bool isUnorderSameWord(const unordered_map<char, int> &target, const unordered_map<char, int> &window) {
    for (const auto &[key, value] : target) {
      const auto iter = window.find(key);
      if (iter == window.cend()) {
        return false;
      }
      if (iter->second != value) {
        return false;
      }
    }
    return true;
  }

 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;

    unordered_map<char, int> target;
    for (const auto &c : p) {
      target[c]++;
    }

    int n = s.length();

    unordered_map<char, int> window;
    int lastIdx = 0;

    for (int i = 0; i < n; ++i) {
      if (target.find(s[i]) == target.end()) {
        lastIdx = i + 1;
        window.clear();
      } else {
        window[s[i]]++;
        if (isUnorderSameWord(target, window)) {
          ans.push_back(lastIdx);
          window[s[lastIdx]]--;
          ++lastIdx;
        } else {
          if (window[s[i]] > target[s[i]]) {
            // move `lastIdx` to make the number of s[i] less than target[s[i]]
            while (s[lastIdx] != s[i]) {
              window[s[lastIdx]]--;
              ++lastIdx;
            }
            window[s[lastIdx]]--;
            ++lastIdx;
          }
        }
      }
    }

    return ans;
  }
};
