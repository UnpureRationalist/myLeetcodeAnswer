#include <algorithm>
#include <climits>
#include <cmath>
#include <ctime>
#include <iostream>
#include <memory>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findSubstring(string &s, vector<string> &words) {
    vector<int> res;
    int m = words.size(), n = words[0].size(), ls = s.size();
    for (int i = 0; i < n && i + m * n <= ls; ++i) {
      unordered_map<string, int> differ;
      for (int j = 0; j < m; ++j) {
        ++differ[s.substr(i + j * n, n)];
      }
      for (string &word : words) {
        if (--differ[word] == 0) {
          differ.erase(word);
        }
      }
      for (int start = i; start < ls - m * n + 1; start += n) {
        if (start != i) {
          string word = s.substr(start + (m - 1) * n, n);
          if (++differ[word] == 0) {
            differ.erase(word);
          }
          word = s.substr(start - n, n);
          if (--differ[word] == 0) {
            differ.erase(word);
          }
        }
        if (differ.empty()) {
          res.emplace_back(start);
        }
      }
    }
    return res;
  }
};
