#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> result;
    unordered_map<string, int> st;
    int i = 0;
    for (const auto &str : strs) {
      string tmp = str;
      sort(tmp.begin(), tmp.end());
      const auto iter = st.find(tmp);
      int idx = -1;
      if (iter == st.end()) {
        st.emplace(tmp, result.size());
        result.emplace_back();
        idx = st.size() - 1;
      } else {
        idx = iter->second;
      }
      result[idx].emplace_back(str);
      ++i;
    }
    return result;
  }
};
