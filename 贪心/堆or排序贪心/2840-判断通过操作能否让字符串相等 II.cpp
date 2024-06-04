#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_map<int, string> getModKMap(int n, int k, const string &s) {
    unordered_map<int, string> ans;
    for (int i = 0; i < n; ++i) {
      ans[i % k].push_back(s[i]);
    }
    return ans;
  }

  bool check(int n, int k, string &s, string &t) {
    auto smp = getModKMap(n, k, s);
    auto tmp = getModKMap(n, k, t);
    for (int i = 0; i < k; ++i) {
      sort(smp[i].begin(), smp[i].end());
      sort(tmp[i].begin(), tmp[i].end());
      if (smp[i] != tmp[i]) {
        return false;
      }
    }
    return true;
  }

 public:
  bool checkStrings(string s1, string s2) {
    int n = s1.length();
    return check(n, 2, s1, s2);
  }
};

class Solution {
 public:
  bool checkStrings(string s1, string s2) {
    int cnt1[2][26]{}, cnt2[2][26]{};
    for (int i = 0; i < s1.length(); i++) {
      cnt1[i % 2][s1[i] - 'a']++;
      cnt2[i % 2][s2[i] - 'a']++;
    }
    return memcmp(cnt1, cnt2, sizeof(cnt1)) == 0;
  }
};
