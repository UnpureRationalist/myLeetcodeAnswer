#include <bits/stdc++.h>
using namespace std;

class Solution {
  using A = array<int, 26>;
  static constexpr A A0{};
  vector<A> tr;
  void insert(const string &word) {
    int pos = 0;
    for (char c : word) {
      c -= 'a';
      if (tr[pos][c] == 0) {
        tr[pos][c] = tr.size();
        tr.push_back(A0);
      }
      pos = tr[pos][c];
    }
  }

 public:
  int minValidStrings(vector<string> &words, string target) {
    tr.resize(1);
    for (auto &i : words) {
      insert(i);
    }

    int len = target.size();
    vector<int> dp(len + 1, 10000000);
    dp[0] = 0;
    int c, p;
    for (int i = 0; i < len; i++) {
      p = 0;
      for (int j = i; j < len; j++) {
        c = target[j] - 'a';
        if (tr[p][c] == 0) {
          break;
        }
        p = tr[p][c];
        dp[j + 1] = min(dp[j + 1], dp[i] + 1);
      }
    }
    return dp.back() > 10000 ? -1 : dp.back();
  }
};
