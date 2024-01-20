#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int result = 0;
    unordered_set<char> hash;
    int left = 0;
    int right = left + 1;
    int n = s.length();
    while (left < n) {
      hash.insert(s[left]);

      right = max(right, left + 1);

      while (right < n && hash.find(s[right]) == hash.end()) {
        hash.insert(s[right]);
        ++right;
      }

      result = max(result, right - left);
      hash.erase(s[left]);
      ++left;
    }
    return result;
  }
};

class Solution2 {
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

class Solution3 {
 public:
  int lengthOfLongestSubstring(string s) {
    // 哈希表记录元素最后出现的位置
    unordered_map<char, int> hash;
    int ans = 0, left = 0;
    int i;
    for (i = 0; i < s.length(); ++i) {
      char cur = s[i];
      if (hash.count(cur)) {
        ans = max(ans, i - left);
        left = max(left, hash[cur] + 1);
      }
      hash[cur] = i;
    }
    return max(ans, i - left);
  }
};
