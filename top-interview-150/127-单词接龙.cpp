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
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    if (beginWord == endWord) {
      return 1;
    }
    queue<string> q;
    q.push(beginWord);
    int n = wordList.size();
    vector<char> visited(n, false);
    int ans = 1;
    while (!q.empty()) {
      int size = q.size();
      ++ans;
      while (size--) {
        string cur = q.front();
        q.pop();
        for (int i = 0; i < n; ++i) {
          if (!visited[i] && differLen(cur, wordList[i]) == 1) {
            if (wordList[i] == endWord) {
              return ans;
            }
            visited[i] = true;
            q.push(wordList[i]);
          }
        }
      }
    }
    return 0;
  }
};
