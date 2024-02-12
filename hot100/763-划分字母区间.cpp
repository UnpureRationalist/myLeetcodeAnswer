#include <algorithm>
#include <climits>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    int n = s.length();
    unordered_map<char, int> char2lastidx;
    for (int i = 0; i < n; ++i) {
      char2lastidx[s[i]] = i;
    }
    vector<int> result;
    int max_idx = 0;
    int last_idx = -1;
    for (int i = 0; i < n; ++i) {
      max_idx = max(max_idx, char2lastidx[s[i]]);
      if (i == max_idx) {
        result.push_back(i - last_idx);
        last_idx = i;
      }
    }
    return result;
  }
};
