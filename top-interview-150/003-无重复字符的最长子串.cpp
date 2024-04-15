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
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int ans = 0;
    int begin_idx = 0;  // 无重复字符字串的起点下标
    unordered_map<char, int> c2idx;
    int i = 0;  // [begin_idx, i) 即为无重复字符字串
    for (; i < n; ++i) {
      char c = s[i];
      if (c2idx.find(c) != c2idx.end()) {  // 若当前字符已出现过
        ans = max(ans, i - begin_idx);
        begin_idx = max(begin_idx, c2idx[c] + 1);  // 更新字串起点下标
      }
      c2idx[c] = i;
    }
    return max(ans, i - begin_idx);
  }
};

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    // 哈希集合，记录每个字符是否出现过
    unordered_set<char> occ;
    int n = s.size();
    // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
    int rk = -1, ans = 0;
    // 枚举左指针的位置，初始值隐性地表示为 -1
    for (int i = 0; i < n; ++i) {
      if (i != 0) {
        // 左指针向右移动一格，移除一个字符
        occ.erase(s[i - 1]);
      }
      while (rk + 1 < n && !occ.count(s[rk + 1])) {
        // 不断地移动右指针
        occ.insert(s[rk + 1]);
        ++rk;
      }
      // 第 i 到 rk 个字符是一个极长的无重复字符子串
      ans = max(ans, rk - i + 1);
    }
    return ans;
  }
};
