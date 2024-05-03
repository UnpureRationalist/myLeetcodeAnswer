#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // 如果某个字符串中 至多一个 字母出现 奇数 次，则称其为 最美 字符串。
  // 字符串由前十个小写英文字母组成（'a' 到 'j'）
  long long wonderfulSubstrings(string word) {
    int n = word.length();
    long long ans = 0;
    unordered_map<int, int> state2times;
    state2times[0] = 1;
    for (int i = 0, state = 0; i < n; ++i) {
      char c = word[i];
      state ^= (1 << (c - 'a'));
      // 计算以 i 结尾的完美字符串数量
      ans += state2times[state];  // 累加上区间中每个字母出现次数都是偶数的个数
      for (int j = 0; j < 10; ++j) {
        ans += state2times[state ^ (1 << j)];  // 枚举出现一次的字母 然后将对应的状态累加
      }
      state2times[state]++;
    }
    return ans;
  }
};
