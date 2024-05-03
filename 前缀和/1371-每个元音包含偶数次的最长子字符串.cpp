#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_map<char, int> char2num{{'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};

 public:
  int findTheLongestSubstring(string s) {
    int n = s.length();
    int ans = 0;
    unordered_map<int, int> state2idx;  // 记录每个状态出现的第一个位置
    state2idx[0] = -1;                  // 初始化
    for (int i = 0, state = 0; i < n; ++i) {
      char c = s[i];
      if (char2num.count(c)) {  // 只有元音字母才会引起状态变化
        state ^= char2num[c];
      }
      if (state2idx.count(state)) {
        ans = max(ans, i - state2idx[state]);  // 如果当前状态已经出现过，更新长度
      } else {
        state2idx[state] = i;  // 否则记录第一次状态出现的下标
      }
    }
    return ans;
  }
};
