#include "header.h"

class Solution {
  int differLen(const string &s1, const string &s2) {
    int n = s1.length();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += s1[i] != s2[i];
    }
    return ans;
  }

 public:
  int minMutation(string startGene, string endGene, vector<string> &bank) {
    if (startGene == endGene) {
      return 0;
    }
    queue<string> q;
    q.push(startGene);
    int n = bank.size();
    vector<char> visited(n, false);
    int ans = 0;
    while (!q.empty()) {
      int size = q.size();
      ++ans;
      while (size--) {
        string cur = q.front();
        q.pop();
        for (int i = 0; i < n; ++i) {
          if (!visited[i] && differLen(cur, bank[i]) == 1) {
            if (bank[i] == endGene) {
              return ans;
            }
            visited[i] = true;
            q.push(bank[i]);
          }
        }
      }
    }
    return -1;
  }
};

class Solution {
 public:
  int minMutation(string start, string end, vector<string> &bank) {
    unordered_set<string> cnt;
    unordered_set<string> visited;
    char keys[4] = {'A', 'C', 'G', 'T'};
    for (auto &w : bank) {
      cnt.emplace(w);
    }
    if (start == end) {
      return 0;
    }
    if (!cnt.count(end)) {
      return -1;
    }
    queue<string> qu;
    qu.emplace(start);
    visited.emplace(start);
    int step = 1;
    while (!qu.empty()) {
      int sz = qu.size();
      for (int i = 0; i < sz; i++) {
        string curr = qu.front();
        qu.pop();
        for (int j = 0; j < 8; j++) {
          for (int k = 0; k < 4; k++) {
            if (keys[k] != curr[j]) {
              string next = curr;
              next[j] = keys[k];
              if (!visited.count(next) && cnt.count(next)) {
                if (next == end) {
                  return step;
                }
                qu.emplace(next);
                visited.emplace(next);
              }
            }
          }
        }
      }
      step++;
    }
    return -1;
  }
};
